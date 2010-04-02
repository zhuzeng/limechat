#import <Cocoa/Cocoa.h>
#import "TCPClient.h"
#import "Timer.h"


@interface IRCConnection : NSObject
{
	id delegate;
	
	NSString* host;
	int port;
	BOOL useSSL;
	
	BOOL useSystemSocks;
	BOOL useSocks;
	int socksVersion;
	NSString* proxyHost;
	int proxyPort;
	NSString* proxyUser;
	NSString* proxyPassword;
	
	TCPClient* conn;
	NSMutableArray* sendQueue;
	Timer* timer;
	BOOL sending;
	int penalty;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, retain) NSString* host;
@property (nonatomic, assign) int port;
@property (nonatomic, assign) BOOL useSSL;

@property (nonatomic, assign) BOOL useSystemSocks;
@property (nonatomic, assign) BOOL useSocks;
@property (nonatomic, assign) int socksVersion;
@property (nonatomic, retain) NSString* proxyHost;
@property (nonatomic, assign) int proxyPort;
@property (nonatomic, retain) NSString* proxyUser;
@property (nonatomic, retain) NSString* proxyPassword;

@property (nonatomic, readonly) BOOL active;
@property (nonatomic, readonly) BOOL connecting;
@property (nonatomic, readonly) BOOL connected;
@property (nonatomic, readonly) BOOL readyToSend;

- (void)open;
- (void)close;

@end


@interface NSObject (IRCConnectionDelegate)
- (void)ircConnectionDidConnect:(IRCConnection*)sender;
- (void)ircConnectionDidDisconnect:(IRCConnection*)sender;
- (void)ircConnectionDidError:(IRCConnection*)sender;
- (void)ircConnectionDidReceive:(NSData*)data;
- (void)ircConnectionWillSend:(id)msg;
@end



$NetBSD: patch-src_stun.c,v 1.3 2012/06/28 04:50:12 dholland Exp $

- Fix a wrong memset call.
- Always seed with /dev/random on NetBSD instead of relying on a
configure test.
- Fix build with gcc 4.6

--- src/stun.c.orig	2009-06-16 10:49:48.000000000 +0000
+++ src/stun.c
@@ -398,7 +398,7 @@ stunParseMessage( char* buf, unsigned in
    char* body;
    unsigned int size;
 	 ortp_debug("stun: Received stun message: %i bytes\n", bufLen);
-   memset(msg, 0, sizeof(msg));
+   memset(msg, 0, sizeof(*msg));
 	
    if (sizeof(StunMsgHdr) > bufLen)
    {
@@ -1185,7 +1185,7 @@ stunRand(void)
 	read(fd,&tick,sizeof(tick));
 	closesocket(fd);
       }
-#elif defined(__linux) || defined(HAVE_DEV_RANDOM) 
+#elif defined(__linux) || defined(__NetBSD__) || defined(HAVE_DEV_RANDOM) 
       {
  	fd_set fdSet;
 	int maxFd=0;
@@ -1984,7 +1984,6 @@ stunSendTest( Socket myFd, StunAddress4 
 	
    bool_t changePort=FALSE;
    bool_t changeIP=FALSE;
-   bool_t discard=FALSE;
 
    StunMessage req;
    char buf[STUN_MAX_MESSAGE_SIZE];
@@ -2007,7 +2006,6 @@ stunSendTest( Socket myFd, StunAddress4 
          changeIP=TRUE;
          break;
       case 5:
-         discard=TRUE;
          break;
       default:
          ortp_error("stun: Test %i is unkown\n", testNum);
@@ -2153,7 +2151,7 @@ stunNatType( StunAddress4 *dest, 
 
    bool_t respTestI=FALSE;
    bool_t isNat=TRUE;
-   StunAddress4 testIchangedAddr;
+   /* StunAddress4 testIchangedAddr; */
    StunAddress4 testImappedAddr;
    bool_t respTestI2=FALSE; 
    bool_t mappedIpSame = TRUE;
@@ -2336,8 +2334,8 @@ stunNatType( StunAddress4 *dest, 
                         if ( !respTestI )
                         {
 									
-                           testIchangedAddr.addr = resp.changedAddress.ipv4.addr;
-                           testIchangedAddr.port = resp.changedAddress.ipv4.port;
+                           /* testIchangedAddr.addr = resp.changedAddress.ipv4.addr; */
+                           /* testIchangedAddr.port = resp.changedAddress.ipv4.port; */
                            testImappedAddr.addr = resp.mappedAddress.ipv4.addr;
                            testImappedAddr.port = resp.mappedAddress.ipv4.port;
 									

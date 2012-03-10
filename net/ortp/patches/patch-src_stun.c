$NetBSD: patch-src_stun.c,v 1.1 2012/03/10 22:07:25 markd Exp $

Fix build with gcc 4.6

--- src/stun.c.orig	2012-02-13 09:03:33.121945876 +0000
+++ src/stun.c
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
 									

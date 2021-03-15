$NetBSD: patch-src_PerfSocket.cpp,v 1.2 2021/03/15 17:00:06 gdt Exp $

Fix bug where setsockopt was used with int when it is defined to use
unsigned char.  This should avoid bugs on BE machines.

https://sourceforge.net/p/iperf2/tickets/104/

--- src/PerfSocket.cpp.orig	2019-01-22 20:31:18.000000000 +0000
+++ src/PerfSocket.cpp
@@ -120,8 +120,9 @@ void SetSocketOptions( thread_Settings *
 	    // set TTL
 	    int val = inSettings->mTTL;
 	    if ( !isIPV6(inSettings) ) {
+ 		u_char uval = val;
 		int rc = setsockopt( inSettings->mSock, IPPROTO_IP, IP_MULTICAST_TTL,
-				     (char*) &val, (Socklen_t) sizeof(val));
+				     (char*) &uval, (Socklen_t) sizeof(val));
 
 		WARN_errno( rc == SOCKET_ERROR, "multicast v4 ttl" );
 	    } else

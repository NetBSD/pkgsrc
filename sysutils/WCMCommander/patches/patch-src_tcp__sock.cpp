$NetBSD: patch-src_tcp__sock.cpp,v 1.2 2015/09/08 13:21:46 wiz Exp $

NetBSD does not have gethostbyname_r() either.
https://github.com/corporateshark/WCMCommander/pull/509

--- src/tcp_sock.cpp.orig	2015-04-24 21:50:22.000000000 +0000
+++ src/tcp_sock.cpp
@@ -64,7 +64,7 @@ bool GetHostIp( const char* utf8, unsign
 
 	struct hostent* ret;
 
-#if defined( __APPLE__ ) || defined(__OpenBSD__)
+#if defined( __APPLE__ ) || defined(__OpenBSD__) || defined(__NetBSD__)
 	ret = gethostbyname( utf8 );
 
 	if ( !ret )

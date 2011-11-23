$NetBSD: patch-src_dns.cpp,v 1.1 2011/11/23 19:37:56 marino Exp $

--- src/dns.cpp.orig	2009-10-12 16:41:19.000000000 +0000
+++ src/dns.cpp
@@ -23,6 +23,10 @@
 
 #include <stdio.h>
 
+#if defined (__DragonFly__)
+#include <string.h>
+#endif
+
 #if ( !defined( _WIN32 ) && !defined( _WIN32_WCE ) ) || defined( __SYMBIAN32__ )
 # include <netinet/in.h>
 # include <arpa/nameser.h>

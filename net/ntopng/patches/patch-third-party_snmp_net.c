$NetBSD: patch-third-party_snmp_net.c,v 1.1 2017/06/15 14:54:45 fhajny Exp $

SunOS doesn't have gethostbyname2.

--- third-party/snmp/net.c.orig	2016-06-27 19:31:19.000000000 +0000
+++ third-party/snmp/net.c
@@ -15,7 +15,7 @@
 #define __USE_GNU
 #endif
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__sun)
 #define gethostbyname2(a, b) gethostbyname(a)
 #else
 #include <unistd.h>

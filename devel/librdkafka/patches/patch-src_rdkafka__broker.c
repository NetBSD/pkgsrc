$NetBSD: patch-src_rdkafka__broker.c,v 1.1 2017/04/20 08:01:19 fhajny Exp $

XPG6 is needed.

--- src/rdkafka_broker.c.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/rdkafka_broker.c
@@ -31,7 +31,7 @@
 #ifndef _MSC_VER
 #define _GNU_SOURCE
 #ifndef _AIX    /* AIX defines this and the value needs to be set correctly */
-#define _XOPEN_SOURCE
+#define _XOPEN_SOURCE 600
 #endif
 #include <signal.h>
 #endif

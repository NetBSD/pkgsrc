$NetBSD: patch-src_rdkafka__broker.c,v 1.2 2017/04/24 12:20:37 fhajny Exp $

Do not mess with _XOPEN_SOURCE here, it's needed generally and elsewhere.

--- src/rdkafka_broker.c.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/rdkafka_broker.c
@@ -30,9 +30,6 @@
 
 #ifndef _MSC_VER
 #define _GNU_SOURCE
-#ifndef _AIX    /* AIX defines this and the value needs to be set correctly */
-#define _XOPEN_SOURCE
-#endif
 #include <signal.h>
 #endif
 

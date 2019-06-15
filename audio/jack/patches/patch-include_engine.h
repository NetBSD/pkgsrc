$NetBSD: patch-include_engine.h,v 1.1 2019/06/15 08:21:33 adam Exp $

Allow overriding the watchdog timeout.

--- include/engine.h.orig	2016-03-02 22:50:14.000000000 +0000
+++ include/engine.h
@@ -56,8 +56,12 @@ typedef struct _jack_reserved_name {
 	char name[JACK_CLIENT_NAME_SIZE];
 } jack_reserved_name_t;
 
+#ifndef JACKD_WATCHDOG_TIMEOUT
 #define JACKD_WATCHDOG_TIMEOUT 10000
+#endif
+#ifndef JACKD_CLIENT_EVENT_TIMEOUT
 #define JACKD_CLIENT_EVENT_TIMEOUT 2000
+#endif
 
 /* The main engine structure in local memory. */
 struct _jack_engine {

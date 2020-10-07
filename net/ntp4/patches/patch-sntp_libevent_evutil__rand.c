$NetBSD: patch-sntp_libevent_evutil__rand.c,v 1.1 2020/10/07 10:15:02 jperkin Exp $

Don't assume arc4random_addrandom() is available.

--- sntp/libevent/evutil_rand.c.orig	2014-03-04 08:33:31.000000000 +0000
+++ sntp/libevent/evutil_rand.c
@@ -195,8 +195,10 @@ evutil_secure_rng_get_bytes(void *buf, s
 void
 evutil_secure_rng_add_bytes(const char *buf, size_t n)
 {
+#ifndef __sun
 	arc4random_addrandom((unsigned char*)buf,
 	    n>(size_t)INT_MAX ? INT_MAX : (int)n);
+#endif
 }
 
 void

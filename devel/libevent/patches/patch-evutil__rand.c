$NetBSD: patch-evutil__rand.c,v 1.3 2017/03/08 13:37:55 jperkin Exp $

Native illumos arc4random(3C) imported the latest OpenBSD API which
does not have arc4random_addrandom().

--- evutil_rand.c.orig	2013-11-01 18:18:57.000000000 +0000
+++ evutil_rand.c
@@ -195,7 +195,9 @@ evutil_secure_rng_get_bytes(void *buf, s
 void
 evutil_secure_rng_add_bytes(const char *buf, size_t n)
 {
+#if !(defined(EVENT__HAVE_ARC4RANDOM) && defined(__sun))
 	arc4random_addrandom((unsigned char*)buf,
 	    n>(size_t)INT_MAX ? INT_MAX : (int)n);
+#endif
 }
 

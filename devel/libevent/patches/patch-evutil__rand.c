$NetBSD: patch-evutil__rand.c,v 1.4 2017/09/22 02:58:50 maya Exp $

Native illumos arc4random(3C) imported the latest OpenBSD API which
does not have arc4random_addrandom().

--- evutil_rand.c.orig	2016-10-04 19:55:31.000000000 +0000
+++ evutil_rand.c
@@ -195,8 +195,10 @@ evutil_secure_rng_get_bytes(void *buf, s
 void
 evutil_secure_rng_add_bytes(const char *buf, size_t n)
 {
+#if !(defined(EVENT__HAVE_ARC4RANDOM) && defined(__sun))
 	arc4random_addrandom((unsigned char*)buf,
 	    n>(size_t)INT_MAX ? INT_MAX : (int)n);
+#endif
 }
 
 void

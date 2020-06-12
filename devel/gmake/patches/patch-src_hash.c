$NetBSD: patch-src_hash.c,v 1.1 2020/06/12 14:48:38 sevan Exp $

PCC says: hash.c:326: error: Constant "4294967295" is out of range

--- work/make-4.3/src/hash.c.orig	2020-06-12 14:40:24.838680043 +0000
+++ work/make-4.3/src/hash.c
@@ -321,7 +321,7 @@ round_up_2 (unsigned long n)
   n |= (n >> 8);
   n |= (n >> 16);
 
-#if !defined(HAVE_LIMITS_H) || ULONG_MAX > 4294967295
+#if !defined(HAVE_LIMITS_H) || ULONG_MAX > 4294967295ul
   /* We only need this on systems where unsigned long is >32 bits.  */
   n |= (n >> 32);
 #endif

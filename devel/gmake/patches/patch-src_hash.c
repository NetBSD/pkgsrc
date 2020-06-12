$NetBSD: patch-src_hash.c,v 1.3 2020/06/12 23:50:16 sevan Exp $

PCC says: hash.c:326: error: Constant "4294967295" is out of range

--- hash.c.orig	2006-02-11 21:00:39.000000000 +0100
+++ hash.c
@@ -323,7 +323,7 @@ round_up_2 (unsigned long n)
   n |= (n >> 8);
   n |= (n >> 16);
 
-#if !defined(HAVE_LIMITS_H) || ULONG_MAX > 4294967295
+#if !defined(HAVE_LIMITS_H) || ULONG_MAX > 4294967295ul
   /* We only need this on systems where unsigned long is >32 bits.  */
   n |= (n >> 32);
 #endif

$NetBSD: patch-tryulong32.c,v 1.1 2017/07/27 02:20:30 schmonz Exp $

Support arm.

--- tryulong32.c.orig	2000-02-29 04:10:12.000000000 +0000
+++ tryulong32.c
@@ -1,5 +1,8 @@
 void main()
 {
+#ifdef __arm__
+ _exit(0);
+#else
  unsigned long u;
  u = 1;
  u += u; u += u; u += u; u += u; u += u; u += u; u += u; u += u;
@@ -8,4 +11,5 @@ void main()
  u += u; u += u; u += u; u += u; u += u; u += u; u += u; u += u;
  if (!u) _exit(0);
  _exit(1);
+#endif
 }

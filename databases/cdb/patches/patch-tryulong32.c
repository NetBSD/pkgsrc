$NetBSD: patch-tryulong32.c,v 1.1 2020/06/30 13:29:35 schmonz Exp $

Work around very slow compile on arm/gcc 2.95.3.

--- tryulong32.c.orig	2000-02-19 20:42:05.000000000 +0000
+++ tryulong32.c
@@ -1,5 +1,8 @@
 void main()
 {
+#ifdef __arm__
+  _exit(0);
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

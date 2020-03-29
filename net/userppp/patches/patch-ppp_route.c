$NetBSD: patch-ppp_route.c,v 1.1 2020/03/29 06:01:31 rillig Exp $

Fix the build on NetBSD >= 8.

https://github.com/NetBSD/src/commit/4b9481766e9fbdb9d5a37313b91bba3180607b1a

--- ppp/route.c.orig	2000-11-07 05:45:45.000000000 +0000
+++ ppp/route.c
@@ -223,9 +223,17 @@ static struct bits {
   { RTF_DYNAMIC, 'D' },
   { RTF_MODIFIED, 'M' },
   { RTF_DONE, 'd' },
+#ifdef RTF_CLONING
   { RTF_CLONING, 'C' },
+#else
+  { RTF_CONNECTED, 'C' }, // Since NetBSD 8.0
+#endif
+#ifdef RTF_XRESOLVE
   { RTF_XRESOLVE, 'X' },
+#endif
+#ifdef RTF_LLINFO
   { RTF_LLINFO, 'L' },
+#endif
   { RTF_STATIC, 'S' },
   { RTF_PROTO1, '1' },
   { RTF_PROTO2, '2' },

$NetBSD: patch-src_foreign_vsa.c,v 1.1 2023/04/04 21:51:07 tpaul Exp $

Avoid "sun" conflict.

--- src/foreign/vsa.c.orig	2021-11-29 12:09:28.000000000 +0000
+++ src/foreign/vsa.c
@@ -43,6 +43,10 @@
 #include "vsa.h"
 #include "miniobj.h"
 
+#ifdef __sun
+#undef sun
+#endif
+
 /*
  * Struct sockaddr{|_in|_in6|_storage} is absolutely the worst data
  * structure I have ever seen gold-plated in international standards.

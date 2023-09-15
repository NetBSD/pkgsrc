$NetBSD: patch-src-b-em.h,v 1.3 2023/09/15 16:13:27 reinoud Exp $

Define the missing macro's

--- src/b-em.h.orig	2023-09-10 00:50:28.000000000 +0000
+++ src/b-em.h
@@ -41,6 +41,9 @@
 #ifdef __APPLE__
 #define fread_unlocked fread
 #define fwrite_unlocked fwrite
+#else
+#define fread_unlocked fread
+#define fwrite_unlocked fwrite
 #endif
 #endif
 

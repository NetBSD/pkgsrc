$NetBSD: patch-include_PGFplatform.h,v 1.1 2023/09/29 18:29:29 nros Exp $

* Add DragonflyBSD and Haiku support

--- include/PGFplatform.h.orig	2023-09-29 18:29:20.586933088 +0000
+++ include/PGFplatform.h
@@ -336,7 +336,7 @@ inline OSError SetFPos(HANDLE hFile, int
 //-------------------------------------------------------------------------------
 // *BSD
 //-------------------------------------------------------------------------------
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__HAIKU__)
 #ifndef __POSIX__ 
 #define __POSIX__ 
 #endif 

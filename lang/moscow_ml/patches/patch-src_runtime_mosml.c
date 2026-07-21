$NetBSD: patch-src_runtime_mosml.c,v 1.1 2026/07/21 14:07:29 ryoon Exp $

--- src/runtime/mosml.c.orig	2026-06-03 13:01:26.123401038 +0000
+++ src/runtime/mosml.c
@@ -972,7 +972,7 @@ value sml_access(value path, value permarg)          /
 }
 
 #ifndef HAS_STRERROR
-#if (!defined(__FreeBSD__) && !defined(linux) && !defined(__APPLE__))
+#if (!defined(__FreeBSD__) && !defined(linux) && !defined(__APPLE__) && !defined(__NetBSD__))
   extern int sys_nerr;
   extern char * sys_errlist [];
 #endif   

$NetBSD: patch-src_System_config.h.cmake,v 1.1 2026/11/09 10:45:17 nros Exp $

Make sure snprintf is used on systems that have it

--- src/System/config.h.cmake.orig	2026-10-18 10:02:32.643653469 +0000
+++ src/System/config.h.cmake
@@ -50,6 +50,8 @@
 /* Define to 1 if you have the <pty.h> header file. */
 #cmakedefine HAVE_PTY_H 1
 
+#cmakedefine HAVE_SNPRINTF 1
+
 /* Define to 1 if you have the <stdint.h> header file. */
 #cmakedefine HAVE_STDINT_H 1
 

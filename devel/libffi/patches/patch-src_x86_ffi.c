$NetBSD: patch-src_x86_ffi.c,v 1.1 2013/07/26 13:12:25 ryoon Exp $

Fix build on Cygwin64. From Cygwin64 1.7.22's 3.0.12-cygwin.patch.

--- src/x86/ffi.c.orig	2013-03-16 11:25:04.000000000 +0000
+++ src/x86/ffi.c
@@ -28,7 +28,7 @@
    DEALINGS IN THE SOFTWARE.
    ----------------------------------------------------------------------- */
 
-#if !defined(__x86_64__) || defined(_WIN64)
+#if !defined(__x86_64__) || defined(_WIN64) || defined(__CYGWIN__)
 
 #ifdef _WIN64
 #include <windows.h>

$NetBSD: patch-bundles_pyml_pyml-current_pyml__arch.ml.c,v 1.1 2026/01/25 23:50:17 wiz Exp $

NetBSD doesn't define 'unix'

--- bundles/pyml/pyml-current/pyml_arch.ml.c.orig	2026-01-25 23:45:56.634799893 +0000
+++ bundles/pyml/pyml-current/pyml_arch.ml.c
@@ -3,7 +3,7 @@
 #elif defined(WIN32) || defined(_WIN32)
   #define PLATFORM_NAME Windows
   #define WIN_HANDLE_FD
-#elif unix
+#elif defined(unix) || defined(__NetBSD__)
   #define PLATFORM_NAME Unix
 #else
   #error "Unknown platform"

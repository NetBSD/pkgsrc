$NetBSD: patch-src_cabocha.h,v 1.1 2012/04/22 20:31:30 joerg Exp $

Do not include C++ headers in a extern "C" block.

--- src/cabocha.h.orig	2012-04-20 16:25:56.000000000 +0000
+++ src/cabocha.h
@@ -24,12 +24,6 @@
 #ifndef _CABOCHA_CABOCHA_H
 #define _CABOCHA_CABOCHA_H
 
-#ifdef __cplusplus
-
-/* for C */
-extern "C" {
-#endif
-
 #ifdef _WIN32
 #  ifdef DLL_EXPORT
 #    define CABOCHA_DLL_EXTERN    __declspec(dllexport)
@@ -50,6 +44,12 @@ extern "C" {
 #include <string.h>
 #endif
 
+#ifdef __cplusplus
+
+/* for C */
+extern "C" {
+#endif
+
   typedef struct _cabocha_t cabocha_t;
 
   typedef void cabocha_tree_t;

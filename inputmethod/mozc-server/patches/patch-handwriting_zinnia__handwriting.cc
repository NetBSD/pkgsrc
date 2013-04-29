$NetBSD: patch-handwriting_zinnia__handwriting.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

* Not confirmed yet.

--- handwriting/zinnia_handwriting.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ handwriting/zinnia_handwriting.cc
@@ -52,7 +52,7 @@ string GetModelFileName() {
 #elif defined(USE_LIBZINNIA)
   // On Linux, use the model for tegaki-zinnia.
   const char kModelFile[] =
-      "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+      "@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model";
   return kModelFile;
 #else
   const char kModelFile[] = "handwriting-ja.model";

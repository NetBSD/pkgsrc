$NetBSD: patch-handwriting_zinnia__handwriting.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

* Not confirmed yet.

--- handwriting/zinnia_handwriting.cc.orig	2013-07-17 02:38:04.000000000 +0000
+++ handwriting/zinnia_handwriting.cc
@@ -57,7 +57,7 @@ string ZinniaHandwriting::GetModelFileNa
   const char kModelFile[] = MOZC_ZINNIA_MODEL_FILE;
 #else
   const char kModelFile[] =
-      "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+      "@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model";
 #endif  // MOZC_ZINNIA_MODEL_FILE
   return kModelFile;
 #else

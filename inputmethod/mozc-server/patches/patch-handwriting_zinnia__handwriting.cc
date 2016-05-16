$NetBSD: patch-handwriting_zinnia__handwriting.cc,v 1.3 2016/05/16 11:51:49 ryoon Exp $

* Not confirmed yet.

--- handwriting/zinnia_handwriting.cc.orig	2016-05-15 08:11:11.000000000 +0000
+++ handwriting/zinnia_handwriting.cc
@@ -59,7 +59,7 @@ string ZinniaHandwriting::GetModelFileNa
   return FileUtil::JoinPath(MacUtil::GetResourcesDirectory(), kModelFile);
 #elif defined(OS_LINUX)
   const char kModelFile[] =
-      "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+      "@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model";
   return kModelFile;
 #else
   const char kModelFile[] = "handwriting-ja.model";

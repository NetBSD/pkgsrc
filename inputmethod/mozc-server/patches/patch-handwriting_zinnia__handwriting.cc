$NetBSD: patch-handwriting_zinnia__handwriting.cc,v 1.4 2017/12/17 14:15:43 tsutsui Exp $

* Not confirmed yet.

--- handwriting/zinnia_handwriting.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ handwriting/zinnia_handwriting.cc
@@ -59,7 +59,7 @@ string ZinniaHandwriting::GetModelFileNa
   const char kModelFile[] = "handwriting-ja.model";
   return FileUtil::JoinPath(MacUtil::GetResourcesDirectory(), kModelFile);
 #else  // OS_LINUX
-  return "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+  return "@PREFIX@/tegaki/models/zinnia/handwriting-ja.model";
 #endif
 #endif  // else defined(MOZC_BUILD)
 }

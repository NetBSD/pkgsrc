$NetBSD: patch-src_imagemgr.h,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Fix build with gcc-4.5.

--- src/imagemgr.h.orig	2004-12-05 03:01:27.000000000 +0000
+++ src/imagemgr.h
@@ -102,7 +102,7 @@ public:
     static void destroy();
 
     ImageInfo *get(const std::string &name);
-    SubImage *ImageMgr::getSubImage(const std::string &name);
+    SubImage *getSubImage(const std::string &name);
     void freeIntroBackgrounds();
     const std::vector<std::string> &getSetNames();
 

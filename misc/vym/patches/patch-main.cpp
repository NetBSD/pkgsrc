$NetBSD: patch-main.cpp,v 1.3 2019/10/30 13:09:38 kamil Exp $

--- main.cpp.orig	2019-05-14 13:33:32.620701292 +0000
+++ main.cpp
@@ -319,7 +319,7 @@ int main(int argc, char* argv[])
             vymInstallDir.setPath(basePath);
             vymBaseDir.setPath(basePath);
 #else
-            vymBaseDir.setPath ("/usr/share/vym");
+            vymBaseDir.setPath ("@PREFIX@/share/vym");
             if (!vymBaseDir.exists())
             {
                 vymBaseDir.setPath ("/usr/local/share/vym");

$NetBSD: patch-lib_usrp_x300_x300__image__loader.cpp,v 1.1 2024/04/25 12:22:39 tnn Exp $

Fix boost fallout
https://github.com/EttusResearch/uhd/commit/ea586168c596d13d05d145832519755794649ba0

--- lib/usrp/x300/x300_image_loader.cpp.orig	2023-11-13 15:22:00.000000000 +0000
+++ lib/usrp/x300/x300_image_loader.cpp
@@ -138,8 +138,8 @@ static void x300_validate_image(x300_ses
             boost::format("Could not find image at path \"%s\".") % session.filepath));
     }
 
-    std::string extension = fs::extension(session.filepath);
-    session.lvbitx        = (extension == ".lvbitx");
+    const std::string extension = fs::path(session.filepath).extension().string();
+    session.lvbitx              = (extension == ".lvbitx");
 
     if (session.lvbitx) {
         extract_from_lvbitx(session);

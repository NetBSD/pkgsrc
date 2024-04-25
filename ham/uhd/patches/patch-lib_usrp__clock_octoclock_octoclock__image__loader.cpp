$NetBSD: patch-lib_usrp__clock_octoclock_octoclock__image__loader.cpp,v 1.1 2024/04/25 12:22:39 tnn Exp $

Fix boost fallout
https://github.com/EttusResearch/uhd/commit/ea586168c596d13d05d145832519755794649ba0

--- lib/usrp_clock/octoclock/octoclock_image_loader.cpp.orig	2023-11-13 15:22:00.000000000 +0000
+++ lib/usrp_clock/octoclock/octoclock_image_loader.cpp
@@ -95,7 +95,7 @@ static void octoclock_validate_firmware_
                                      % session.image_filepath));
     }
 
-    std::string extension = fs::extension(session.image_filepath);
+    const std::string extension = fs::path(session.image_filepath).extension().string();
     if (extension == ".bin") {
         octoclock_read_bin(session);
     } else if (extension == ".hex") {

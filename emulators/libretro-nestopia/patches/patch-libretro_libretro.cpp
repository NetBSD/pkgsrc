$NetBSD: patch-libretro_libretro.cpp,v 1.2 2018/08/11 20:26:12 nia Exp $

retroarch normally expects to find the NstDatabase.xml file in
~/.config/retroarch/bios, but there's no real reason to be editing it.
Rather than have users manually copy the file into place, we install it
system-wide and look for it there instead.

--- libretro/libretro.cpp.orig	2018-06-24 23:26:58.000000000 +0000
+++ libretro/libretro.cpp
@@ -1073,7 +1073,7 @@ bool retro_load_game(const struct retro_
    }
    delete custompalette;
    
-   sprintf(db_path, "%s%cNstDatabase.xml", dir, slash);
+   snprintf(db_path, sizeof(db_path), "%s/share/libretro-nestopia/NstDatabase.xml", PREFIX);
 
    if (log_cb)
       log_cb(RETRO_LOG_INFO, "NstDatabase.xml path: %s\n", db_path);

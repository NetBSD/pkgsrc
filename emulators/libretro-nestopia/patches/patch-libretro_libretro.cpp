$NetBSD: patch-libretro_libretro.cpp,v 1.1 2015/04/10 03:16:18 snj Exp $

retroarch normally expects to find the NstDatabase.xml file in
~/.config/retroarch/bios, but there's no real reason to be editing it.
Rather than have users manually copy the file into place, we install it
system-wide and look for it there instead.

--- libretro/libretro.cpp.orig	2015-03-19 19:54:18.000000000 -0700
+++ libretro/libretro.cpp	2015-03-29 23:31:42.000000000 -0700
@@ -624,7 +624,7 @@ bool retro_load_game(const struct retro_
    if (!environ_cb(RETRO_ENVIRONMENT_GET_OVERSCAN, &use_overscan))
       use_overscan = true;
 
-   snprintf(db_path, sizeof(db_path), "%s%cNstDatabase.xml", dir, slash);
+   snprintf(db_path, sizeof(db_path), "%s/share/libretro-nestopia/NstDatabase.xml", PREFIX);
 
    if (log_cb)
       log_cb(RETRO_LOG_INFO, "NstDatabase.xml path: %s\n", db_path);

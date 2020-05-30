$NetBSD: patch-frontend_drivers_platform__unix.c,v 1.5 2020/05/30 14:26:52 nia Exp $

Allow loading cores and core info from pkgsrc.

--- frontend/drivers/platform_unix.c.orig	2020-05-27 18:11:31.000000000 +0000
+++ frontend/drivers/platform_unix.c
@@ -1708,10 +1708,22 @@ static void frontend_unix_get_env(int *a
    else
       strlcpy(base_path, "retroarch", sizeof(base_path));
 
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE], base_path,
-         "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE]));
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE_INFO], base_path,
-         "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE_INFO]));
+   if (path_is_directory("@PREFIX@/lib/libretro"))
+      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE],
+            "@PREFIX@/lib", "libretro",
+            sizeof(g_defaults.dirs[DEFAULT_DIR_CORE]));
+   else
+      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE], base_path,
+            "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE]));
+
+   if (path_is_directory("@PREFIX@/share/libretro/info"))
+      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE_INFO],
+            "@PREFIX@/share/libretro", "info",
+            sizeof(g_defaults.dirs[DEFAULT_DIR_CORE_INFO]));
+   else
+      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE_INFO], base_path,
+            "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE_INFO]));
+
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_AUTOCONFIG], base_path,
          "autoconfig", sizeof(g_defaults.dirs[DEFAULT_DIR_AUTOCONFIG]));
 

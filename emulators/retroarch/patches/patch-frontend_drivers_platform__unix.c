$NetBSD: patch-frontend_drivers_platform__unix.c,v 1.2 2019/02/06 11:18:44 nia Exp $

Pick up paths from pkgsrc.

--- frontend/drivers/platform_unix.c.orig	2019-02-04 14:54:53.000000000 +0000
+++ frontend/drivers/platform_unix.c
@@ -1852,32 +1852,15 @@ static void frontend_unix_get_env(int *a
    else
       snprintf(base_path, sizeof(base_path), "retroarch");
 
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE], base_path,
-         "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE]));
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE_INFO], base_path,
-         "cores", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE_INFO]));
+   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE], PREFIX,
+         "lib/libretro", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE]));
+   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CORE_INFO], PREFIX,
+         "share/libretro/info", sizeof(g_defaults.dirs[DEFAULT_DIR_CORE_INFO]));
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_AUTOCONFIG], base_path,
          "autoconfig", sizeof(g_defaults.dirs[DEFAULT_DIR_AUTOCONFIG]));
 
-   if (path_is_directory("/usr/local/share/retroarch/assets"))
-      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS],
-            "/usr/local/share/retroarch",
-            "assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
-   else if (path_is_directory("/usr/share/retroarch/assets"))
-      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS],
-            "/usr/share/retroarch",
-            "assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
-   else if (path_is_directory("/usr/local/share/games/retroarch/assets"))
-      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS],
-            "/usr/local/share/games/retroarch",
-            "assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
-   else if (path_is_directory("/usr/share/games/retroarch/assets"))
-      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS],
-            "/usr/share/games/retroarch",
-            "assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
-   else
-      fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS], base_path,
-            "assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
+   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_ASSETS], PREFIX,
+         "share/retroarch/assets", sizeof(g_defaults.dirs[DEFAULT_DIR_ASSETS]));
 
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_MENU_CONFIG], base_path,
          "config", sizeof(g_defaults.dirs[DEFAULT_DIR_MENU_CONFIG]));
@@ -1890,10 +1873,10 @@ static void frontend_unix_get_env(int *a
          "records_config", sizeof(g_defaults.dirs[DEFAULT_DIR_RECORD_CONFIG]));
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_RECORD_OUTPUT], base_path,
          "records", sizeof(g_defaults.dirs[DEFAULT_DIR_RECORD_OUTPUT]));
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CURSOR], base_path,
-         "database/cursors", sizeof(g_defaults.dirs[DEFAULT_DIR_CURSOR]));
-   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_DATABASE], base_path,
-         "database/rdb", sizeof(g_defaults.dirs[DEFAULT_DIR_DATABASE]));
+   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CURSOR], PREFIX,
+         "share/libretro/database/cursors", sizeof(g_defaults.dirs[DEFAULT_DIR_CURSOR]));
+   fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_DATABASE], PREFIX,
+         "share/libretro/database/rdb", sizeof(g_defaults.dirs[DEFAULT_DIR_DATABASE]));
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_SHADER], base_path,
          "shaders", sizeof(g_defaults.dirs[DEFAULT_DIR_SHADER]));
    fill_pathname_join(g_defaults.dirs[DEFAULT_DIR_CHEATS], base_path,

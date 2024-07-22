$NetBSD: patch-gcc_config_xtensa_xtensa-dynconfig.cc,v 1.1 2024/07/22 20:01:50 tnn Exp $

Try full path if dlopen of dynconfig lib fails.
Fails at least on macOS otherwise.

--- gcc/config/xtensa/xtensa-dynconfig.cc.orig	2024-07-22 19:20:13.596989938 +0000
+++ gcc/config/xtensa/xtensa-dynconfig.cc
@@ -134,6 +134,15 @@ const void *xtensa_load_config (const ch
       if (!path)
 	return no_plugin_def;
       handle = dlopen (path, RTLD_LAZY);
+      if (!handle)
+	{
+	  char fullpath[1024];
+	  int ret = snprintf(fullpath, sizeof(fullpath), "%s/%s/%s", "@GNU_CONFIGURE_PREFIX@", "lib", path);
+	  if (ret > 0 && ret < sizeof(fullpath))
+	    {
+	      handle = dlopen (fullpath, RTLD_LAZY);
+	    }
+        }
       free (path);
       if (!handle)
 	{

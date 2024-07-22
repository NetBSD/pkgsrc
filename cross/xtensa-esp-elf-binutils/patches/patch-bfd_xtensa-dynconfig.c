$NetBSD: patch-bfd_xtensa-dynconfig.c,v 1.1 2024/07/22 20:01:50 tnn Exp $

Try full path if dlopen of dynconfig lib fails.
Fails at least on macOS otherwise.

--- bfd/xtensa-dynconfig.c.orig	2024-07-22 19:32:42.008309960 +0000
+++ bfd/xtensa-dynconfig.c
@@ -146,6 +146,15 @@ const void *xtensa_load_config (const ch
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

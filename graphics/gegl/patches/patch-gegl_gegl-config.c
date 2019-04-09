$NetBSD: patch-gegl_gegl-config.c,v 1.1 2019/04/09 13:09:03 ryoon Exp $

--- gegl/gegl-config.c.orig	2019-02-25 19:00:08.000000000 +0000
+++ gegl/gegl-config.c
@@ -244,7 +244,11 @@ gegl_config_class_init (GeglConfigClass 
 
 #else
     mem_total = sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#if defined(_SC_AVPHYS_PAGES)
     mem_available = sysconf (_SC_AVPHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#else
+    mem_available = sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#endif
 #endif
 
     default_tile_cache_size = mem_total;

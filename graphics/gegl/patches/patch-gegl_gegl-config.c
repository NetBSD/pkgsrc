$NetBSD: patch-gegl_gegl-config.c,v 1.2 2019/06/18 14:26:59 ryoon Exp $

--- gegl/gegl-config.c.orig	2019-05-07 20:32:27.000000000 +0000
+++ gegl/gegl-config.c
@@ -280,7 +280,11 @@ gegl_config_class_init (GeglConfigClass 
     }
 #else
     mem_total = sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#if defined(_SC_AVPHYS_PAGES)
     mem_available = sysconf (_SC_AVPHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#else
+    mem_available = sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#endif
 #endif
 
     default_tile_cache_size = mem_total;

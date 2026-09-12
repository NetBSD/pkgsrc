$NetBSD: patch-gegl_gegl-config.c,v 1.4 2026/09/12 21:49:46 wiz Exp $

Support NetBSD<11.

--- gegl/gegl-config.c.orig	2019-10-26 23:01:07.000000000 +0000
+++ gegl/gegl-config.c
@@ -319,7 +319,11 @@ gegl_config_class_init (GeglConfigClass 
     }
 #else
     mem_total = (uint64_t) sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#ifdef _SC_AVPHYS_PAGES
     mem_available = (uint64_t) sysconf (_SC_AVPHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#else
+    mem_available = (uint64_t) sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+#endif
 #endif
 
     default_tile_cache_size = mem_total;

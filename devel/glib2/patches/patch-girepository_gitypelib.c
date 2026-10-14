$NetBSD: patch-girepository_gitypelib.c,v 1.2 2026/10/14 09:34:25 jperkin Exp $

Try to look for introspectable libraries in pkgsrc's ${PREFIX}/lib before
any system default search patchs. Fixes this problem on macOS:

$ python3.13
>>> import gi
>>> from gi.repository import Gtk

GLib-GIRepository-WARNING **: 17:25:55.737: Failed to load shared library 'libpango-1.0.0.dylib' referenced by the typelib: dlopen(libpango-1.0.0.dylib, 0x0009): tried: 'libpango-1.0.0.dylib' (no such file), '/System/Volumes/Preboot/Cryptexes/OSlibpango-1.0.0.dylib' (no such file), '/usr/lib/libpango-1.0.0.dylib' (no such file, not in dyld cache), 'libpango-1.0.0.dylib' (no such file)

--- girepository/gitypelib.c.orig	2026-10-06 15:22:44.000000000 +0000
+++ girepository/gitypelib.c
@@ -2256,6 +2256,12 @@ load_one_shared_library (GITypelib  *typ
           if (m != NULL)
             return m;
         }
+      /* try pkgsrc lib dir */
+      char *pkglibpath = g_build_filename ("@PREFIX@/lib", shlib, NULL);
+      m = g_module_open (pkglibpath, G_MODULE_BIND_LAZY);
+      g_free (pkglibpath);
+      if (m != NULL)
+        return m;
     }
 
   /* Then try loading from standard paths */

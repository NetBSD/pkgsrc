$NetBSD: patch-girepository_gitypelib.c,v 1.1 2022/05/13 12:05:59 tnn Exp $

Try to look for introspectable libraries in pkgsrc's ${PREFIX}/lib before
any system default search patchs. Fixes this problem on macOS:

python3.9
>>> import gi
>>> from gi.repository import Gtk

WARNING **: 13:46:16.161: Failed to load shared library 'libpango-1.0.0.dylib'
referenced by the typelib: dlopen(libpango-1.0.0.dylib, 0x0009): tried:
'libpango-1.0.0.dylib' (no such file),
'/usr/local/lib/libpango-1.0.0.dylib' (no such file),
'/usr/lib/libpango-1.0.0.dylib' (no such file)

--- girepository/gitypelib.c.orig	2021-09-17 16:02:42.000000000 +0000
+++ girepository/gitypelib.c
@@ -2275,6 +2275,12 @@ load_one_shared_library (const char *shl
           if (m != NULL)
             return m;
         }
+      /* try pkgsrc lib dir */
+      char *pkglibpath = g_build_filename ("@PREFIX@/lib", shlib, NULL);
+      m= g_module_open (pkglibpath, G_MODULE_BIND_LAZY);
+      g_free (pkglibpath);
+      if (m != NULL)
+        return m;
     }
 
   /* Then try loading from standard paths */

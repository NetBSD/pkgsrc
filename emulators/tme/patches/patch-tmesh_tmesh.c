$NetBSD: patch-tmesh_tmesh.c,v 1.1 2013/11/02 21:53:36 martin Exp $

Supply a sane default value for LTDL_LIBRARY_PATH.

--- tmesh/tmesh.c.orig	2009-08-30 19:06:38.000000000 +0200
+++ tmesh/tmesh.c	2013-11-02 21:59:21.000000000 +0100
@@ -583,6 +586,12 @@
     }
   }
 
+#ifdef LTDL_LIBRARY_PATH_DEFAULT
+  /* if the user did not provide a library path, put a sane default */
+  if (getenv("LTDL_LIBRARY_PATH") == NULL)
+    setenv("LTDL_LIBRARY_PATH", LTDL_LIBRARY_PATH_DEFAULT, 0);
+#endif
+
   /* initialize libtme: */
   (void) tme_init();
 

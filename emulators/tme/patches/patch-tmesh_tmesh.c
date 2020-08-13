$NetBSD: patch-tmesh_tmesh.c,v 1.2 2020/08/13 05:59:52 tsutsui Exp $

Supply a sane default value for LTDL_LIBRARY_PATH.

--- tmesh/tmesh.c.orig	2009-08-30 17:06:38.000000000 +0000
+++ tmesh/tmesh.c
@@ -583,6 +583,12 @@ where OPTIONS are:\n\
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
 

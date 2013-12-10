$NetBSD: patch-rsvg-base.c,v 1.1 2013/12/10 00:25:18 prlw1 Exp $

Allow rsvg to built on other systems than just Linux.

https://bugzilla.gnome.org/show_bug.cgi?id=710163
Finally committed as 02cb1983
--- rsvg-base.c.orig	2013-05-11 09:19:07.000000000 +0000
+++ rsvg-base.c
@@ -2190,8 +2190,7 @@ _rsvg_handle_allow_load (RsvgHandle *han
     dir = g_file_get_path (base);
     g_object_unref (base);
 
-    /* FIXME portability */
-    cdir = canonicalize_file_name (dir);
+    cdir = realpath (dir, NULL);
     g_free (dir);
     if (cdir == NULL)
         goto deny;
@@ -2200,8 +2199,7 @@ _rsvg_handle_allow_load (RsvgHandle *han
     if (path == NULL)
         goto deny;
 
-    /* FIXME portability */
-    cpath = canonicalize_file_name (path);
+    cpath = realpath (path, NULL);
     g_free (path);
 
     if (cpath == NULL)

$NetBSD: patch-src-win.c,v 1.2 2012/08/12 02:03:15 marino Exp $

--- src/win.c.orig	2012-05-22 11:39:06.000000000 +0000
+++ src/win.c
@@ -345,6 +345,7 @@ int WINAPI WinMain (HINSTANCE hThisInsta
         get_executable_name(exedir, 511);
         p = get_filename(exedir);
         p[0] = 0;
+        strcpy(exedir, "@BEMDATADIR@");
 
         config_load();
 

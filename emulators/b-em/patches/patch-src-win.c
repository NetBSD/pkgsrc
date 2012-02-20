$NetBSD: patch-src-win.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/win.c.orig	2011-02-12 17:34:10.000000000 +0000
+++ src/win.c
@@ -346,6 +346,7 @@ int WINAPI WinMain (HINSTANCE hThisInsta
         get_executable_name(exedir,511);
         p=get_filename(exedir);
         p[0]=0;
+	strcpy(exedir, "@BEMDATADIR@");
 
         loadconfig();
 

$NetBSD: patch-tools_dbusmenu-dumper.c,v 1.1 2016/05/20 22:07:41 youri Exp $

Remove deprecated function.

--- tools/dbusmenu-dumper.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ tools/dbusmenu-dumper.c
@@ -388,7 +388,6 @@ static GOptionEntry general_options[] = 
 int
 main (int argc, char ** argv)
 {
-	g_type_init();
 	GError * error = NULL;
 	GOptionContext * context;
 

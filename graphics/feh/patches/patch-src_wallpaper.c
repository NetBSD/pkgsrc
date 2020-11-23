$NetBSD: patch-src_wallpaper.c,v 1.1 2020/11/23 13:10:54 nia Exp $

ctype arguments must be unsigned char.

--- src/wallpaper.c.orig	2020-08-29 06:50:28.000000000 +0000
+++ src/wallpaper.c
@@ -625,7 +625,7 @@ int feh_wm_get_num_desks(void)
 		return(-1);
 	D(("Got from E IPC: %s\n", buf));
 	ptr = buf;
-	while (ptr && !isdigit(*ptr))
+	while (ptr && !isdigit((unsigned char)*ptr))
 		ptr++;
 	desks = atoi(ptr);
 

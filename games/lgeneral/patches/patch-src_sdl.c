$NetBSD: patch-src_sdl.c,v 1.1 2012/07/09 19:08:05 joerg Exp $

--- src/sdl.c.orig	2012-07-06 16:16:17.000000000 +0000
+++ src/sdl.c
@@ -31,7 +31,7 @@ int cur_time, last_time;
 /* sdl surface */
 
 /* return full path of bitmap */
-inline void get_full_bmp_path( char *full_path, char *file_name )
+static inline void get_full_bmp_path( char *full_path, char *file_name )
 {
     sprintf(full_path,  "%s/gfx/%s", SRC_DIR, file_name );
 }

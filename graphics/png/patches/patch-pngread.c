$NetBSD: patch-pngread.c,v 1.1 2012/02/20 22:42:29 wiz Exp $

Fix typo in define. From John Bowler <jbowler@acm.org>.

--- pngread.c.orig	2012-02-18 20:31:14.000000000 +0000
+++ pngread.c
@@ -72,7 +72,7 @@ png_create_read_struct_2,(png_const_char
    png_ptr->user_chunk_cache_max = PNG_USER_CHUNK_CACHE_MAX;
 #  endif
 
-#  ifdef PNG_SET_USER_CHUNK_MALLOC_MAX
+#  ifdef PNG_USER_CHUNK_MALLOC_MAX
    /* Added at libpng-1.2.43 and 1.4.1 */
    png_ptr->user_chunk_malloc_max = PNG_USER_CHUNK_MALLOC_MAX;
 #  endif

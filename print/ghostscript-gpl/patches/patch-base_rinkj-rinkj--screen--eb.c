$NetBSD: patch-base_rinkj-rinkj--screen--eb.c,v 1.1 2026/01/03 03:50:17 dholland Exp $

Fix wrong casts. Required with gcc14.

--- base/rinkj/rinkj-screen-eb.c~	2012-08-08 08:01:36.000000000 +0000
+++ base/rinkj/rinkj-screen-eb.c
@@ -182,8 +182,8 @@ rinkj_screen_eb_write (RinkjDevice *self
   for (; status >= 0 && z->yrem < z->height_out; z->yrem += z->height_in)
     {
       even_better_line (z->dither,
-                        (unsigned char *)out_buf,
-                        (unsigned char *)data_permuted);
+                        out_buf,
+                        (const unsigned char *const *)data_permuted);
 
       for (i = 0; i < n_planes; i++)
         {

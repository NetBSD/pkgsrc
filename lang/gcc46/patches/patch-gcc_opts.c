$NetBSD: patch-gcc_opts.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/opts.c.orig	2011-02-17 22:51:57.000000000 +0000
+++ gcc/opts.c
@@ -691,6 +691,8 @@ finish_options (struct gcc_options *opts
 
   if (!opts->x_flag_opts_finished)
     {
+      if (opts->x_flag_pic || opts->x_profile_flag)
+        opts->x_flag_pie = 0;
       if (opts->x_flag_pie)
 	opts->x_flag_pic = opts->x_flag_pie;
       if (opts->x_flag_pic && !opts->x_flag_pie)

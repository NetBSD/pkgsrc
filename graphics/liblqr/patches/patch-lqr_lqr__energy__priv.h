$NetBSD: patch-lqr_lqr__energy__priv.h,v 1.4 2025/04/29 09:26:11 tnn Exp $

* Replace K&R prototypes

--- lqr/lqr_energy_priv.h.orig	2025-04-29 09:20:15.710378164 +0000
+++ lqr/lqr_energy_priv.h
@@ -56,11 +56,11 @@ gdouble lqr_carver_read_cached_rgba(LqrC
 gdouble lqr_carver_read_cached_custom(LqrCarver *r, gint x, gint y, gint channel);
 
 /* cache brightness (or luma or else) to speedup energy computation */
-gdouble *lqr_carver_generate_rcache_bright();
-gdouble *lqr_carver_generate_rcache_luma();
-gdouble *lqr_carver_generate_rcache_rgba();
-gdouble *lqr_carver_generate_rcache_custom();
-gdouble *lqr_carver_generate_rcache();
+gdouble *lqr_carver_generate_rcache_bright(LqrCarver *);
+gdouble *lqr_carver_generate_rcache_luma(LqrCarver *);
+gdouble *lqr_carver_generate_rcache_rgba(LqrCarver *);
+gdouble *lqr_carver_generate_rcache_custom(LqrCarver *);
+gdouble *lqr_carver_generate_rcache(LqrCarver *);
 
 gfloat lqr_energy_builtin_grad_all(gint x, gint y, gint img_width, gint img_height, LqrReadingWindow *rwindow,
                                    LqrGradFunc gf);

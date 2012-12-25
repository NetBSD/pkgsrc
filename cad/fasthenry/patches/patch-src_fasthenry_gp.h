$NetBSD: patch-src_fasthenry_gp.h,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/gp.h.orig	2012-12-25 16:21:13.000000000 +0000
+++ src/fasthenry/gp.h
@@ -323,4 +323,6 @@ Gcell *pick_cell_based_on_vec();
 /* return opposite direction to dir */
 #define opposite_dir(dir) ( (dir + 2)%4 )
 
+void make_equiv_rect(double x0, double y0, double z0, double x_width, double y_width, Nonuni_gp *gp, char *name);
+
 #endif /* _GP_H */

$NetBSD: patch-src_mathfunc.c,v 1.1 2019/01/15 12:05:56 wiz Exp $

mathfunc.c:5036:43: error: initializer element is not a compile-time constant
https://gitlab.gnome.org/GNOME/gnumeric/issues/378

--- src/mathfunc.c.orig	2018-11-19 01:34:12.000000000 +0000
+++ src/mathfunc.c
@@ -5033,7 +5033,7 @@ gnm_lambert_w (gnm_float x, int k)
 {
 	gnm_float w;
 	static const gnm_float one_over_e = 1 / M_Egnum;
-	static const gnm_float sqrt_one_over_e = gnm_sqrt (1 / M_Egnum);
+	const gnm_float sqrt_one_over_e = gnm_sqrt (1 / M_Egnum);
 	static const gboolean debug = FALSE;
 	gnm_float wmin, wmax;
 	int i, imax = 20;

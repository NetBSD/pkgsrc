$NetBSD: patch-src-gpm-array-float.h,v 1.1 2012/01/20 17:02:55 joerg Exp $

--- src/gpm-array-float.h.orig	2012-01-18 16:40:53.000000000 +0000
+++ src/gpm-array-float.h
@@ -49,9 +49,9 @@ gfloat		 gpm_array_float_get_average		(G
 gboolean	 gpm_array_float_print			(GArray		*array);
 GArray		*gpm_array_float_convolve		(GArray		*data,
 							 GArray		*kernel);
-inline gfloat	 gpm_array_float_get			(GArray		*array,
+gfloat		 gpm_array_float_get			(GArray		*array,
 							 guint		 i);
-inline void	 gpm_array_float_set			(GArray		*array,
+void		 gpm_array_float_set			(GArray		*array,
 							 guint		 i,
 							 gfloat		 value);
 

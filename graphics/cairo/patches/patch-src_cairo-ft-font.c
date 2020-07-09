$NetBSD: patch-src_cairo-ft-font.c,v 1.1 2020/07/09 14:38:55 leot Exp $

Use FT_Done_MM_Var instead of free when available.

Fixes possible crashes and memory leaks.

Backport from upstream commits 90e85c24, a68c1968.

--- src/cairo-ft-font.c.orig	2020-07-09 14:26:11.503421448 +0000
+++ src/cairo-ft-font.c
@@ -459,6 +459,11 @@ _cairo_ft_unscaled_font_init (cairo_ft_u
 		unscaled->variations = calloc (ft_mm_var->num_axis, sizeof (FT_Fixed));
 		if (unscaled->variations)
 		    FT_Get_Var_Design_Coordinates (face, ft_mm_var->num_axis, unscaled->variations);
+#if HAVE_FT_DONE_MM_VAR
+		FT_Done_MM_Var (face->glyph->library, ft_mm_var);
+#else
+		free (ft_mm_var);
+#endif
 	    }
 	}
 #endif
@@ -2393,7 +2398,11 @@ skip:
 done:
         free (coords);
         free (current_coords);
+#if HAVE_FT_DONE_MM_VAR
+        FT_Done_MM_Var (face->glyph->library, ft_mm_var);
+#else
         free (ft_mm_var);
+#endif
     }
 }
 

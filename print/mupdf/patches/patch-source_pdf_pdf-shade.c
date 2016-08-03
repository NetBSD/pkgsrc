$NetBSD: patch-source_pdf_pdf-shade.c,v 1.1 2016/08/03 08:50:17 leot Exp $

Fix possible heap corruption vulnerability (via upstream bug 696954).

--- source/pdf/pdf-shade.c.orig	2016-04-21 11:14:32.000000000 +0000
+++ source/pdf/pdf-shade.c
@@ -206,7 +206,7 @@ pdf_load_mesh_params(fz_context *ctx, pd
 	obj = pdf_dict_get(ctx, dict, PDF_NAME_Decode);
 	if (pdf_array_len(ctx, obj) >= 6)
 	{
-		n = (pdf_array_len(ctx, obj) - 4) / 2;
+		n = fz_mini(FZ_MAX_COLORS, (pdf_array_len(ctx, obj) - 4) / 2);
 		shade->u.m.x0 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 0));
 		shade->u.m.x1 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 1));
 		shade->u.m.y0 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 2));

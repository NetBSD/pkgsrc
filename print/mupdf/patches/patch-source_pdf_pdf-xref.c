$NetBSD: patch-source_pdf_pdf-xref.c,v 1.1 2016/07/22 15:42:38 leot Exp $

Fix for CVE-2016-6265 use after free (via upstream bug 696941).

--- source/pdf/pdf-xref.c.orig	2016-04-21 11:14:32.000000000 +0000
+++ source/pdf/pdf-xref.c
@@ -1191,8 +1191,14 @@ pdf_load_xref(fz_context *ctx, pdf_docum
 				fz_throw(ctx, FZ_ERROR_GENERIC, "object offset out of range: %d (%d 0 R)", (int)entry->ofs, i);
 		}
 		if (entry->type == 'o')
-			if (entry->ofs <= 0 || entry->ofs >= xref_len || pdf_get_xref_entry(ctx, doc, entry->ofs)->type != 'n')
-				fz_throw(ctx, FZ_ERROR_GENERIC, "invalid reference to an objstm that does not exist: %d (%d 0 R)", (int)entry->ofs, i);
+		{
+			/* Read this into a local variable here, because pdf_get_xref_entry
+			 * may solidify the xref, hence invalidating "entry", meaning we
+			 * need a stashed value for the throw. */
+			fz_off_t ofs = entry->ofs;
+			if (ofs <= 0 || ofs >= xref_len || pdf_get_xref_entry(ctx, doc, ofs)->type != 'n')
+				fz_throw(ctx, FZ_ERROR_GENERIC, "invalid reference to an objstm that does not exist: %d (%d 0 R)", (int)ofs, i);
+		}
 	}
 }
 

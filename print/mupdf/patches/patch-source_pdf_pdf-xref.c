$NetBSD: patch-source_pdf_pdf-xref.c,v 1.3 2021/05/25 07:59:43 nia Exp $

Bug 703366: Fix double free of object during linearization.

This appears to happen because we parse an illegal object from
a broken file and assign it to object 0, which is defined to
be free.

Here, we fix the parsing code so this can't happen.

https://nvd.nist.gov/vuln/detail/CVE-2021-3407
http://git.ghostscript.com/?p=mupdf.git;h=cee7cefc610d42fd383b3c80c12cbc675443176a

--- source/pdf/pdf-xref.c.orig	2020-10-07 10:35:03.000000000 +0000
+++ source/pdf/pdf-xref.c
@@ -1012,6 +1012,8 @@ pdf_read_new_xref(fz_context *ctx, pdf_d
 	{
 		ofs = fz_tell(ctx, doc->file);
 		trailer = pdf_parse_ind_obj(ctx, doc, doc->file, buf, &num, &gen, &stm_ofs, NULL);
+		if (num == 0)
+			fz_throw(ctx, FZ_ERROR_GENERIC, "Trailer object number cannot be 0\n");
 	}
 	fz_catch(ctx)
 	{

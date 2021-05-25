$NetBSD: patch-source_pdf_pdf-parse.c,v 1.1 2021/05/25 07:59:43 nia Exp $

Bug 703366: Fix double free of object during linearization.

This appears to happen because we parse an illegal object from
a broken file and assign it to object 0, which is defined to
be free.

Here, we fix the parsing code so this can't happen.

https://nvd.nist.gov/vuln/detail/CVE-2021-3407
http://git.ghostscript.com/?p=mupdf.git;h=cee7cefc610d42fd383b3c80c12cbc675443176a

--- source/pdf/pdf-parse.c.orig	2020-10-07 10:35:03.000000000 +0000
+++ source/pdf/pdf-parse.c
@@ -749,6 +749,12 @@ pdf_parse_ind_obj(fz_context *ctx, pdf_d
 		fz_throw(ctx, FZ_ERROR_SYNTAX, "expected generation number (%d ? obj)", num);
 	}
 	gen = buf->i;
+	if (gen < 0 || gen >= 65536)
+	{
+		if (try_repair)
+			*try_repair = 1;
+		fz_throw(ctx, FZ_ERROR_SYNTAX, "invalid generation number (%d)", gen);
+	}
 
 	tok = pdf_lex(ctx, file, buf);
 	if (tok != PDF_TOK_OBJ)

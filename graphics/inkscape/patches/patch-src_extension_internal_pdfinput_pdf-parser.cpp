$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.15 2021/11/07 21:28:48 wiz Exp $

Fix build with poppler-21.11.0
https://gitlab.com/inkscape/inkscape/-/merge_requests/3622/diffs?commit_id=d7fb99ff5708d4fe3cf3526966b73d81da71a7b2

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2021-05-25 11:35:00.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -2169,7 +2169,11 @@ void PdfParser::opSetFont(Object args[],
   }
   if (printCommands) {
     printf("  font: tag=%s name='%s' %g\n",
+#if POPPLER_CHECK_VERSION(21,11,0)
+	   font->getTag().c_str(),
+#else
 	   font->getTag()->getCString(),
+#endif
 	   font->getName() ? font->getName()->getCString() : "???",
 	   args[1].getNum());
     fflush(stdout);

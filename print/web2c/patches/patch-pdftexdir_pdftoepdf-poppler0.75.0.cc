$NetBSD: patch-pdftexdir_pdftoepdf-poppler0.75.0.cc,v 1.3 2020/03/05 06:21:42 wiz Exp $

Fix build with poppler 0.86.1.

--- pdftexdir/pdftoepdf-poppler0.75.0.cc.orig	2019-03-21 06:38:16.000000000 +0000
+++ pdftexdir/pdftoepdf-poppler0.75.0.cc
@@ -22,7 +22,7 @@ This is based on the patch texlive-poppl
 https://git.archlinux.org/svntogit/packages.git/plain/texlive-bin/trunk
 by Arch Linux. A little modifications are made to avoid a crash for
 some kind of pdf images, such as figure_missing.pdf in gnuplot.
-The poppler should be 0.75.0 or newer versions.
+The poppler should be 0.83.0 or newer versions.
 POPPLER_VERSION should be defined.
 */
 
@@ -669,7 +669,7 @@ static void writeEncodings()
             else
                 glyphNames[i] = notdef;
         }
-        epdf_write_enc(glyphNames, r->enc_objnum);
+        epdf_write_enc(const_cast<const char**>(glyphNames), r->enc_objnum);
     }
     for (r = encodingList; r != 0; r = n) {
         n = r->next;
@@ -710,7 +710,7 @@ static const PDFRectangle *get_pagebox(P
 
 int
 read_pdf_info(char *image_name, char *page_name, int page_num,
-              int pagebox_spec, int minor_pdf_version_wanted,
+              int pagebox_spec, /* int major_pdf_version_wanted, */ int minor_pdf_version_wanted,
               int pdf_inclusion_errorlevel)
 {
     PdfDocument *pdf_doc;
@@ -723,7 +723,7 @@ read_pdf_info(char *image_name, char *pa
 #endif
     // initialize
     if (!isInit) {
-        globalParams = new GlobalParams();
+        globalParams = std::make_unique<GlobalParams>();
         globalParams->setErrQuiet(false);
         isInit = true;
     }
@@ -738,16 +738,16 @@ read_pdf_info(char *image_name, char *pa
 #ifdef POPPLER_VERSION
     pdf_major_version_found = pdf_doc->doc->getPDFMajorVersion();
     pdf_minor_version_found = pdf_doc->doc->getPDFMinorVersion();
-    if ((pdf_major_version_found > 1)
+    if ((pdf_major_version_found > /* major_pdf_version_wanted */ 1)
      || (pdf_minor_version_found > minor_pdf_version_wanted)) {
         const char *msg =
-            "PDF inclusion: found PDF version <%d.%d>, but at most version <1.%d> allowed";
+            "PDF inclusion: found PDF version <%d.%d>, but at most version <%d.%d> allowed";
         if (pdf_inclusion_errorlevel > 0) {
-            pdftex_fail(msg, pdf_major_version_found, pdf_minor_version_found, minor_pdf_version_wanted);
+            pdftex_fail(msg, pdf_major_version_found, pdf_minor_version_found, /* major_pdf_version_wanted, */ minor_pdf_version_wanted);
         } else if (pdf_inclusion_errorlevel < 0) {
             ; /* do nothing */
         } else { /* = 0, give warning */
-            pdftex_warn(msg, pdf_major_version_found, pdf_minor_version_found, minor_pdf_version_wanted);
+            pdftex_warn(msg, pdf_major_version_found, pdf_minor_version_found, /* major_pdf_version_wanted, */ minor_pdf_version_wanted);
         }
     }
 #else
@@ -757,15 +757,14 @@ read_pdf_info(char *image_name, char *pa
     if (page_name) {
         // get page by name
         GString name(page_name);
-        LinkDest *link = pdf_doc->doc->findDest(&name);
+        std::unique_ptr<LinkDest> link = pdf_doc->doc->findDest(&name);
         if (link == 0 || !link->isOk())
             pdftex_fail("PDF inclusion: invalid destination <%s>", page_name);
         Ref ref = link->getPageRef();
-        page_num = pdf_doc->doc->getCatalog()->findPage(ref.num, ref.gen);
+        page_num = pdf_doc->doc->getCatalog()->findPage(ref);
         if (page_num == 0)
             pdftex_fail("PDF inclusion: destination is not a page <%s>",
                         page_name);
-        delete link;
     } else {
         // get page by number
         if (page_num <= 0 || page_num > epdf_num_pages)
@@ -1107,7 +1106,5 @@ void epdf_check_mem()
             n = p->next;
             delete_document(p);
         }
-        // see above for globalParams
-        delete globalParams;
     }
 }

$NetBSD: patch-texk_web2c_luatexdir_image_pdftoepdf.w,v 1.5 2018/05/13 12:46:27 markd Exp $

Build with poppler 0.64

--- texk/web2c/luatexdir/image/pdftoepdf.w.orig	2018-01-17 18:00:12.000000000 +0000
+++ texk/web2c/luatexdir/image/pdftoepdf.w
@@ -361,9 +361,9 @@ void copyReal(PDF pdf, double d)
     pdf->cave = true;
 }
 
-static void copyString(PDF pdf, GooString * string)
+static void copyString(PDF pdf, const GooString * string)
 {
-    char *p;
+    const char *p;
     unsigned char c;
     size_t i, l;
     p = string->getCString();
@@ -393,7 +393,7 @@ static void copyString(PDF pdf, GooStrin
     pdf->cave = true;
 }
 
-static void copyName(PDF pdf, char *s)
+static void copyName(PDF pdf, const char *s)
 {
     pdf_out(pdf, '/');
     for (; *s != 0; s++) {

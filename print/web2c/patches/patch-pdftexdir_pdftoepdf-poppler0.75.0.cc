$NetBSD: patch-pdftexdir_pdftoepdf-poppler0.75.0.cc,v 1.1 2019/05/14 13:23:10 adam Exp $

Fix building.

--- pdftexdir/pdftoepdf-poppler0.75.0.cc.orig	2019-03-21 06:38:16.000000000 +0000
+++ pdftexdir/pdftoepdf-poppler0.75.0.cc
@@ -275,7 +275,7 @@ static int getNewObjectNumber(Ref ref)
 
 static void copyObject(Object *);
 
-static void copyName(char *s)
+static void copyName(const char *s)
 {
     pdf_puts("/");
     for (; *s != 0; s++) {
@@ -310,7 +310,7 @@ static void copyDict(Object * obj)
 static void copyFontDict(Object * obj, InObj * r)
 {
     int i, l;
-    char *key;
+    const char *key;
     if (!obj->isDict())
         pdftex_fail("PDF inclusion: invalid dict type <%s>",
                     obj->getTypeName());
@@ -382,7 +382,7 @@ static bool embeddableFont(Object * font
     return false;
 }
 
-static void copyFont(char *tag, Object * fontRef)
+static void copyFont(const char *tag, Object * fontRef)
 {
     Object fontdict, subtype, basefont, fontdescRef, fontdesc, charset,
         stemV;
@@ -467,7 +467,7 @@ static void copyFontResources(Object * o
     pdf_puts(">>\n");
 }
 
-static void copyOtherResources(Object * obj, char *key)
+static void copyOtherResources(Object * obj, const char *key)
 {
     // copies all other resources (write_epdf handles Fonts and ProcSets),
 
@@ -554,8 +554,8 @@ static void copyObject(Object * obj)
     Object obj1;
     int i, l, c;
     Ref ref;
-    char *p;
-    GString *s;
+    const char *p;
+    const GString *s;
     if (obj->isBool()) {
         pdf_printf("%s", obj->getBool()? "true" : "false");
     } else if (obj->isInt()) {
@@ -655,7 +655,7 @@ static void writeRefs()
 static void writeEncodings()
 {
     UsedEncoding *r, *n;
-    char *glyphNames[256], *s;
+    const char *glyphNames[256], *s;
     int i;
     for (r = encodingList; r != 0; r = r->next) {
         for (i = 0; i < 256; i++) {
@@ -685,20 +685,24 @@ static void writeEncodings()
 // get the pagebox according to the pagebox_spec
 static const PDFRectangle *get_pagebox(Page * page, int pagebox_spec)
 {
+    const PDFRectangle *ret;
+
     if (pagebox_spec == pdfboxspecmedia)
-        return page->getMediaBox();
+        ret = page->getMediaBox();
     else if (pagebox_spec == pdfboxspeccrop)
-        return page->getCropBox();
+        ret = page->getCropBox();
     else if (pagebox_spec == pdfboxspecbleed)
-        return page->getBleedBox();
+        ret = page->getBleedBox();
     else if (pagebox_spec == pdfboxspectrim)
-        return page->getTrimBox();
+        ret = page->getTrimBox();
     else if (pagebox_spec == pdfboxspecart)
-        return page->getArtBox();
+        ret = page->getArtBox();
     else
         pdftex_fail("PDF inclusion: unknown value of pagebox spec (%i)",
                     (int) pagebox_spec);
-    return page->getMediaBox(); // to make the compiler happy
+    // ret = page->getMediaBox(); // to make the compiler happy
+
+    return const_cast<PDFRectangle*>(ret);
 }
 
 
@@ -761,7 +765,7 @@ read_pdf_info(char *image_name, char *pa
         if (link == 0 || !link->isOk())
             pdftex_fail("PDF inclusion: invalid destination <%s>", page_name);
         Ref ref = link->getPageRef();
-        page_num = pdf_doc->doc->getCatalog()->findPage(ref.num, ref.gen);
+        page_num = pdf_doc->doc->getCatalog()->findPage(ref);
         if (page_num == 0)
             pdftex_fail("PDF inclusion: destination is not a page <%s>",
                         page_name);
@@ -822,7 +826,7 @@ void write_epdf(void)
     Object groupDict;
     bool writeSepGroup = false;
     Object info;
-    char *key;
+    const char *key;
     char s[256];
     int i, l;
     int rotate;

$NetBSD: patch-pdftexdir_pdftoepdf-newpoppler.cc,v 1.4 2019/02/28 19:34:50 markd Exp $

--- pdftexdir/pdftoepdf-newpoppler.cc.orig	2018-04-04 04:08:11.000000000 +0000
+++ pdftexdir/pdftoepdf-newpoppler.cc
@@ -120,7 +120,7 @@ struct UsedEncoding {
 
 static InObj *inObjList;
 static UsedEncoding *encodingList;
-static GBool isInit = gFalse;
+static bool isInit = false;
 
 // --------------------------------------------------------------------
 // Maintain list of open embedded PDF files
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
@@ -418,7 +418,7 @@ static void copyFont(char *tag, Object *
         && fontdescRef.isRef()
         && fontdesc.isDict()
         && embeddableFont(&fontdesc)
-        && (fontmap = lookup_fontmap(basefont.getName())) != NULL) {
+        && (fontmap = lookup_fontmap((char *)basefont.getName())) != NULL) {
         // round /StemV value, since the PDF input is a float
         // (see Font Descriptors in PDF reference), but we only store an
         // integer, since we don't want to change the struct.
@@ -427,7 +427,7 @@ static void copyFont(char *tag, Object *
         charset = fontdesc.dictLookup("CharSet");
         if (!charset.isNull() &&
             charset.isString() && is_subsetable(fontmap))
-            epdf_mark_glyphs(fd, charset.getString()->getCString());
+            epdf_mark_glyphs(fd, (char *)charset.getString()->c_str());
         else
             embed_whole_font(fd);
         addFontDesc(fontdescRef.getRef(), fd);
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
@@ -566,7 +566,7 @@ static void copyObject(Object * obj)
         pdf_printf("%s", convertNumToPDF(obj->getNum()));
     } else if (obj->isString()) {
         s = obj->getString();
-        p = s->getCString();
+        p = s->c_str();
         l = s->getLength();
         if (strlen(p) == (unsigned int) l) {
             pdf_puts("(");
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
 static PDFRectangle *get_pagebox(Page * page, int pagebox_spec)
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
 
 
@@ -724,8 +728,8 @@ read_pdf_info(char *image_name, char *pa
     // initialize
     if (!isInit) {
         globalParams = new GlobalParams();
-        globalParams->setErrQuiet(gFalse);
-        isInit = gTrue;
+        globalParams->setErrQuiet(false);
+        isInit = true;
     }
     // open PDF file
     pdf_doc = find_add_document(image_name);
@@ -822,7 +826,7 @@ void write_epdf(void)
     Object groupDict;
     bool writeSepGroup = false;
     Object info;
-    char *key;
+    const char *key;
     char s[256];
     int i, l;
     int rotate;
@@ -977,7 +981,7 @@ The changes below seem to work fine. 
             }
             l = dic1.getLength();
             for (i = 0; i < l; i++) {
-                groupDict.dictAdd(copyString(dic1.getKey(i)),
+                groupDict.dictAdd(const_cast<const char *>(copyString(dic1.getKey(i))),
                                   dic1.getValNF(i));
             }
 // end modification

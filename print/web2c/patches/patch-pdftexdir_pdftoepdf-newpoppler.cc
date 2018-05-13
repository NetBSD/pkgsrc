$NetBSD: patch-pdftexdir_pdftoepdf-newpoppler.cc,v 1.1 2018/05/13 13:01:02 markd Exp $

Build with poppler 0.64

--- pdftexdir/pdftoepdf-newpoppler.cc.orig	2018-04-04 04:08:11.000000000 +0000
+++ pdftexdir/pdftoepdf-newpoppler.cc
@@ -275,7 +275,7 @@ static int getNewObjectNumber(Ref ref)
 
 static void copyObject(Object *);
 
-static void copyName(char *s)
+static void copyName(const char *s)
 {
     pdf_puts("/");
     for (; *s != 0; s++) {
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
+            epdf_mark_glyphs(fd, (char *)charset.getString()->getCString());
         else
             embed_whole_font(fd);
         addFontDesc(fontdescRef.getRef(), fd);
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

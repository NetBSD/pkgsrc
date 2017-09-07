$NetBSD: patch-pdftexdir_pdftoepdf.cc,v 1.1 2017/09/07 14:15:52 tnn Exp $

Try to adapt to new poppler-0.59 Object API.

--- pdftexdir/pdftoepdf.cc.orig	2016-11-25 18:09:21.000000000 +0000
+++ pdftexdir/pdftoepdf.cc
@@ -94,7 +94,6 @@ class PdfObject {
   public:
     PdfObject() {               // nothing
     } ~PdfObject() {
-        iObject.free();
     }
     Object *operator->() {
         return &iObject;
@@ -217,10 +216,9 @@ static void delete_document(PdfDocument 
 
 static void initDictFromDict(PdfObject & obj, Dict * dict)
 {
-    obj->initDict(xref);
+    obj.iObject = Object(objDict);
     for (int i = 0, l = dict->getLength(); i < l; i++) {
-        Object obj1;
-        obj->dictAdd(copyString(dict->getKey(i)), dict->getValNF(i, &obj1));
+        obj->dictAdd(copyString(dict->getKey(i)), dict->getValNF(i));
     }
 }
 
@@ -323,7 +321,7 @@ static void copyDictEntry(Object * obj, 
     PdfObject obj1;
     copyName(obj->dictGetKey(i));
     pdf_puts(" ");
-    obj->dictGetValNF(i, &obj1);
+    obj1.iObject = obj->dictGetValNF(i);
     copyObject(&obj1);
     pdf_puts("\n");
 }
@@ -382,7 +380,7 @@ static void copyProcSet(Object * obj)
                     obj->getTypeName());
     pdf_puts("/ProcSet [ ");
     for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-        obj->arrayGetNF(i, &procset);
+        procset.iObject = obj->arrayGetNF(i);
         if (!procset->isName())
             pdftex_fail("PDF inclusion: invalid ProcSet entry type <%s>",
                         procset->getTypeName());
@@ -413,25 +411,25 @@ static void copyFont(char *tag, Object *
     }
     // Only handle included Type1 (and Type1C) fonts; anything else will be copied.
     // Type1C fonts are replaced by Type1 fonts, if REPLACE_TYPE1C is true.
-    if (!fixedinclusioncopyfont && fontRef->fetch(xref, &fontdict)->isDict()
-        && fontdict->dictLookup("Subtype", &subtype)->isName()
+    if (!fixedinclusioncopyfont && (fontdict.iObject = fontRef->fetch(xref), fontdict->isDict())
+        && (subtype.iObject = fontdict->dictLookup("Subtype"), subtype->isName())
         && !strcmp(subtype->getName(), "Type1")
-        && fontdict->dictLookup("BaseFont", &basefont)->isName()
-        && fontdict->dictLookupNF("FontDescriptor", &fontdescRef)->isRef()
-        && fontdescRef->fetch(xref, &fontdesc)->isDict()
-        && (fontdesc->dictLookup("FontFile", &fontfile)->isStream()
+        && (basefont.iObject = fontdict->dictLookup("BaseFont"), basefont->isName())
+        && (fontdescRef.iObject = fontdict->dictLookupNF("FontDescriptor"), fontdescRef->isRef())
+        && (fontdesc.iObject = fontdescRef->fetch(xref), fontdesc->isDict())
+        && ((fontfile.iObject = fontdesc->dictLookup("FontFile"), fontfile->isStream())
             || (REPLACE_TYPE1C
-                && fontdesc->dictLookup("FontFile3", &fontfile)->isStream()
-                && fontfile->streamGetDict()->lookup("Subtype",
-                                                     &ffsubtype)->isName()
+                && (fontfile.iObject = fontdesc->dictLookup("FontFile3"), fontfile->isStream())
+                && (ffsubtype.iObject = fontfile->streamGetDict()->lookup("Subtype"), 
+                                                     ffsubtype->isName())
                 && !strcmp(ffsubtype->getName(), "Type1C")))
         && (fontmap = lookup_fontmap(basefont->getName())) != NULL) {
         // round /StemV value, since the PDF input is a float
         // (see Font Descriptors in PDF reference), but we only store an
         // integer, since we don't want to change the struct.
-        fontdesc->dictLookup("StemV", &stemV);
+        stemV.iObject = fontdesc->dictLookup("StemV");
         fd = epdf_create_fontdescriptor(fontmap, zround(stemV->getNum()));
-        if (fontdesc->dictLookup("CharSet", &charset) &&
+        if ((charset.iObject = fontdesc->dictLookup("CharSet"), !charset->isNull()) &&
             charset->isString() && is_subsetable(fontmap))
             epdf_mark_glyphs(fd, charset->getString()->getCString());
         else
@@ -458,7 +456,7 @@ static void copyFontResources(Object * o
                     obj->getTypeName());
     pdf_puts("/Font << ");
     for (i = 0, l = obj->dictGetLength(); i < l; ++i) {
-        obj->dictGetValNF(i, &fontRef);
+        fontRef.iObject = obj->dictGetValNF(i);
         if (fontRef->isRef())
             copyFont(obj->dictGetKey(i), &fontRef);
         else if (fontRef->isDict()) {   // some programs generate pdf with embedded font object
@@ -601,7 +599,7 @@ static void copyObject(Object * obj)
     } else if (obj->isArray()) {
         pdf_puts("[");
         for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-            obj->arrayGetNF(i, &obj1);
+            obj1.iObject = obj->arrayGetNF(i);
             if (!obj1->isName())
                 pdf_puts(" ");
             copyObject(&obj1);
@@ -640,7 +638,7 @@ static void writeRefs()
         if (!r->written) {
             Object obj1;
             r->written = 1;
-            xref->fetch(r->ref.num, r->ref.gen, &obj1);
+            obj1 = xref->fetch(r->ref.num, r->ref.gen);
             if (r->type == objFont) {
                 assert(!obj1.isStream());
                 pdfbeginobj(r->num, 2);         // \pdfobjcompresslevel = 2 is for this
@@ -656,7 +654,7 @@ static void writeRefs()
                 pdf_puts("\n");
                 pdfendobj();
             }
-            obj1.free();
+            obj1.setToNull();
         }
     }
 }
@@ -867,7 +865,7 @@ void write_epdf(void)
     encodingList = 0;
     page = pdf_doc->doc->getCatalog()->getPage(epdf_selected_page);
     pageRef = pdf_doc->doc->getCatalog()->getPageRef(epdf_selected_page);
-    xref->fetch(pageRef->num, pageRef->gen, &pageObj);
+    pageObj.iObject = xref->fetch(pageRef->num, pageRef->gen);
     pageDict = pageObj->getDict();
     rotate = page->getRotate();
     PDFRectangle *pagebox;
@@ -886,7 +884,7 @@ void write_epdf(void)
         pdf_printf("/%s.PageNumber %i\n", pdfkeyprefix, (int) epdf_selected_page);
     }
     if ((suppress_ptex_info & MASK_SUPPRESS_PTEX_INFODICT) == 0) {
-        pdf_doc->doc->getDocInfoNF(&info);
+        info = pdf_doc->doc->getDocInfoNF();
         if (info.isRef()) {
             // the info dict must be indirect (PDF Ref p. 61)
             pdf_printf("/%s.InfoDict ", pdfkeyprefix);
@@ -942,13 +940,13 @@ void write_epdf(void)
     pdf_puts(stripzeros(s));
 
     // Metadata validity check (as a stream it must be indirect)
-    pageDict->lookupNF("Metadata", &dictObj);
+    dictObj.iObject = pageDict->lookupNF("Metadata");
     if (!dictObj->isNull() && !dictObj->isRef())
         pdftex_warn("PDF inclusion: /Metadata must be indirect object");
 
     // copy selected items in Page dictionary except Resources & Group
     for (i = 0; pageDictKeys[i] != NULL; i++) {
-        pageDict->lookupNF(pageDictKeys[i], &dictObj);
+        dictObj.iObject = pageDict->lookupNF(pageDictKeys[i]);
         if (!dictObj->isNull()) {
             pdf_newline();
             pdf_printf("/%s ", pageDictKeys[i]);
@@ -957,7 +955,7 @@ void write_epdf(void)
     } 
 
     // handle page group
-    pageDict->lookupNF("Group", &dictObj);
+    dictObj.iObject = pageDict->lookupNF("Group");
     if (!dictObj->isNull()) {
         if (pdfpagegroupval == 0) { 
             // another pdf with page group was included earlier on the
@@ -972,7 +970,7 @@ void write_epdf(void)
             copyObject(&dictObj);
         } else {
             // write Group dict as a separate object, since the Page dict also refers to it
-            pageDict->lookup("Group", &dictObj);
+            dictObj.iObject = pageDict->lookup("Group");
             if (!dictObj->isDict())
                 pdftex_fail("PDF inclusion: /Group dict missing");
             writeSepGroup = true;
@@ -996,7 +994,7 @@ void write_epdf(void)
         pdf_newline();
         pdf_puts("/Resources <<\n");
         for (i = 0, l = obj1->dictGetLength(); i < l; ++i) {
-            obj1->dictGetVal(i, &obj2);
+            obj2.iObject = obj1->dictGetVal(i);
             key = obj1->dictGetKey(i);
             if (strcmp("Font", key) == 0)
                 copyFontResources(&obj2);
@@ -1009,7 +1007,7 @@ void write_epdf(void)
     }
 
     // write the page contents
-    page->getContents(&contents);
+    contents.iObject = page->getContents();
     if (contents->isStream()) {
 
         // Variant A: get stream and recompress under control
@@ -1021,21 +1019,21 @@ void write_epdf(void)
 
         // Variant B: copy stream without recompressing
         //
-        contents->streamGetDict()->lookup("F", &obj1);
+        obj1.iObject = contents->streamGetDict()->lookup("F");
         if (!obj1->isNull()) {
             pdftex_fail("PDF inclusion: Unsupported external stream");
         }
-        contents->streamGetDict()->lookup("Length", &obj1);
+        obj1.iObject = contents->streamGetDict()->lookup("Length");
         assert(!obj1->isNull());
         pdf_puts("/Length ");
         copyObject(&obj1);
         pdf_puts("\n");
-        contents->streamGetDict()->lookup("Filter", &obj1);
+        obj1.iObject = contents->streamGetDict()->lookup("Filter");
         if (!obj1->isNull()) {
             pdf_puts("/Filter ");
             copyObject(&obj1);
             pdf_puts("\n");
-            contents->streamGetDict()->lookup("DecodeParms", &obj1);
+            obj1.iObject = contents->streamGetDict()->lookup("DecodeParms");
             if (!obj1->isNull()) {
                 pdf_puts("/DecodeParms ");
                 copyObject(&obj1);
@@ -1048,9 +1046,7 @@ void write_epdf(void)
     } else if (contents->isArray()) {
         pdfbeginstream();
         for (i = 0, l = contents->arrayGetLength(); i < l; ++i) {
-            Object contentsobj;
-            copyStream((contents->arrayGet(i, &contentsobj))->getStream());
-            contentsobj.free();
+            copyStream((contents->arrayGet(i)).getStream());
             if (i < l - 1)
                 pdf_newline();  // add a newline after each stream except the last
         }

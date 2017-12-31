$NetBSD: patch-pdftexdir_pdftoepdf.cc,v 1.3 2017/12/31 00:44:32 markd Exp $

Allow recent poppler - from ArchLinux

--- pdftexdir/pdftoepdf.cc.orig	2016-11-25 18:09:21.000000000 +0000
+++ pdftexdir/pdftoepdf.cc
@@ -84,31 +84,6 @@ extern integer zround(double);
 #define MASK_SUPPRESS_PTEX_PAGENUMBER 0x04
 #define MASK_SUPPRESS_PTEX_INFODICT   0x08
 
-// PdfObject encapsulates the xpdf Object type,
-// and properly frees its resources on destruction.
-// Use obj-> to access members of the Object,
-// and &obj to get a pointer to the object.
-// It is no longer necessary to call Object::free explicitely.
-
-class PdfObject {
-  public:
-    PdfObject() {               // nothing
-    } ~PdfObject() {
-        iObject.free();
-    }
-    Object *operator->() {
-        return &iObject;
-    }
-    Object *operator&() {
-        return &iObject;
-    }
-  private:                     // no copying or assigning
-    PdfObject(const PdfObject &);
-    void operator=(const PdfObject &);
-  public:
-    Object iObject;
-};
-
 // When copying the Resources of the selected page, all objects are copied
 // recusively top-down. Indirect objects however are not fetched during
 // copying, but get a new object number from pdfTeX and then will be
@@ -212,18 +187,6 @@ static void delete_document(PdfDocument
     delete pdf_doc;
 }
 
-// Replacement for
-//      Object *initDict(Dict *dict1){ initObj(objDict); dict = dict1; return this; }
-
-static void initDictFromDict(PdfObject & obj, Dict * dict)
-{
-    obj->initDict(xref);
-    for (int i = 0, l = dict->getLength(); i < l; i++) {
-        Object obj1;
-        obj->dictAdd(copyString(dict->getKey(i)), dict->getValNF(i, &obj1));
-    }
-}
-
 // --------------------------------------------------------------------
 
 static int addEncoding(GfxFont * gfont)
@@ -320,10 +283,10 @@ static void copyName(char *s)
 
 static void copyDictEntry(Object * obj, int i)
 {
-    PdfObject obj1;
+    Object obj1;
     copyName(obj->dictGetKey(i));
     pdf_puts(" ");
-    obj->dictGetValNF(i, &obj1);
+    obj1 = obj->dictGetValNF(i);
     copyObject(&obj1);
     pdf_puts("\n");
 }
@@ -376,17 +339,17 @@ static void copyStream(Stream * str)
 static void copyProcSet(Object * obj)
 {
     int i, l;
-    PdfObject procset;
+    Object procset;
     if (!obj->isArray())
         pdftex_fail("PDF inclusion: invalid ProcSet array type <%s>",
                     obj->getTypeName());
     pdf_puts("/ProcSet [ ");
     for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-        obj->arrayGetNF(i, &procset);
-        if (!procset->isName())
+        procset = obj->arrayGetNF(i);
+        if (!procset.isName())
             pdftex_fail("PDF inclusion: invalid ProcSet entry type <%s>",
-                        procset->getTypeName());
-        copyName(procset->getName());
+                        procset.getTypeName());
+        copyName(procset.getName());
         pdf_puts(" ");
     }
     pdf_puts("]\n");
@@ -394,10 +357,29 @@ static void copyProcSet(Object * obj)
 
 #define REPLACE_TYPE1C true
 
+static bool embeddableFont(Object * fontdesc)
+{
+    Object fontfile, ffsubtype;
+
+    if (!fontdesc->isDict())
+        return false;
+    fontfile = fontdesc->dictLookup("FontFile");
+    if (fontfile.isStream())
+        return true;
+    if (REPLACE_TYPE1C) {
+        fontfile = fontdesc->dictLookup("FontFile3");
+        if (!fontfile.isStream())
+            return false;
+        ffsubtype = fontfile.streamGetDict()->lookup("Subtype");
+        return ffsubtype.isName() && !strcmp(ffsubtype.getName(), "Type1C");
+    }
+    return false;
+}
+
 static void copyFont(char *tag, Object * fontRef)
 {
-    PdfObject fontdict, subtype, basefont, fontdescRef, fontdesc, charset,
-        fontfile, ffsubtype, stemV;
+    Object fontdict, subtype, basefont, fontdescRef, fontdesc, charset,
+        stemV;
     GfxFont *gfont;
     fd_entry *fd;
     fm_entry *fontmap;
@@ -413,33 +395,39 @@ static void copyFont(char *tag, Object *
     }
     // Only handle included Type1 (and Type1C) fonts; anything else will be copied.
     // Type1C fonts are replaced by Type1 fonts, if REPLACE_TYPE1C is true.
-    if (!fixedinclusioncopyfont && fontRef->fetch(xref, &fontdict)->isDict()
-        && fontdict->dictLookup("Subtype", &subtype)->isName()
-        && !strcmp(subtype->getName(), "Type1")
-        && fontdict->dictLookup("BaseFont", &basefont)->isName()
-        && fontdict->dictLookupNF("FontDescriptor", &fontdescRef)->isRef()
-        && fontdescRef->fetch(xref, &fontdesc)->isDict()
-        && (fontdesc->dictLookup("FontFile", &fontfile)->isStream()
-            || (REPLACE_TYPE1C
-                && fontdesc->dictLookup("FontFile3", &fontfile)->isStream()
-                && fontfile->streamGetDict()->lookup("Subtype",
-                                                     &ffsubtype)->isName()
-                && !strcmp(ffsubtype->getName(), "Type1C")))
-        && (fontmap = lookup_fontmap(basefont->getName())) != NULL) {
+    fontdict = fontRef->fetch(xref);
+    fontdesc = Object(objNull);
+    if (fontdict.isDict()) {
+        subtype = fontdict.dictLookup("Subtype");
+        basefont = fontdict.dictLookup("BaseFont");
+        fontdescRef = fontdict.dictLookupNF("FontDescriptor");
+        if (fontdescRef.isRef()) {
+            fontdesc = fontdescRef.fetch(xref);
+        }
+    }
+    if (!fixedinclusioncopyfont && fontdict.isDict()
+        && subtype.isName()
+        && !strcmp(subtype.getName(), "Type1")
+        && basefont.isName()
+        && fontdescRef.isRef()
+        && fontdesc.isDict()
+        && embeddableFont(&fontdesc)
+        && (fontmap = lookup_fontmap(basefont.getName())) != NULL) {
         // round /StemV value, since the PDF input is a float
         // (see Font Descriptors in PDF reference), but we only store an
         // integer, since we don't want to change the struct.
-        fontdesc->dictLookup("StemV", &stemV);
-        fd = epdf_create_fontdescriptor(fontmap, zround(stemV->getNum()));
-        if (fontdesc->dictLookup("CharSet", &charset) &&
-            charset->isString() && is_subsetable(fontmap))
-            epdf_mark_glyphs(fd, charset->getString()->getCString());
+        stemV = fontdesc.dictLookup("StemV");
+        fd = epdf_create_fontdescriptor(fontmap, zround(stemV.getNum()));
+        charset = fontdesc.dictLookup("CharSet");
+        if (!charset.isNull() &&
+            charset.isString() && is_subsetable(fontmap))
+            epdf_mark_glyphs(fd, charset.getString()->getCString());
         else
             embed_whole_font(fd);
-        addFontDesc(fontdescRef->getRef(), fd);
+        addFontDesc(fontdescRef.getRef(), fd);
         copyName(tag);
         gfont = GfxFont::makeFont(xref, tag, fontRef->getRef(),
-                                  fontdict->getDict());
+                                  fontdict.getDict());
         pdf_printf(" %d 0 R ", addFont(fontRef->getRef(), fd,
                                        addEncoding(gfont)));
     } else {
@@ -451,24 +439,24 @@ static void copyFont(char *tag, Object *
 
 static void copyFontResources(Object * obj)
 {
-    PdfObject fontRef;
+    Object fontRef;
     int i, l;
     if (!obj->isDict())
         pdftex_fail("PDF inclusion: invalid font resources dict type <%s>",
                     obj->getTypeName());
     pdf_puts("/Font << ");
     for (i = 0, l = obj->dictGetLength(); i < l; ++i) {
-        obj->dictGetValNF(i, &fontRef);
-        if (fontRef->isRef())
+        fontRef = obj->dictGetValNF(i);
+        if (fontRef.isRef())
             copyFont(obj->dictGetKey(i), &fontRef);
-        else if (fontRef->isDict()) {   // some programs generate pdf with embedded font object
+        else if (fontRef.isDict()) {   // some programs generate pdf with embedded font object
             copyName(obj->dictGetKey(i));
             pdf_puts(" ");
             copyObject(&fontRef);
         }
         else
             pdftex_fail("PDF inclusion: invalid font in reference type <%s>",
-                        fontRef->getTypeName());
+                        fontRef.getTypeName());
     }
     pdf_puts(">>\n");
 }
@@ -557,7 +545,7 @@ static char *convertNumToPDF(double n)
 
 static void copyObject(Object * obj)
 {
-    PdfObject obj1;
+    Object obj1;
     int i, l, c;
     Ref ref;
     char *p;
@@ -601,8 +589,8 @@ static void copyObject(Object * obj)
     } else if (obj->isArray()) {
         pdf_puts("[");
         for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-            obj->arrayGetNF(i, &obj1);
-            if (!obj1->isName())
+            obj1 = obj->arrayGetNF(i);
+            if (!obj1.isName())
                 pdf_puts(" ");
             copyObject(&obj1);
         }
@@ -612,9 +600,8 @@ static void copyObject(Object * obj)
         copyDict(obj);
         pdf_puts(">>");
     } else if (obj->isStream()) {
-        initDictFromDict(obj1, obj->streamGetDict());
         pdf_puts("<<\n");
-        copyDict(&obj1);
+        copyDict(obj->getStream()->getDictObject());
         pdf_puts(">>\n");
         pdf_puts("stream\n");
         copyStream(obj->getStream()->getUndecodedStream());
@@ -638,9 +625,8 @@ static void writeRefs()
     InObj *r;
     for (r = inObjList; r != 0; r = r->next) {
         if (!r->written) {
-            Object obj1;
             r->written = 1;
-            xref->fetch(r->ref.num, r->ref.gen, &obj1);
+            Object obj1 = xref->fetch(r->ref.num, r->ref.gen);
             if (r->type == objFont) {
                 assert(!obj1.isStream());
                 pdfbeginobj(r->num, 2);         // \pdfobjcompresslevel = 2 is for this
@@ -656,7 +642,6 @@ static void writeRefs()
                 pdf_puts("\n");
                 pdfendobj();
             }
-            obj1.free();
         }
     }
 }
@@ -839,8 +824,8 @@ void write_epdf(void)
     Page *page;
     Ref *pageRef;
     Dict *pageDict;
-    PdfObject contents, obj1, obj2, pageObj, dictObj;
-    PdfObject groupDict;
+    Object contents, obj1, obj2, pageObj, dictObj;
+    Object groupDict;
     bool writeSepGroup = false;
     Object info;
     char *key;
@@ -867,8 +852,8 @@ void write_epdf(void)
     encodingList = 0;
     page = pdf_doc->doc->getCatalog()->getPage(epdf_selected_page);
     pageRef = pdf_doc->doc->getCatalog()->getPageRef(epdf_selected_page);
-    xref->fetch(pageRef->num, pageRef->gen, &pageObj);
-    pageDict = pageObj->getDict();
+    pageObj = xref->fetch(pageRef->num, pageRef->gen);
+    pageDict = pageObj.getDict();
     rotate = page->getRotate();
     PDFRectangle *pagebox;
     // write the Page header
@@ -886,7 +871,7 @@ void write_epdf(void)
         pdf_printf("/%s.PageNumber %i\n", pdfkeyprefix, (int) epdf_selected_page);
     }
     if ((suppress_ptex_info & MASK_SUPPRESS_PTEX_INFODICT) == 0) {
-        pdf_doc->doc->getDocInfoNF(&info);
+        info = pdf_doc->doc->getDocInfoNF();
         if (info.isRef()) {
             // the info dict must be indirect (PDF Ref p. 61)
             pdf_printf("/%s.InfoDict ", pdfkeyprefix);
@@ -942,14 +927,14 @@ void write_epdf(void)
     pdf_puts(stripzeros(s));
 
     // Metadata validity check (as a stream it must be indirect)
-    pageDict->lookupNF("Metadata", &dictObj);
-    if (!dictObj->isNull() && !dictObj->isRef())
+    dictObj = pageDict->lookupNF("Metadata");
+    if (!dictObj.isNull() && !dictObj.isRef())
         pdftex_warn("PDF inclusion: /Metadata must be indirect object");
 
     // copy selected items in Page dictionary except Resources & Group
     for (i = 0; pageDictKeys[i] != NULL; i++) {
-        pageDict->lookupNF(pageDictKeys[i], &dictObj);
-        if (!dictObj->isNull()) {
+        dictObj = pageDict->lookupNF(pageDictKeys[i]);
+        if (!dictObj.isNull()) {
             pdf_newline();
             pdf_printf("/%s ", pageDictKeys[i]);
             copyObject(&dictObj); // preserves indirection
@@ -957,8 +942,8 @@ void write_epdf(void)
     } 
 
     // handle page group
-    pageDict->lookupNF("Group", &dictObj);
-    if (!dictObj->isNull()) {
+    dictObj = pageDict->lookupNF("Group");
+    if (!dictObj.isNull()) {
         if (pdfpagegroupval == 0) { 
             // another pdf with page group was included earlier on the
             // same page; copy the Group entry as is.  See manual for
@@ -972,11 +957,11 @@ void write_epdf(void)
             copyObject(&dictObj);
         } else {
             // write Group dict as a separate object, since the Page dict also refers to it
-            pageDict->lookup("Group", &dictObj);
-            if (!dictObj->isDict())
+            dictObj = pageDict->lookup("Group");
+            if (!dictObj.isDict())
                 pdftex_fail("PDF inclusion: /Group dict missing");
             writeSepGroup = true;
-            initDictFromDict(groupDict, page->getGroup());
+            groupDict = Object(page->getGroup());
             pdf_printf("/Group %ld 0 R\n", (long)pdfpagegroupval);
         }
     }
@@ -989,14 +974,14 @@ void write_epdf(void)
         pdftex_warn
             ("PDF inclusion: /Resources missing. 'This practice is not recommended' (PDF Ref)");
     } else {
-        initDictFromDict(obj1, page->getResourceDict());
+        Object *obj1 = page->getResourceDictObject();
         if (!obj1->isDict())
             pdftex_fail("PDF inclusion: invalid resources dict type <%s>",
                         obj1->getTypeName());
         pdf_newline();
         pdf_puts("/Resources <<\n");
         for (i = 0, l = obj1->dictGetLength(); i < l; ++i) {
-            obj1->dictGetVal(i, &obj2);
+            obj2 = obj1->dictGetVal(i);
             key = obj1->dictGetKey(i);
             if (strcmp("Font", key) == 0)
                 copyFontResources(&obj2);
@@ -1009,8 +994,8 @@ void write_epdf(void)
     }
 
     // write the page contents
-    page->getContents(&contents);
-    if (contents->isStream()) {
+    contents = page->getContents();
+    if (contents.isStream()) {
 
         // Variant A: get stream and recompress under control
         // of \pdfcompresslevel
@@ -1021,36 +1006,35 @@ void write_epdf(void)
 
         // Variant B: copy stream without recompressing
         //
-        contents->streamGetDict()->lookup("F", &obj1);
-        if (!obj1->isNull()) {
+        obj1 = contents.streamGetDict()->lookup("F");
+        if (!obj1.isNull()) {
             pdftex_fail("PDF inclusion: Unsupported external stream");
         }
-        contents->streamGetDict()->lookup("Length", &obj1);
-        assert(!obj1->isNull());
+        obj1 = contents.streamGetDict()->lookup("Length");
+        assert(!obj1.isNull());
         pdf_puts("/Length ");
         copyObject(&obj1);
         pdf_puts("\n");
-        contents->streamGetDict()->lookup("Filter", &obj1);
-        if (!obj1->isNull()) {
+        obj1 = contents.streamGetDict()->lookup("Filter");
+        if (!obj1.isNull()) {
             pdf_puts("/Filter ");
             copyObject(&obj1);
             pdf_puts("\n");
-            contents->streamGetDict()->lookup("DecodeParms", &obj1);
-            if (!obj1->isNull()) {
+            obj1 = contents.streamGetDict()->lookup("DecodeParms");
+            if (!obj1.isNull()) {
                 pdf_puts("/DecodeParms ");
                 copyObject(&obj1);
                 pdf_puts("\n");
             }
         }
         pdf_puts(">>\nstream\n");
-        copyStream(contents->getStream()->getUndecodedStream());
+        copyStream(contents.getStream()->getUndecodedStream());
         pdfendstream();
-    } else if (contents->isArray()) {
+    } else if (contents.isArray()) {
         pdfbeginstream();
-        for (i = 0, l = contents->arrayGetLength(); i < l; ++i) {
-            Object contentsobj;
-            copyStream((contents->arrayGet(i, &contentsobj))->getStream());
-            contentsobj.free();
+        for (i = 0, l = contents.arrayGetLength(); i < l; ++i) {
+            Object contentsobj = contents.arrayGet(i);
+            copyStream(contentsobj.getStream());
             if (i < l - 1)
                 pdf_newline();  // add a newline after each stream except the last
         }

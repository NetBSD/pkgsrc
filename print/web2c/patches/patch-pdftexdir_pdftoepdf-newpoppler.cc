$NetBSD: patch-pdftexdir_pdftoepdf-newpoppler.cc,v 1.5 2019/05/10 19:19:09 ryoon Exp $

--- pdftexdir/pdftoepdf-newpoppler.cc.orig	2018-04-04 04:08:11.000000000 +0000
+++ pdftexdir/pdftoepdf-newpoppler.cc
@@ -22,7 +22,7 @@ This is based on the patch texlive-poppl
 https://git.archlinux.org/svntogit/packages.git/plain/texlive-bin/trunk
 by Arch Linux. A little modifications are made to avoid a crash for
 some kind of pdf images, such as figure_missing.pdf in gnuplot.
-The poppler should be 0.59.0 or newer versions.
+The poppler should be 0.76.0 or newer versions.
 POPPLER_VERSION should be defined.
 */
 
@@ -120,7 +120,7 @@ struct UsedEncoding {
 
 static InObj *inObjList;
 static UsedEncoding *encodingList;
-static GBool isInit = gFalse;
+static bool isInit = false;
 
 // --------------------------------------------------------------------
 // Maintain list of open embedded PDF files
@@ -290,9 +290,9 @@ static void copyName(char *s)
 static void copyDictEntry(Object * obj, int i)
 {
     Object obj1;
-    copyName(obj->dictGetKey(i));
+    copyName((char *)obj->dictGetKey(i));
     pdf_puts(" ");
-    obj1 = obj->dictGetValNF(i);
+    obj1 = obj->dictGetValNF(i).copy();
     copyObject(&obj1);
     pdf_puts("\n");
 }
@@ -317,7 +317,7 @@ static void copyFontDict(Object * obj, I
     pdf_puts("<<\n");
     assert(r->type == objFont); // FontDescriptor is in fd_tree
     for (i = 0, l = obj->dictGetLength(); i < l; ++i) {
-        key = obj->dictGetKey(i);
+        key = (char *)obj->dictGetKey(i);
         if (strncmp("FontDescriptor", key, strlen("FontDescriptor")) == 0
             || strncmp("BaseFont", key, strlen("BaseFont")) == 0
             || strncmp("Encoding", key, strlen("Encoding")) == 0)
@@ -351,11 +351,11 @@ static void copyProcSet(Object * obj)
                     obj->getTypeName());
     pdf_puts("/ProcSet [ ");
     for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-        procset = obj->arrayGetNF(i);
+        procset = obj->arrayGetNF(i).copy();
         if (!procset.isName())
             pdftex_fail("PDF inclusion: invalid ProcSet entry type <%s>",
                         procset.getTypeName());
-        copyName(procset.getName());
+        copyName((char *)procset.getName());
         pdf_puts(" ");
     }
     pdf_puts("]\n");
@@ -406,7 +406,7 @@ static void copyFont(char *tag, Object *
     if (fontdict.isDict()) {
         subtype = fontdict.dictLookup("Subtype");
         basefont = fontdict.dictLookup("BaseFont");
-        fontdescRef = fontdict.dictLookupNF("FontDescriptor");
+        fontdescRef = fontdict.dictLookupNF("FontDescriptor").copy();
         if (fontdescRef.isRef()) {
             fontdesc = fontdescRef.fetch(xref);
         }
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
@@ -452,11 +452,11 @@ static void copyFontResources(Object * o
                     obj->getTypeName());
     pdf_puts("/Font << ");
     for (i = 0, l = obj->dictGetLength(); i < l; ++i) {
-        fontRef = obj->dictGetValNF(i);
+        fontRef = obj->dictGetValNF(i).copy();
         if (fontRef.isRef())
-            copyFont(obj->dictGetKey(i), &fontRef);
+            copyFont((char *)obj->dictGetKey(i), &fontRef);
         else if (fontRef.isDict()) {   // some programs generate pdf with embedded font object
-            copyName(obj->dictGetKey(i));
+            copyName((char *)obj->dictGetKey(i));
             pdf_puts(" ");
             copyObject(&fontRef);
         }
@@ -565,8 +565,8 @@ static void copyObject(Object * obj)
     } else if (obj->isNum()) {
         pdf_printf("%s", convertNumToPDF(obj->getNum()));
     } else if (obj->isString()) {
-        s = obj->getString();
-        p = s->getCString();
+        s = (GooString *)obj->getString();
+        p = (char *)s->c_str();
         l = s->getLength();
         if (strlen(p) == (unsigned int) l) {
             pdf_puts("(");
@@ -589,13 +589,13 @@ static void copyObject(Object * obj)
             pdf_puts(">");
         }
     } else if (obj->isName()) {
-        copyName(obj->getName());
+        copyName((char *)obj->getName());
     } else if (obj->isNull()) {
         pdf_puts("null");
     } else if (obj->isArray()) {
         pdf_puts("[");
         for (i = 0, l = obj->arrayGetLength(); i < l; ++i) {
-            obj1 = obj->arrayGetNF(i);
+            obj1 = obj->arrayGetNF(i).copy();
             if (!obj1.isName())
                 pdf_puts(" ");
             copyObject(&obj1);
@@ -664,12 +664,12 @@ static void writeEncodings()
                     ("PDF inclusion: CID fonts are not supported"
                      " (try to disable font replacement to fix this)");
             }
-            if ((s = ((Gfx8BitFont *) r->font)->getCharName(i)) != 0)
+            if ((s = (char *)((Gfx8BitFont *) r->font)->getCharName(i)) != 0)
                 glyphNames[i] = s;
             else
                 glyphNames[i] = notdef;
         }
-        epdf_write_enc(glyphNames, r->enc_objnum);
+        epdf_write_enc(const_cast<const char**>(glyphNames), r->enc_objnum);
     }
     for (r = encodingList; r != 0; r = n) {
         n = r->next;
@@ -683,7 +683,7 @@ static void writeEncodings()
 }
 
 // get the pagebox according to the pagebox_spec
-static PDFRectangle *get_pagebox(Page * page, int pagebox_spec)
+static const PDFRectangle *get_pagebox(Page * page, int pagebox_spec)
 {
     if (pagebox_spec == pdfboxspecmedia)
         return page->getMediaBox();
@@ -715,7 +715,7 @@ read_pdf_info(char *image_name, char *pa
 {
     PdfDocument *pdf_doc;
     Page *page;
-    PDFRectangle *pagebox;
+    const PDFRectangle *pagebox;
 #ifdef POPPLER_VERSION
     int pdf_major_version_found, pdf_minor_version_found;
 #else
@@ -724,8 +724,8 @@ read_pdf_info(char *image_name, char *pa
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
@@ -761,7 +761,7 @@ read_pdf_info(char *image_name, char *pa
         if (link == 0 || !link->isOk())
             pdftex_fail("PDF inclusion: invalid destination <%s>", page_name);
         Ref ref = link->getPageRef();
-        page_num = pdf_doc->doc->getCatalog()->findPage(ref.num, ref.gen);
+        page_num = pdf_doc->doc->getCatalog()->findPage(ref);
         if (page_num == 0)
             pdftex_fail("PDF inclusion: destination is not a page <%s>",
                         page_name);
@@ -849,7 +849,7 @@ void write_epdf(void)
     pageObj = xref->fetch(pageRef->num, pageRef->gen);
     pageDict = pageObj.getDict();
     rotate = page->getRotate();
-    PDFRectangle *pagebox;
+    const PDFRectangle *pagebox;
     // write the Page header
     pdf_puts("/Type /XObject\n");
     pdf_puts("/Subtype /Form\n");
@@ -865,7 +865,7 @@ void write_epdf(void)
         pdf_printf("/%s.PageNumber %i\n", pdfkeyprefix, (int) epdf_selected_page);
     }
     if ((suppress_ptex_info & MASK_SUPPRESS_PTEX_INFODICT) == 0) {
-        info = pdf_doc->doc->getDocInfoNF();
+        info = pdf_doc->doc->getDocInfoNF().copy();
         if (info.isRef()) {
             // the info dict must be indirect (PDF Ref p. 61)
             pdf_printf("/%s.InfoDict ", pdfkeyprefix);
@@ -921,13 +921,13 @@ void write_epdf(void)
     pdf_puts(stripzeros(s));
 
     // Metadata validity check (as a stream it must be indirect)
-    dictObj = pageDict->lookupNF("Metadata");
+    dictObj = pageDict->lookupNF("Metadata").copy();
     if (!dictObj.isNull() && !dictObj.isRef())
         pdftex_warn("PDF inclusion: /Metadata must be indirect object");
 
     // copy selected items in Page dictionary except Resources & Group
     for (i = 0; pageDictKeys[i] != NULL; i++) {
-        dictObj = pageDict->lookupNF(pageDictKeys[i]);
+        dictObj = pageDict->lookupNF(pageDictKeys[i]).copy();
         if (!dictObj.isNull()) {
             pdf_newline();
             pdf_printf("/%s ", pageDictKeys[i]);
@@ -936,7 +936,7 @@ void write_epdf(void)
     } 
 
     // handle page group
-    dictObj = pageDict->lookupNF("Group");
+    dictObj = pageDict->lookupNF("Group").copy();
     if (!dictObj.isNull()) {
         if (pdfpagegroupval == 0) { 
             // another pdf with page group was included earlier on the
@@ -977,8 +977,8 @@ The changes below seem to work fine. 
             }
             l = dic1.getLength();
             for (i = 0; i < l; i++) {
-                groupDict.dictAdd(copyString(dic1.getKey(i)),
-                                  dic1.getValNF(i));
+                groupDict.dictAdd((const char *)copyString(dic1.getKey(i)),
+                                  dic1.getValNF(i).copy());
             }
 // end modification
             pdf_printf("/Group %ld 0 R\n", (long)pdfpagegroupval);
@@ -1001,13 +1001,13 @@ The changes below seem to work fine. 
         pdf_puts("/Resources <<\n");
         for (i = 0, l = obj1->dictGetLength(); i < l; ++i) {
             obj2 = obj1->dictGetVal(i);
-            key = obj1->dictGetKey(i);
+            key = (char *)obj1->dictGetKey(i);
             if (strcmp("Font", key) == 0)
                 copyFontResources(&obj2);
             else if (strcmp("ProcSet", key) == 0)
                 copyProcSet(&obj2);
             else
-                copyOtherResources(&obj2, key);
+                copyOtherResources(&obj2, (char *)key);
         }
         pdf_puts(">>\n");
     }

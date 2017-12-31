$NetBSD: patch-texk_web2c_luatexdir_image_pdftoepdf.w,v 1.3 2017/12/31 00:41:19 markd Exp $

The ctangle tex-to-C generator strips whitespace, resulting in "C++11 requires
a space between literal and identifier" failures.  Pull in hacky patch from
Gentoo which avoids this problem by using newlines.

Add support for newer poppler's from ArchLinux

--- texk/web2c/luatexdir/image/pdftoepdf.w.orig	2016-11-25 18:09:14.000000000 +0000
+++ texk/web2c/luatexdir/image/pdftoepdf.w
@@ -71,7 +71,11 @@ static char *get_file_checksum(const cha
         ck = (char *) malloc(PDF_CHECKSUM_SIZE);
         if (ck == NULL)
             formatted_error("pdf inclusion","out of memory while processing '%s'", a);
-        snprintf(ck, PDF_CHECKSUM_SIZE, "%" PRIu64 "_%" PRIu64, (uint64_t) size,(uint64_t) mtime);
+        snprintf(ck, PDF_CHECKSUM_SIZE, "%"
+PRIu64
+"_%"
+PRIu64
+, (uint64_t) size,(uint64_t) mtime);
    } else {
         switch (fe) {
             case FE_FAIL:
@@ -224,7 +228,7 @@ PdfDocument *refMemStreamPdfDocument(cha
         free(checksum);
     }
     if (pdf_doc->doc == NULL) {
-        docmemstream = new MemStream( docstream,0,streamsize, obj.initNull() );
+        docmemstream = new MemStream( docstream,0,streamsize, Object(objNull) );
         doc = new PDFDoc(docmemstream); /* takes ownership of docmemstream */
         pdf_doc->pc++;
         if (!doc->isOk() || !doc->okToPrint()) {
@@ -408,9 +412,8 @@ static void copyArray(PDF pdf, PdfDocume
     Object obj1;
     pdf_begin_array(pdf);
     for (i = 0, l = array->getLength(); i < l; ++i) {
-        array->getNF(i, &obj1);
+        obj1 = array->getNF(i);
         copyObject(pdf, pdf_doc, &obj1);
-        obj1.free();
     }
     pdf_end_array(pdf);
 }
@@ -422,9 +425,8 @@ static void copyDict(PDF pdf, PdfDocumen
     pdf_begin_dict(pdf);
     for (i = 0, l = dict->getLength(); i < l; ++i) {
         copyName(pdf, dict->getKey(i));
-        dict->getValNF(i, &obj1);
+        obj1 = dict->getValNF(i);
         copyObject(pdf, pdf_doc, &obj1);
-        obj1.free();
     }
     pdf_end_dict(pdf);
 }
@@ -510,13 +512,12 @@ static void writeRefs(PDF pdf, PdfDocume
     PDFDoc *doc = pdf_doc->doc;
     xref = doc->getXRef();
     for (r = pdf_doc->inObjList; r != NULL;) {
-        xref->fetch(r->ref.num, r->ref.gen, &obj1);
+        obj1 = xref->fetch(r->ref.num, r->ref.gen);
         if (obj1.isStream())
             pdf_begin_obj(pdf, r->num, OBJSTM_NEVER);
         else
             pdf_begin_obj(pdf, r->num, 2);
         copyObject(pdf, pdf_doc, &obj1);
-        obj1.free();
         pdf_end_obj(pdf);
         n = r->next;
         delete r;
@@ -740,7 +741,7 @@ void write_epdf(PDF pdf, image_dict * id
     catalog = doc->getCatalog();
     page = catalog->getPage(img_pagenum(idict));
     pageref = catalog->getPageRef(img_pagenum(idict));
-    doc->getXRef()->fetch(pageref->num, pageref->gen, &pageobj);
+    pageobj = doc->getXRef()->fetch(pageref->num, pageref->gen);
     pageDict = pageobj.getDict();
     /* write the Page header */
     pdf_begin_obj(pdf, img_objnum(idict), OBJSTM_NEVER);
@@ -757,12 +758,11 @@ void write_epdf(PDF pdf, image_dict * id
         pdf_dict_add_int(pdf, "PTEX.PageNumber", (int) img_pagenum(idict));
     }
     if ((suppress_optional_info & 8) == 0) {
-        doc->getDocInfoNF(&obj1);
+        obj1 = doc->getDocInfoNF();
         if (obj1.isRef()) {
             /* the info dict must be indirect (PDF Ref p. 61) */
             pdf_dict_add_ref(pdf, "PTEX.InfoDict", addInObj(pdf, pdf_doc, obj1.getRef()));
         }
-        obj1.free();
     }
     if (img_is_bbox(idict)) {
         bbox[0] = sp2bp(img_bbox(idict)[0]);
@@ -788,19 +788,17 @@ void write_epdf(PDF pdf, image_dict * id
         Now all relevant parts of the Page dictionary are copied. Metadata validity
         check is needed(as a stream it must be indirect).
     */
-    pageDict->lookupNF("Metadata", &obj1);
+    obj1 = pageDict->lookupNF("Metadata");
     if (!obj1.isNull() && !obj1.isRef())
         formatted_warning("pdf inclusion","/Metadata must be indirect object");
-    obj1.free();
     /* copy selected items in Page dictionary */
     for (i = 0; pagedictkeys[i] != NULL; i++) {
-        pageDict->lookupNF(pagedictkeys[i], &obj1);
+        obj1 = pageDict->lookupNF(pagedictkeys[i]);
         if (!obj1.isNull()) {
             pdf_add_name(pdf, pagedictkeys[i]);
             /* preserves indirection */
             copyObject(pdf, pdf_doc, &obj1);
         }
-        obj1.free();
     }
     /*
         If there are no Resources in the Page dict of the embedded page,
@@ -808,32 +806,28 @@ void write_epdf(PDF pdf, image_dict * id
         PDF file, climbing up the tree until the Resources are found.
         (This fixes a problem with Scribus 1.3.3.14.)
     */
-    pageDict->lookupNF("Resources", &obj1);
+    obj1 = pageDict->lookupNF("Resources");
     if (obj1.isNull()) {
         op1 = &pagesobj1;
         op2 = &pagesobj2;
-        pageDict->lookup("Parent", op1);
+        *op1 = pageDict->lookup("Parent");
         while (op1->isDict()) {
-            obj1.free();
-            op1->dictLookupNF("Resources", &obj1);
+            obj1 = op1->dictLookupNF("Resources");
             if (!obj1.isNull()) {
                 pdf_add_name(pdf, "Resources");
                 copyObject(pdf, pdf_doc, &obj1);
                 break;
             }
-            op1->dictLookup("Parent", op2);
+            *op2 = op1->dictLookup("Parent");
             optmp = op1;
             op1 = op2;
             op2 = optmp;
-            op2->free();
         };
         if (!op1->isDict())
             formatted_warning("pdf inclusion","Page /Resources missing");
-        op1->free();
     }
-    obj1.free();
     /* Write the Page contents. */
-    page->getContents(&contents);
+    contents = page->getContents();
     if (contents.isStream()) {
         /*
             Variant A: get stream and recompress under control of \pdfcompresslevel
@@ -844,27 +838,23 @@ void write_epdf(PDF pdf, image_dict * id
 
             Variant B: copy stream without recompressing
         */
-        contents.streamGetDict()->lookup("F", &obj1);
+        obj1 = contents.streamGetDict()->lookup("F");
         if (!obj1.isNull()) {
             normal_error("pdf inclusion","unsupported external stream");
         }
-        obj1.free();
-        contents.streamGetDict()->lookup("Length", &obj1);
+        obj1 = contents.streamGetDict()->lookup("Length");
         pdf_add_name(pdf, "Length");
         copyObject(pdf, pdf_doc, &obj1);
-        obj1.free();
-        contents.streamGetDict()->lookup("Filter", &obj1);
+        obj1 = contents.streamGetDict()->lookup("Filter");
         if (!obj1.isNull()) {
             pdf_add_name(pdf, "Filter");
             copyObject(pdf, pdf_doc, &obj1);
-            obj1.free();
-            contents.streamGetDict()->lookup("DecodeParms", &obj1);
+            obj1 = contents.streamGetDict()->lookup("DecodeParms");
             if (!obj1.isNull()) {
                 pdf_add_name(pdf, "DecodeParms");
                 copyObject(pdf, pdf_doc, &obj1);
             }
         }
-        obj1.free();
         pdf_end_dict(pdf);
         pdf_begin_stream(pdf);
         copyStreamStream(pdf, contents.getStream()->getUndecodedStream());
@@ -875,8 +865,8 @@ void write_epdf(PDF pdf, image_dict * id
         pdf_end_dict(pdf);
         pdf_begin_stream(pdf);
         for (i = 0, l = contents.arrayGetLength(); i < l; ++i) {
-            copyStreamStream(pdf, (contents.arrayGet(i, &obj1))->getStream());
-            obj1.free();
+            obj1 = contents.arrayGet(i);
+            copyStreamStream(pdf, obj1.getStream());
             if (i < (l - 1)) {
                 /*
                     Put a space between streams to be on the safe side (streams
@@ -897,8 +887,6 @@ void write_epdf(PDF pdf, image_dict * id
     }
     /* write out all indirect objects */
     writeRefs(pdf, pdf_doc);
-    contents.free();
-    pageobj.free();
     /*
         unrefPdfDocument() must come after contents.free() and pageobj.free()!
         TH: The next line makes repeated pdf inclusion unacceptably slow

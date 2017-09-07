$NetBSD: patch-filter_pdf.cxx,v 1.1 2017/09/07 11:24:29 prlw1 Exp $

support poppler-0.58
https://bugs.linuxfoundation.org/show_bug.cgi?id=1408

--- filter/pdf.cxx.orig	2017-08-15 18:29:57.000000000 +0000
+++ filter/pdf.cxx
@@ -129,64 +129,125 @@ extern "C" void pdf_prepend_stream(pdf_t
     Object array;
     Ref r;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj = xref->fetch(pageref->num, pageref->gen);
+#else
     xref->fetch(pageref->num, pageref->gen, &pageobj);
-    if (!pageobj.isDict() || !pageobj.dictLookupNF("Contents", &contents)) {
+#endif
+    if (!pageobj.isDict() ||
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        (contents = pageobj.dictLookupNF("Contents")).isNull()
+#else
+        !pageobj.dictLookupNF("Contents", &contents)
+#endif
+    ) {
         fprintf(stderr, "Error: malformed pdf\n");
         return;
     }
 
-    if (contents.isRef())
+    if (contents.isRef()) {
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        contents = xref->fetch(contents.getRefNum(), contents.getRefGen());
+#else
         xref->fetch(contents.getRefNum(), contents.getRefGen(), &contents);
+#endif
+    }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    (void) lenobj;
+    dict = Object(new Dict(xref));
+    dict.dictSet("Length", Object(static_cast<int>(len)));
+    stream = Object(static_cast<Stream *>(new MemStream(buf, 0, len, std::move(dict))));
+#else
     lenobj.initInt(len);
     dict.initDict(xref);
     dict.dictSet("Length", &lenobj);
     stream.initStream(new MemStream(buf, 0, len, &dict));
+#endif
 
     r = xref->addIndirectObject(&stream);
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    streamrefobj = Object(r.num, r.gen);
+#else
     streamrefobj.initRef(r.num, r.gen);
+#endif
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    array = Object(new Array(xref));
+    array.arrayAdd(std::move(streamrefobj));
+#else
     array.initArray(xref);
     array.arrayAdd(&streamrefobj);
+#endif
 
     if (contents.isStream()) {
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        contents = pageobj.dictLookupNF("Contents"); // streams must be indirect, i.e. not fetch()-ed
+        array.arrayAdd(std::move(contents));
+#else
         pageobj.dictLookupNF("Contents", &contents); // streams must be indirect, i.e. not fetch()-ed
         array.arrayAdd(&contents);
+#endif
     }
     else if (contents.isArray()) {
         int i, len = contents.arrayGetLength();
         Object obj;
         for (i = 0; i < len; i++) {
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+            obj = contents.arrayGetNF(i);
+            array.arrayAdd(std::move(obj));
+#else
             contents.arrayGetNF(i, &obj);
             array.arrayAdd(&obj);
+#endif
         }
     }
     else
         fprintf(stderr, "Error: malformed pdf\n");
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj.dictSet("Contents", std::move(array));
+#else
     pageobj.dictSet("Contents", &array);
+#endif
 
     xref->setModifiedObject(&pageobj, *pageref);
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     pageobj.free();
+#endif
 }
 
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+static Object name_object(const char *s)
+{
+    return Object(new GooString(s));
+}
+#else
 static Object * name_object(const char *s)
 {
     Object *o = new Object();
     o->initName((char *)s);
     return o;
 }
+#endif
 
 /*
  * Create new PDF integer type object.
  */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+static Object int_object(int i)
+{
+    return Object(i);
+}
+#else
 static Object * int_object(int i)
 {
     Object *o = new Object();
     o->initInt(i);
     return o;
 }
+#endif
 
 static Object * get_resource_dict(XRef *xref,
                                   Dict *pagedict,
@@ -196,21 +257,36 @@ static Object * get_resource_dict(XRef *
     Object res;
 
     /* TODO resource dict can also be inherited */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    res = pagedict->lookupNF("Resources");
+    if (res.isNull())
+#else
     if (!pagedict->lookupNF("Resources", &res))
+#endif
         return NULL;
 
     if (res.isRef()) {
         *resref = res.getRef();
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        *resdict = xref->fetch(resref->num, resref->gen);
+#else
         xref->fetch(resref->num, resref->gen, resdict);
+#endif
     }
     else if (res.isDict()) {
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        *resdict = res.copy();
+#else
         res.copy(resdict);
+#endif
         resref->num = 0;
     }
     else
         resdict = NULL;
 
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     res.free();
+#endif
     return resdict;
 }
 
@@ -226,7 +302,11 @@ extern "C" void pdf_add_type1_font(pdf_t
     Object resdict;
     Ref resref;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj = xref->fetch(pageref->num, pageref->gen);
+#else
     xref->fetch(pageref->num, pageref->gen, &pageobj);
+#endif
     if (!pageobj.isDict()) {
         fprintf(stderr, "Error: malformed pdf\n");
         return;
@@ -234,21 +314,35 @@ extern "C" void pdf_add_type1_font(pdf_t
 
     if (!get_resource_dict(xref, pageobj.getDict(), &resdict, &resref)) {
         fprintf(stderr, "Error: malformed pdf\n");
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
         pageobj.free();
+#endif
         return;
     }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    font = Object(new Dict(xref));
+#else
     font.initDict(xref);
+#endif
     font.dictSet("Type", name_object("Font"));
     font.dictSet("Subtype", name_object("Type1"));
     font.dictSet("BaseFont", name_object(name));
     xref->addIndirectObject(&font);
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    fonts = resdict.dictLookupNF("Font");
+#else
     resdict.dictLookupNF("Font", &fonts);
+#endif
     if (fonts.isNull()) {
         /* Create new font dic obj in page's resources */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        resdict.dictSet("Font", Object(new Dict(xref)));
+#else
         fonts.initDict(xref);
         resdict.dictSet("Font", &fonts);
+#endif
     }
 
     Object *fonts_dic;
@@ -259,7 +353,11 @@ extern "C" void pdf_add_type1_font(pdf_t
         fonts_dic = &fonts;
     } else if ( fonts.isRef() ) {
         /* "Font" resource is indirect reference object */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        dereferenced_obj = xref->fetch(fonts.getRefNum(), fonts.getRefGen());
+#else
         xref->fetch(fonts.getRefNum(), fonts.getRefGen(), &dereferenced_obj);
+#endif
         fonts_dic = &dereferenced_obj;
     }
 
@@ -269,7 +367,11 @@ extern "C" void pdf_add_type1_font(pdf_t
     }
 
     /* Add new entry to "Font" resource */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    fonts_dic->dictSet("bannertopdf-font", std::move(font));
+#else
     fonts_dic->dictSet("bannertopdf-font", &font);
+#endif
 
     /* Notify poppler about changes */
     if ( fonts.isRef() ) {
@@ -281,7 +383,9 @@ extern "C" void pdf_add_type1_font(pdf_t
     else
         xref->setModifiedObject(&resdict, resref);
 
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     pageobj.free();
+#endif
 }
 
 
@@ -293,23 +397,38 @@ static bool dict_lookup_rect(Object *dic
     Array *array;
     int i;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    o = dict->dictLookup(key);
+    if (o.isNull())
+#else
     if (!dict->dictLookup(key, &o))
+#endif
         return false;
 
     if (!o.isArray()) {
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
         o.free();
+#endif
         return false;
     }
 
     array = o.getArray();
     for (i = 0; i < 4; i++) {
         Object el;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        el = array->get(i);
+        if (el.isNum())
+            rect[i] = el.getNum();
+#else
         if (array->get(i, &el) && el.isNum())
             rect[i] = el.getNum();
         el.free();
+#endif
     }
 
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     o.free();
+#endif
     return i == 4;
 }
 
@@ -322,6 +441,15 @@ static void dict_set_rect(XRef *xref,
     Object array;
     int i;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    array = Object(new Array(xref));
+
+    for (i = 0; i < 4; i++) {
+        array.arrayAdd(Object(static_cast<double>(rect[i])));
+    }
+
+    dict->dictSet(key, std::move(array));
+#else
     array.initArray(xref);
 
     for (i = 0; i < 4; i++) {
@@ -331,6 +459,7 @@ static void dict_set_rect(XRef *xref,
     }
 
     dict->dictSet(key, &array);
+#endif
 }
 
 
@@ -361,7 +490,11 @@ extern "C" void pdf_resize_page (pdf_t *
     float mediabox[4] = { 0.0, 0.0, width, length };
     float old_mediabox[4];
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj = xref->fetch(pageref->num, pageref->gen);
+#else
     xref->fetch(pageref->num, pageref->gen, &pageobj);
+#endif
     if (!pageobj.isDict()) {
         fprintf(stderr, "Error: malformed pdf\n");
         return;
@@ -381,7 +514,9 @@ extern "C" void pdf_resize_page (pdf_t *
     dict_set_rect (xref, &pageobj, "BleedBox", mediabox);
 
     xref->setModifiedObject(&pageobj, *pageref);
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     pageobj.free();
+#endif
 }
 
 
@@ -394,21 +529,34 @@ extern "C" void pdf_duplicate_page (pdf_
     Object page, parentref, parent, kids, ref, countobj;
     int i;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    page = xref->fetch(pageref->num, pageref->gen);
+#else
     xref->fetch(pageref->num, pageref->gen, &page);
+#endif
     if (!page.isDict("Page")) {
         fprintf(stderr, "Error: malformed pdf (invalid Page object)\n");
         return;
     }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    parentref = page.dictLookupNF("Parent");
+    parent = parentref.fetch(xref);
+#else
     page.dictLookupNF("Parent", &parentref);
     parentref.fetch(xref, &parent);
+#endif
     if (!parent.isDict("Pages")) {
         fprintf(stderr, "Error: malformed pdf (Page.Parent must point to a "
                         "Pages object)\n");
         return;
     }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    kids = parent.dictLookup("Kids");
+#else
     parent.dictLookup("Kids", &kids);
+#endif
     if (!kids.isArray()) {
         fprintf(stderr, "Error: malformed pdf (Pages.Kids must be an array)\n");
         return;
@@ -420,14 +568,22 @@ extern "C" void pdf_duplicate_page (pdf_
     // the pages tree (not supported by major pdf implementations).
     for (i = 1; i < count; i++) {
         Ref r = xref->addIndirectObject(&page);
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        kids.arrayAdd(Object(r.num, r.gen));
+#else
         ref.initRef(r.num, r.gen);
         kids.arrayAdd(&ref);
         ref.free();
+#endif
     }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    parent.dictSet("Count", Object(count));
+#else
     countobj.initInt(count);
     parent.dictSet("Count", &countobj);
     countobj.free();
+#endif
 
     xref->setModifiedObject(&parent, parentref.getRef());
 }
@@ -523,7 +679,11 @@ extern "C" int pdf_fill_form(pdf_t *doc,
     }
     Object pageobj;
     Ref pageref = page->getRef();
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj = xref->fetch(pageref.num, pageref.gen);
+#else
     xref->fetch(pageref.num, pageref.gen, &pageobj);
+#endif
 
     const char *font_size = lookup_opt(opt, "banner-font-size");
     if ( ! font_size ) {
@@ -614,8 +774,12 @@ extern "C" int pdf_fill_form(pdf_t *doc,
 
         /* Modify field's appearance */
         Object appearance_obj;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        field_obj->getDict()->set("DA", Object(appearance));
+#else
         appearance_obj.initString(appearance);
         field_obj->getDict()->set("DA", &appearance_obj);
+#endif
 
         /*
          * Create /AP - entry stuff.
@@ -653,7 +817,11 @@ extern "C" int pdf_fill_form(pdf_t *doc,
         appearance_stream->append("EMC\n");
 
         Object appearance_stream_dic;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        appearance_stream_dic = Object(new Dict(xref));
+#else
         appearance_stream_dic.initDict(xref);
+#endif
 
         /*
          * Appearance stream dic.
@@ -663,12 +831,46 @@ extern "C" int pdf_fill_form(pdf_t *doc,
         appearance_stream_dic.dictSet("Type", name_object("XObject"));
         appearance_stream_dic.dictSet("Subtype", name_object("Form"));
         appearance_stream_dic.dictSet("FormType", int_object(1));
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        appearance_stream_dic.dictSet("Resources", Object(resref.num, resref.gen));
+#else
         Object obj_ref_x;
         obj_ref_x.initRef(resref.num, resref.gen);
         appearance_stream_dic.dictSet("Resources", &obj_ref_x);
+#endif
 
         /* BBox array: TODO. currently out of the head. */
         Object array;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        array = Object(new Array(xref));
+        array.arrayAdd(Object(0.0));
+        array.arrayAdd(Object(0.0));
+        array.arrayAdd(Object(237.0));
+        array.arrayAdd(Object(25.0));
+
+        appearance_stream_dic.dictSet("BBox", std::move(array));
+        appearance_stream_dic.dictSet("Length", Object(appearance_stream->getLength()));
+
+        MemStream *mem_stream = new MemStream(appearance_stream->getCString(),
+                0, appearance_stream->getLength(), std::move(appearance_stream_dic));
+
+        /* Make obj stream */
+        Object stream = Object(static_cast<Stream *>(mem_stream));
+
+        Ref r = xref->addIndirectObject(&stream);
+
+        /* Update Xref table */
+        Object obj_ref = Object(r.num, r.gen);
+
+        /*
+         * Fill Annotation's appearance streams dic /AP
+         * See: 8.4.4 Appearance Streams
+         */
+        Object appearance_streams_dic = Object(new Dict(xref));
+        appearance_streams_dic.dictSet("N", std::move(obj_ref));
+
+        field_obj->getDict()->set("AP", std::move(appearance_streams_dic));
+#else
         array.initArray(xref);
         Object el;
         el.initReal(0);
@@ -705,6 +907,7 @@ extern "C" int pdf_fill_form(pdf_t *doc,
         appearance_streams_dic.dictSet("N", &obj_ref);
 
         field_obj->getDict()->set("AP", &appearance_streams_dic);
+#endif
 
         /* Notify poppler about changes */
         xref->setModifiedObject(field_obj, field_ref);
@@ -721,24 +924,38 @@ extern "C" int pdf_fill_form(pdf_t *doc,
      * OpenOffice - by default sets it to 'true'.
      */
     Object *obj_form = catalog->getAcroForm();
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    obj_form->dictSet("NeedAppearances", Object(gFalse));
+#else
     Object obj1;
     obj1.initBool(gFalse);
     obj_form->dictSet("NeedAppearances", &obj1);
+#endif
+
     /* Add AccroForm as indirect obj */
     Ref ref_form = xref->addIndirectObject(obj_form);
 
     /*
      * So update Catalog object.
      */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    Object catObj = xref->getCatalog();
+#else
     Object* catObj = new Object();
     catObj = xref->getCatalog(catObj);
+#endif
     Ref catRef;
     catRef.gen = xref->getRootGen();
     catRef.num = xref->getRootNum();
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    catObj.dictSet("AcroForm", Object(ref_form.num, ref_form.gen));
+    xref->setModifiedObject(&catObj, catRef);
+#else
     Object obj2;
     obj2.initRef(ref_form.num, ref_form.gen);
     catObj->dictSet("AcroForm", &obj2);
     xref->setModifiedObject(catObj, catRef);
+#endif
 
     /* Success */
     return 1;
@@ -780,7 +997,11 @@ static int pdf_embed_font(pdf_t *doc,
 
     /* Font dictionary object for embeded font */
     Object f_dic;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    f_dic = Object(new Dict(xref));
+#else
     f_dic.initDict(xref);
+#endif
     f_dic.dictSet("Type", name_object("Font"));
 
     /* Stream lenght */
@@ -798,12 +1019,18 @@ static int pdf_embed_font(pdf_t *doc,
     }
 
     /* Create memory stream font. Add it to font dic. */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    MemStream *mem_stream = new MemStream(font_stream->getCString(),
+            0, outlen, std::move(f_dic));
+    Object stream = Object(static_cast<Stream *>(mem_stream));
+#else
     MemStream *mem_stream = new MemStream(font_stream->getCString(),
             0, outlen, &f_dic);
 
     /* Make obj stream */
     Object stream;
     stream.initStream(mem_stream);
+#endif
 
     Ref r;
 
@@ -813,7 +1040,11 @@ static int pdf_embed_font(pdf_t *doc,
     /* Get page object */
     Object pageobj;
     Ref pageref = page->getRef();
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    pageobj = xref->fetch(pageref.num, pageref.gen);
+#else
     xref->fetch(pageref.num, pageref.gen, &pageobj);
+#endif
     if (!pageobj.isDict()) {
         fprintf(stderr, "Error: malformed pdf.\n");
         return 0;
@@ -825,18 +1056,29 @@ static int pdf_embed_font(pdf_t *doc,
     Object *ret = get_resource_dict(xref, pageobj.getDict(), &resdict, &resref);
     if ( !ret ) {
         fprintf(stderr, "Error: malformed pdf\n");
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
         pageobj.free();
+#endif
         return 0;
     }
 
     /* Dictionary for all fonts in page's resources */
     Object fonts;
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    fonts = resdict.dictLookupNF("Font");
+#else
     resdict.dictLookupNF("Font", &fonts);
+#endif
     if (fonts.isNull()) {
         /* Create new one, if doesn't exists */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        resdict.dictSet("Font", Object(new Dict(xref)));
+        fonts = resdict.dictLookupNF("Font");
+#else
         fonts.initDict(xref);
         resdict.dictSet("Font", &fonts);
+#endif
         fprintf(stderr, "Create new font dict in page's resources.\n");
     }
 
@@ -866,7 +1108,11 @@ static int pdf_embed_font(pdf_t *doc,
 
     /* r - cid resource dic */
     Object font_res_obj_ref;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    font_res_obj_ref = Object(r.num, r.gen);
+#else
     font_res_obj_ref.initRef(r.num, r.gen);
+#endif
 
     Object *fonts_dic;
     Object dereferenced_obj;
@@ -876,7 +1122,11 @@ static int pdf_embed_font(pdf_t *doc,
         fonts_dic = &fonts;
     } else if ( fonts.isRef() ) {
         /* "Font" resource is indirect reference object */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        dereferenced_obj = xref->fetch(fonts.getRefNum(), fonts.getRefGen());
+#else
         xref->fetch(fonts.getRefNum(), fonts.getRefGen(), &dereferenced_obj);
+#endif
         fonts_dic = &dereferenced_obj;
     }
 
@@ -886,7 +1136,11 @@ static int pdf_embed_font(pdf_t *doc,
     }
 
     /* Add to fonts dic new font */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    fonts_dic->dictSet("stanv_font", std::move(font_res_obj_ref));
+#else
     fonts_dic->dictSet("stanv_font", &font_res_obj_ref);
+#endif
 
     /* Notify poppler about changes in fonts dic */
     if ( fonts.isRef() ) {
@@ -897,7 +1151,9 @@ static int pdf_embed_font(pdf_t *doc,
     xref->setModifiedObject(&resdict, resref);
     fprintf(stderr, "Resource dict was changed.\n");
 
+#if POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR < 58
     pageobj.free();
+#endif
 
     /* Success */
     return 1;
@@ -1104,8 +1360,12 @@ static Object *make_fontdescriptor_dic(
     XRef *xref = doc->getXRef();
 
     /* Font dictionary for embeded font */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    Object *dic = new Object(new Dict(xref));
+#else
     Object *dic = new Object();
     dic->initDict(xref);
+#endif
 
     dic->dictSet("Type", name_object("FontDescriptor"));
     dic->dictSet(
@@ -1119,6 +1379,15 @@ static Object *make_fontdescriptor_dic(
     dic->dictSet("StemV", int_object(fdes->stemV));
 
     /* FontBox array */
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    Object array = Object(new Array(xref));
+    array.arrayAdd(Object(static_cast<double>(fdes->bbxmin)));
+    array.arrayAdd(Object(static_cast<double>(fdes->bbymin)));
+    array.arrayAdd(Object(static_cast<double>(fdes->bbxmax)));
+    array.arrayAdd(Object(static_cast<double>(fdes->bbymax)));
+
+    dic->dictSet("FontBBox", std::move(array));
+#else
     Object array;
     array.initArray(xref);
 
@@ -1137,6 +1406,7 @@ static Object *make_fontdescriptor_dic(
     array.arrayAdd(&el);
 
     dic->dictSet("FontBBox", &array);
+#endif
 
     if (fdes->xHeight) {
         dic->dictSet("XHeight", int_object(fdes->xHeight));
@@ -1149,20 +1419,34 @@ static Object *make_fontdescriptor_dic(
     if (fdes->panose) {
         /* Font dictionary for embeded font */
         Object style_dic;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        style_dic = Object(new Dict(xref));
+#else
         style_dic.initDict(xref);
+#endif
+
+        GooString *panose_str = new GooString(fdes->panose, 12);
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        style_dic.dictSet("Panose", Object(panose_str));
 
+        dic->dictSet("Style", std::move(style_dic));
+#else
         Object panose;
 
-        GooString *panose_str = new GooString(fdes->panose, 12);
         panose.initString(panose_str);
         style_dic.dictSet("Panose", &panose);
 
         dic->dictSet("Style", &style_dic);
+#endif
     }
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    dic->dictSet(emb_pdf_get_fontfile_key(emb), Object(fontfile_obj_ref.num, fontfile_obj_ref.gen));
+#else
     Object ref_obj;
     ref_obj.initRef(fontfile_obj_ref.num, fontfile_obj_ref.gen);
     dic->dictSet(emb_pdf_get_fontfile_key(emb), &ref_obj);
+#endif
 
     return dic;
 }
@@ -1181,8 +1465,12 @@ static Object *make_font_dic(
     /* Get XREF table */
     XRef *xref = doc->getXRef();
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    Object *dic = new Object(new Dict(xref));
+#else
     Object *dic = new Object();
     dic->initDict(xref);
+#endif
 
     dic->dictSet("Type", name_object("Font"));
     dic->dictSet(
@@ -1192,15 +1480,23 @@ static Object *make_font_dic(
             "BaseFont",
             name_object(copyString(emb_pdf_escape_name(fdes->fontname,-1))));
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    dic->dictSet("FontDescriptor", Object(fontdescriptor_obj_ref.num, fontdescriptor_obj_ref.gen));
+#else
     Object ref_obj;
     ref_obj.initRef(fontdescriptor_obj_ref.num, fontdescriptor_obj_ref.gen);
     dic->dictSet("FontDescriptor", &ref_obj);
+#endif
 
     if ( emb->plan & EMB_A_MULTIBYTE ) {
         assert(fwid->warray);
 
         Object CIDSystemInfo_dic;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        CIDSystemInfo_dic = Object(new Dict(xref));
+#else
         CIDSystemInfo_dic.initDict(xref);
+#endif
 
         Object registry;
         Object ordering;
@@ -1208,16 +1504,28 @@ static Object *make_font_dic(
         GooString *str;
 
         str = new GooString(copyString(fdes->registry));
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        CIDSystemInfo_dic.dictSet("Registry", Object(str));
+#else
         registry.initString(str);
         CIDSystemInfo_dic.dictSet("Registry", &registry);
+#endif
 
         str = new GooString(copyString(fdes->ordering));
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        CIDSystemInfo_dic.dictSet("Ordering", Object(str));
+#else
         ordering.initString(str);
         CIDSystemInfo_dic.dictSet("Ordering", &ordering);
+#endif
 
         CIDSystemInfo_dic.dictSet("Supplement", int_object(fdes->supplement));
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+        dic->dictSet("CIDSystemInfo", std::move(CIDSystemInfo_dic));
+#else
         dic->dictSet("CIDSystemInfo", &CIDSystemInfo_dic);
+#endif
 
         dic->dictSet("DW", int_object(fwid->default_width));
     }
@@ -1249,8 +1557,12 @@ static Object *make_cidfont_dic(
     /* Get XREF table */
     XRef *xref = doc->getXRef();
 
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    Object *dic = new Object(new Dict(xref));
+#else
     Object *dic = new Object();
     dic->initDict(xref);
+#endif
 
     dic->dictSet("Type", name_object("Font"));
     dic->dictSet("Subtype", name_object("Type0"));
@@ -1267,13 +1579,24 @@ static Object *make_cidfont_dic(
     dic->dictSet("Encoding", name_object(copyString(encoding)));
 
     Object obj;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    obj = Object(fontdescriptor_obj_ref.num, fontdescriptor_obj_ref.gen);
+#else
     obj.initRef(fontdescriptor_obj_ref.num, fontdescriptor_obj_ref.gen);
+#endif
 
     Object array;
+#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 58
+    array = Object(new Array(xref));
+    array.arrayAdd(std::move(obj));
+
+    dic->dictSet("DescendantFonts", std::move(array));
+#else
     array.initArray(xref);
     array.arrayAdd(&obj);
 
     dic->dictSet("DescendantFonts", &array);
+#endif
 
     return dic;
 }

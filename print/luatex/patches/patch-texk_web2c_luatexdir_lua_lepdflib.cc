$NetBSD: patch-texk_web2c_luatexdir_lua_lepdflib.cc,v 1.1 2014/04/29 20:05:29 wiz Exp $

Use changes from luatex-0.79 to fix build against poppler-0.26.

--- texk/web2c/luatexdir/lua/lepdflib.cc.orig	2013-04-05 10:58:37.000000000 +0000
+++ texk/web2c/luatexdir/lua/lepdflib.cc
@@ -48,25 +48,26 @@ static const char *ErrorCodeNames[] = { 
 
 //**********************************************************************
 
-#define M_Annot            "Annot"
-#define M_Annots           "Annots"
-#define M_Array            "Array"
-#define M_Catalog          "Catalog"
-#define M_Dict             "Dict"
-#define M_EmbFile          "EmbFile"
-#define M_FileSpec         "FileSpec"
-#define M_GooString        "GooString"
-#define M_LinkDest         "LinkDest"
-#define M_Link             "Link"
-#define M_Links            "Links"
-#define M_Object           "Object"
-#define M_Page             "Page"
-#define M_PDFDoc           "PDFDoc"
-#define M_PDFRectangle     "PDFRectangle"
-#define M_Ref              "Ref"
-#define M_Stream           "Stream"
-#define M_XRefEntry        "XRefEntry"
-#define M_XRef             "XRef"
+#define M_Annot            "epdf.Annot" /* ls-hh: epdf.* gives better protection in registry */
+#define M_Annots           "epdf.Annots"
+#define M_Array            "epdf.Array"
+#define M_Catalog          "epdf.Catalog"
+#define M_Dict             "epdf.Dict"
+#define M_EmbFile          "epdf.EmbFile"
+#define M_FileSpec         "epdf.FileSpec"
+#define M_GooString        "epdf.GooString"
+#define M_LinkDest         "epdf.LinkDest"
+#define M_Link             "epdf.Link"
+#define M_Links            "epdf.Links"
+#define M_Object           "epdf.Object"
+#define M_Page             "epdf.Page"
+#define M_PDFDoc           "epdf.PDFDoc"
+#define M_PDFRectangle     "epdf.PDFRectangle"
+#define M_Ref              "epdf.Ref"
+#define M_Stream           "epdf.Stream"
+#define M_StructTreeRoot   "epdf.StructTreeRoot"
+#define M_XRefEntry        "epdf.XRefEntry"
+#define M_XRef             "epdf.XRef"
 
 //**********************************************************************
 
@@ -96,6 +97,7 @@ new_poppler_userdata(Page);
 new_poppler_userdata(PDFRectangle);
 new_poppler_userdata(Ref);
 new_poppler_userdata(Stream);
+new_poppler_userdata(StructTreeRoot);
 new_poppler_userdata(XRef);
 
 //**********************************************************************
@@ -573,7 +575,11 @@ static int m_Catalog_getPageRef(lua_Stat
 
 m_poppler_get_GOOSTRING(Catalog, getBaseURI);
 m_poppler_get_GOOSTRING(Catalog, readMetadata);
+#ifdef GETSTRUCTTREEROOT_RETURNS_OBJECT
 m_poppler_get_poppler(Catalog, Object, getStructTreeRoot);
+#else
+m_poppler_get_poppler(Catalog, StructTreeRoot, getStructTreeRoot);
+#endif
 
 static int m_Catalog_findPage(lua_State * L)
 {
@@ -2146,14 +2152,22 @@ static int m_PDFDoc_readMetadata(lua_Sta
 
 static int m_PDFDoc_getStructTreeRoot(lua_State * L)
 {
+#ifdef GETSTRUCTTREEROOT_RETURNS_OBJECT
     Object *obj;
+#else
+    StructTreeRoot *obj;
+#endif
     udstruct *uin, *uout;
     uin = (udstruct *) luaL_checkudata(L, 1, M_PDFDoc);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     if (((PdfDocument *) uin->d)->doc->getCatalog()->isOk()) {
         obj = ((PdfDocument *) uin->d)->doc->getStructTreeRoot();
+#ifdef GETSTRUCTTREEROOT_RETURNS_OBJECT
         uout = new_Object_userdata(L);
+#else
+        uout = new_StructTreeRoot_userdata(L);
+#endif
         uout->d = obj;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -2617,6 +2631,15 @@ static const struct luaL_Reg XRefEntry_m
 
 //**********************************************************************
 
+#ifdef LuajitTeX
+#define setfuncs_meta(type)                 \
+    luaL_newmetatable(L, M_##type);         \
+    lua_pushvalue(L, -1);                   \
+    lua_setfield(L, -2, "__index");         \
+    lua_pushstring(L, "no user access");    \
+    lua_setfield(L, -2, "__metatable");     \
+    luaL_register(L, NULL, type##_m)
+#else
 #define setfuncs_meta(type)                 \
     luaL_newmetatable(L, M_##type);         \
     lua_pushvalue(L, -1);                   \
@@ -2624,6 +2647,7 @@ static const struct luaL_Reg XRefEntry_m
     lua_pushstring(L, "no user access");    \
     lua_setfield(L, -2, "__metatable");     \
     luaL_setfuncs(L, type##_m, 0)
+#endif
 
 int luaopen_epdf(lua_State * L)
 {
@@ -2646,6 +2670,10 @@ int luaopen_epdf(lua_State * L)
     setfuncs_meta(XRef);
     setfuncs_meta(XRefEntry);
 
+#ifdef LuajitTeX
+    luaL_register(L, "epdf", epdflib_f);
+#else
     luaL_newlib(L, epdflib_f);
+#endif
     return 1;
 }

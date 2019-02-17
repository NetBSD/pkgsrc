$NetBSD: patch-texk_web2c_luatexdir_lua_lepdflib.cc,v 1.8 2019/02/17 11:17:37 tnn Exp $

--- texk/web2c/luatexdir/lua/lepdflib.cc.orig	2018-02-14 14:44:38.000000000 +0000
+++ texk/web2c/luatexdir/lua/lepdflib.cc
@@ -221,6 +221,7 @@ static int l_new_Attribute(lua_State * L
     const char *n;
     int nlen;
     udstruct *uobj, *uout;
+    GooString *gs;
 
     if (lua_type(L,1)==LUA_TNUMBER) {
        uobj = (udstruct *) luaL_checkudata(L, 2, M_Object);
@@ -240,7 +241,8 @@ static int l_new_Attribute(lua_State * L
        if (uobj->pd != NULL && uobj->pd->pc != uobj->pc)
           pdfdoc_changed_error(L);
        uout = new_Attribute_userdata(L);
-       uout->d = new Attribute(n, nlen, (Object *)uobj->d);
+       gs = new GooString(n, nlen);
+       uout->d = new Attribute(std::move(*gs), (Object *)uobj->d);
        uout->atype = ALLOC_LEPDF;
        uout->pc = uobj->pc;
        uout->pd = uobj->pd;
@@ -439,7 +441,7 @@ static int l_new_Object(lua_State * L)
       break;
     case 1:
       if (lua_isboolean (L,1)) {
-	uout->d = new Object(lua_toboolean(L, 1)? gTrue : gFalse);
+	uout->d = new Object(lua_toboolean(L, 1)? true : false);
 	uout->atype = ALLOC_LEPDF;
 	uout->pc = 0;
 	uout->pd = NULL;
@@ -591,7 +593,7 @@ static const struct luaL_Reg epdflib_f[]
 #define m_poppler_get_poppler(in, out, function)               \
 static int m_##in##_##function(lua_State * L)                  \
 {                                                              \
-    out *o;                                                    \
+    const out *o;                                              \
     udstruct *uin, *uout;                                      \
     uin = (udstruct *) luaL_checkudata(L, 1, M_##in);          \
     if (uin->pd != NULL && uin->pd->pc != uin->pc)             \
@@ -599,7 +601,7 @@ static int m_##in##_##function(lua_State
     o = ((in *) uin->d)->function();                           \
     if (o != NULL) {                                           \
         uout = new_##out##_userdata(L);                        \
-        uout->d = o;                                           \
+        uout->d = const_cast<out *>(o);                        \
         uout->pc = uin->pc;                                    \
         uout->pd = uin->pd;                                    \
     } else                                                     \
@@ -669,14 +671,14 @@ static int m_##in##_##function(lua_State
 #define m_poppler_get_GOOSTRING(in, function)                  \
 static int m_##in##_##function(lua_State * L)                  \
 {                                                              \
-    GooString *gs;                                             \
+    const GooString *gs;                                             \
     udstruct *uin;                                             \
     uin = (udstruct *) luaL_checkudata(L, 1, M_##in);          \
     if (uin->pd != NULL && uin->pd->pc != uin->pc)             \
         pdfdoc_changed_error(L);                               \
     gs = ((in *) uin->d)->function();                          \
     if (gs != NULL)                                            \
-        lua_pushlstring(L, gs->getCString(), gs->getLength()); \
+        lua_pushlstring(L, gs->c_str(), gs->getLength()); \
     else                                                       \
         lua_pushnil(L);                                        \
     return 1;                                                  \
@@ -911,7 +913,7 @@ static int m_Array_getString(lua_State *
     if (i > 0 && i <= len) {
         gs = new GooString();
         if (((Array *) uin->d)->getString(i - 1, gs))
-            lua_pushlstring(L, gs->getCString(), gs->getLength());
+            lua_pushlstring(L, gs->c_str(), gs->getLength());
         else
             lua_pushnil(L);
         delete gs;
@@ -1063,7 +1065,7 @@ static int m_Catalog_getJS(lua_State * L
     if (i > 0 && i <= len) {
         gs = ((Catalog *) uin->d)->getJS(i - 1);
         if (gs != NULL)
-            lua_pushlstring(L, gs->getCString(), gs->getLength());
+            lua_pushlstring(L, gs->c_str(), gs->getLength());
         else
             lua_pushnil(L);
         delete gs;
@@ -1125,7 +1127,7 @@ m_poppler_get_INT(Dict, getLength);
 
 static int m_Dict_add(lua_State * L)
 {
-    char *s;
+    const char *s;
     udstruct *uin, *uobj;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Dict);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
@@ -1378,7 +1380,7 @@ static int m_GooString__tostring(lua_Sta
     uin = (udstruct *) luaL_checkudata(L, 1, M_GooString);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    lua_pushlstring(L, ((GooString *) uin->d)->getCString(),
+    lua_pushlstring(L, ((GooString *) uin->d)->c_str(),
                     ((GooString *) uin->d)->getLength());
     return 1;
 }
@@ -1527,9 +1529,9 @@ static int m_Object_initBool(lua_State *
         pdfdoc_changed_error(L);
     luaL_checktype(L, 2, LUA_TBOOLEAN);
     if (lua_toboolean(L, 2) != 0)
-        *((Object *) uin->d) = Object(gTrue);
+        *((Object *) uin->d) = Object(true);
     else
-        *((Object *) uin->d) = Object(gFalse);
+        *((Object *) uin->d) = Object(false);
     return 0;
 }
 
@@ -1807,14 +1809,14 @@ static int m_Object_getNum(lua_State * L
 
 static int m_Object_getString(lua_State * L)
 {
-    GooString *gs;
+    const GooString *gs;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     if (((Object *) uin->d)->isString()) {
         gs = ((Object *) uin->d)->getString();
-        lua_pushlstring(L, gs->getCString(), gs->getLength());
+        lua_pushlstring(L, gs->c_str(), gs->getLength());
     } else
         lua_pushnil(L);
     return 1;
@@ -2051,7 +2053,7 @@ static int m_Object_dictAdd(lua_State * 
         pdfdoc_changed_error(L);
     if (!((Object *) uin->d)->isDict())
         luaL_error(L, "Object is not a Dict");
-    ((Object *) uin->d)->dictAdd(copyString(s), std::move(*((Object *) uobj->d)));
+    ((Object *) uin->d)->dictAdd(s, std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -2465,14 +2467,14 @@ m_PDFDoc_INT(getErrorCode);
 
 static int m_PDFDoc_getFileName(lua_State * L)
 {
-    GooString *gs;
+    const GooString *gs;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_PDFDoc);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     gs = ((PdfDocument *) uin->d)->doc->getFileName();
     if (gs != NULL)
-        lua_pushlstring(L, gs->getCString(), gs->getLength());
+        lua_pushlstring(L, gs->c_str(), gs->getLength());
     else
         lua_pushnil(L);
     return 1;
@@ -2553,7 +2555,7 @@ m_PDFDoc_INT(getNumPages);
 
 static int m_PDFDoc_readMetadata(lua_State * L)
 {
-    GooString *gs;
+    const GooString *gs;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_PDFDoc);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
@@ -2561,7 +2563,7 @@ static int m_PDFDoc_readMetadata(lua_Sta
     if (((PdfDocument *) uin->d)->doc->getCatalog()->isOk()) {
         gs = ((PdfDocument *) uin->d)->doc->readMetadata();
         if (gs != NULL)
-            lua_pushlstring(L, gs->getCString(), gs->getLength());
+            lua_pushlstring(L, gs->c_str(), gs->getLength());
         else
             lua_pushnil(L);
     } else
@@ -2571,7 +2573,7 @@ static int m_PDFDoc_readMetadata(lua_Sta
 
 static int m_PDFDoc_getStructTreeRoot(lua_State * L)
 {
-    StructTreeRoot *obj;
+    const StructTreeRoot *obj;
     udstruct *uin, *uout;
     uin = (udstruct *) luaL_checkudata(L, 1, M_PDFDoc);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
@@ -2579,7 +2581,7 @@ static int m_PDFDoc_getStructTreeRoot(lu
     if (((PdfDocument *) uin->d)->doc->getCatalog()->isOk()) {
         obj = ((PdfDocument *) uin->d)->doc->getStructTreeRoot();
         uout = new_StructTreeRoot_userdata(L);
-        uout->d = obj;
+        uout->d = const_cast<StructTreeRoot *>(obj);
         uout->pc = uin->pc;
         uout->pd = uin->pd;
     } else
@@ -3024,12 +3026,12 @@ m_poppler_get_GUINT(Attribute,getRevisio
 
 static int m_Attribute_setRevision(lua_State * L)
 {
-    Guint i;
+    unsigned int i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Attribute);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = (Guint) luaL_checkint(L, 2);
+    i = (unsigned int) luaL_checkint(L, 2);
     ((Attribute *) uin->d)->setRevision(i);
     return 0;
 }
@@ -3038,12 +3040,12 @@ m_poppler_get_BOOL(Attribute, isHidden);
 
 static int m_Attribute_setHidden(lua_State * L)
 {
-    GBool i;
+    bool i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Attribute);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = (GBool) lua_toboolean(L, 2);
+    i = (bool) lua_toboolean(L, 2);
     ((Attribute *) uin->d)->setHidden(i);
     return 0;
 }
@@ -3180,7 +3182,7 @@ static int m_StructElement_getParentRef(
 // Ref is false if the C++ functione return false
 static int m_StructElement_getPageRef(lua_State * L)
 {
-    GBool b;
+    bool b;
     Ref *r;
     udstruct *uin, *uout;
     uin = (udstruct *) luaL_checkudata(L, 1, M_StructElement);
@@ -3214,28 +3216,28 @@ static int m_StructElement_getTypeName(l
 
 static int m_StructElement_setRevision(lua_State * L)
 {
-    Guint i;
+    unsigned int i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_StructElement);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = (Guint) luaL_checkint(L, 2);
+    i = (unsigned int) luaL_checkint(L, 2);
     ((StructElement *) uin->d)->setRevision(i);
     return 0;
 }
 
 static int m_StructElement_getText(lua_State * L)
 {
-    GBool i;
+    bool i;
     GooString *gs;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_StructElement);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = (GBool) lua_toboolean(L, 2);
+    i = (bool) lua_toboolean(L, 2);
     gs =  ((StructElement *) uin->d)->getText(i);
     if (gs != NULL)
-        lua_pushlstring(L, gs->getCString(), gs->getLength());
+        lua_pushlstring(L, gs->c_str(), gs->getLength());
     else
         lua_pushnil(L);
     return 1;
@@ -3321,7 +3323,7 @@ static int m_StructElement_findAttribute
 {
     Attribute::Type t;
     Attribute::Owner o;
-    GBool g;
+    bool g;
     udstruct *uin, *uout;
     const Attribute *a;
     uin = (udstruct *) luaL_checkudata(L, 1, M_StructElement);
@@ -3329,7 +3331,7 @@ static int m_StructElement_findAttribute
         pdfdoc_changed_error(L);
     t = (Attribute::Type) luaL_checkint(L,1);
     o = (Attribute::Owner) luaL_checkint(L,2);
-    g = (GBool) lua_toboolean(L, 3);
+    g = (bool) lua_toboolean(L, 3);
     a = ((StructElement *) uin->d)->findAttribute(t,g,o);
 
     if (a!=NULL){

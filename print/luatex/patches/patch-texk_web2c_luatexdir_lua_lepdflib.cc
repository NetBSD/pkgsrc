$NetBSD: patch-texk_web2c_luatexdir_lua_lepdflib.cc,v 1.3 2017/12/31 00:41:19 markd Exp $

Add support for newer poppler's from ArchLinux

--- texk/web2c/luatexdir/lua/lepdflib.cc.orig	2017-03-11 01:04:06.000000000 +0000
+++ texk/web2c/luatexdir/lua/lepdflib.cc
@@ -538,7 +538,7 @@ static int m_##in##_##function(lua_State
         pdfdoc_changed_error(L);                               \
     uout = new_Object_userdata(L);                             \
     uout->d = new Object();                                    \
-    ((in *) uin->d)->function((Object *) uout->d);             \
+    *((Object *)uout->d) = ((in *) uin->d)->function();                  \
     uout->atype = ALLOC_LEPDF;                                 \
     uout->pc = uin->pc;                                        \
     uout->pd = uin->pd;                                        \
@@ -668,13 +668,11 @@ static const struct luaL_Reg Annots_m[]
 
 static int m_Array_incRef(lua_State * L)
 {
-    int i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Array);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = ((Array *) uin->d)->incRef();
-    lua_pushinteger(L, i);
+    lua_pushinteger(L, 1);
     return 1;
 }
 
@@ -685,8 +683,7 @@ static int m_Array_decRef(lua_State * L)
     uin = (udstruct *) luaL_checkudata(L, 1, M_Array);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = ((Array *) uin->d)->decRef();
-    lua_pushinteger(L, i);
+    lua_pushinteger(L, 1);
     return 1;
 }
 
@@ -702,7 +699,7 @@ static int m_Array_add(lua_State * L)
     if ((uin->pd != NULL && uin->pd->pc != uin->pc)
         || (uobj->pd != NULL && uobj->pd->pc != uobj->pc))
         pdfdoc_changed_error(L);
-    ((Array *) uin->d)->add(((Object *) uobj->d));
+    ((Array *) uin->d)->add(std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -718,7 +715,7 @@ static int m_Array_get(lua_State * L)
     if (i > 0 && i <= len) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Array *) uin->d)->get(i - 1, (Object *) uout->d);
+        *((Object *) uout->d) = ((Array *) uin->d)->get(i - 1);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -739,7 +736,7 @@ static int m_Array_getNF(lua_State * L)
     if (i > 0 && i <= len) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Array *) uin->d)->getNF(i - 1, (Object *) uout->d);
+        *((Object *) uout->d) = ((Array *) uin->d)->getNF(i - 1);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -953,25 +950,21 @@ static const struct luaL_Reg Catalog_m[]
 
 static int m_Dict_incRef(lua_State * L)
 {
-    int i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Dict);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = ((Dict *) uin->d)->incRef();
-    lua_pushinteger(L, i);
+    lua_pushinteger(L, 1);
     return 1;
 }
 
 static int m_Dict_decRef(lua_State * L)
 {
-    int i;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Dict);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    i = ((Dict *) uin->d)->decRef();
-    lua_pushinteger(L, i);
+    lua_pushinteger(L, 1);
     return 1;
 }
 
@@ -986,7 +979,7 @@ static int m_Dict_add(lua_State * L)
         pdfdoc_changed_error(L);
     s = copyString(luaL_checkstring(L, 2));
     uobj = (udstruct *) luaL_checkudata(L, 3, M_Object);
-    ((Dict *) uin->d)->add(s, ((Object *) uobj->d));
+    ((Dict *) uin->d)->add(s, std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -999,7 +992,7 @@ static int m_Dict_set(lua_State * L)
         pdfdoc_changed_error(L);
     s = luaL_checkstring(L, 2);
     uobj = (udstruct *) luaL_checkudata(L, 3, M_Object);
-    ((Dict *) uin->d)->set(s, ((Object *) uobj->d));
+    ((Dict *) uin->d)->set(s, std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -1027,7 +1020,7 @@ static int m_Dict_lookup(lua_State * L)
     s = luaL_checkstring(L, 2);
     uout = new_Object_userdata(L);
     uout->d = new Object();
-    ((Dict *) uin->d)->lookup(s, (Object *) uout->d);
+    *((Object *) uout->d) = ((Dict *) uin->d)->lookup(s);
     uout->atype = ALLOC_LEPDF;
     uout->pc = uin->pc;
     uout->pd = uin->pd;
@@ -1044,7 +1037,7 @@ static int m_Dict_lookupNF(lua_State * L
     s = luaL_checkstring(L, 2);
     uout = new_Object_userdata(L);
     uout->d = new Object();
-    ((Dict *) uin->d)->lookupNF(s, (Object *) uout->d);
+    *((Object *) uout->d) = ((Dict *) uin->d)->lookupNF(s);
     uout->atype = ALLOC_LEPDF;
     uout->pc = uin->pc;
     uout->pd = uin->pd;
@@ -1096,7 +1089,7 @@ static int m_Dict_getVal(lua_State * L)
     if (i > 0 && i <= len) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Dict *) uin->d)->getVal(i - 1, (Object *) uout->d);
+        *((Object *) uout->d) = ((Dict *) uin->d)->getVal(i - 1);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -1117,7 +1110,7 @@ static int m_Dict_getValNF(lua_State * L
     if (i > 0 && i <= len) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Dict *) uin->d)->getValNF(i - 1, (Object *) uout->d);
+        *((Object *) uout->d) = ((Dict *) uin->d)->getValNF(i - 1);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -1381,9 +1374,9 @@ static int m_Object_initBool(lua_State *
         pdfdoc_changed_error(L);
     luaL_checktype(L, 2, LUA_TBOOLEAN);
     if (lua_toboolean(L, 2) != 0)
-        ((Object *) uin->d)->initBool(gTrue);
+        *((Object *) uin->d) = Object(gTrue);
     else
-        ((Object *) uin->d)->initBool(gFalse);
+        *((Object *) uin->d) = Object(gFalse);
     return 0;
 }
 
@@ -1395,7 +1388,7 @@ static int m_Object_initInt(lua_State *
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     i = luaL_checkint(L, 2);
-    ((Object *) uin->d)->initInt(i);
+    *((Object *) uin->d) = Object(i);
     return 0;
 }
 
@@ -1407,7 +1400,7 @@ static int m_Object_initReal(lua_State *
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     d = luaL_checknumber(L, 2);
-    ((Object *) uin->d)->initReal(d);
+    *((Object *) uin->d) = Object(d);
     return 0;
 }
 
@@ -1422,7 +1415,7 @@ static int m_Object_initString(lua_State
         pdfdoc_changed_error(L);
     s = luaL_checklstring(L, 2, &len);
     gs = new GooString(s, len);
-    ((Object *) uin->d)->initString(gs);
+    *((Object *) uin->d) = Object(gs);
     return 0;
 }
 
@@ -1434,7 +1427,7 @@ static int m_Object_initName(lua_State *
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     s = luaL_checkstring(L, 2);
-    ((Object *) uin->d)->initName(s);
+    *((Object *) uin->d) = Object(objName, s);
     return 0;
 }
 
@@ -1444,13 +1437,14 @@ static int m_Object_initNull(lua_State *
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initNull();
+    *((Object *) uin->d) = Object(objNull);
     return 0;
 }
 
 static int m_Object_initArray(lua_State * L)
 {
     udstruct *uin, *uxref;
+    Array *a;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     uxref = (udstruct *) luaL_checkudata(L, 2, M_XRef);
     if (uin->pd != NULL && uxref->pd != NULL && uin->pd != uxref->pd)
@@ -1458,7 +1452,8 @@ static int m_Object_initArray(lua_State
     if ((uin->pd != NULL && uin->pd->pc != uin->pc)
         || (uxref->pd != NULL && uxref->pd->pc != uxref->pc))
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initArray((XRef *) uxref->d);
+    a = new Array((XRef *) uxref->d);
+    *((Object *) uin->d) = Object(a);
     return 0;
 }
 
@@ -1469,6 +1464,7 @@ static int m_Object_initArray(lua_State
 static int m_Object_initDict(lua_State * L)
 {
     udstruct *uin, *uxref;
+    Dict *d;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     uxref = (udstruct *) luaL_checkudata(L, 2, M_XRef);
     if (uin->pd != NULL && uxref->pd != NULL && uin->pd != uxref->pd)
@@ -1476,7 +1472,8 @@ static int m_Object_initDict(lua_State *
     if ((uin->pd != NULL && uin->pd->pc != uin->pc)
         || (uxref->pd != NULL && uxref->pd->pc != uxref->pc))
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initDict((XRef *) uxref->d);
+    d = new Dict((XRef *) uxref->d);
+    *((Object *) uin->d) = Object(d);
     return 0;
 }
 
@@ -1490,7 +1487,7 @@ static int m_Object_initStream(lua_State
     if ((uin->pd != NULL && uin->pd->pc != uin->pc)
         || (ustream->pd != NULL && ustream->pd->pc != ustream->pc))
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initStream((Stream *) ustream->d);
+    *((Object *) uin->d) = Object((Stream *) ustream->d);
     return 0;
 }
 
@@ -1503,7 +1500,7 @@ static int m_Object_initRef(lua_State *
         pdfdoc_changed_error(L);
     num = luaL_checkint(L, 2);
     gen = luaL_checkint(L, 3);
-    ((Object *) uin->d)->initRef(num, gen);
+    *((Object *) uin->d) = Object(num, gen);
     return 0;
 }
 
@@ -1515,7 +1512,7 @@ static int m_Object_initCmd(lua_State *
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
     s = luaL_checkstring(L, 2);
-    ((Object *) uin->d)->initCmd(CHARP_CAST s);
+    *((Object *) uin->d) = Object(objCmd, CHARP_CAST s);
     return 0;
 }
 
@@ -1525,7 +1522,7 @@ static int m_Object_initError(lua_State
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initError();
+    *((Object *) uin->d) = Object(objError);
     return 0;
 }
 
@@ -1535,7 +1532,7 @@ static int m_Object_initEOF(lua_State *
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
         pdfdoc_changed_error(L);
-    ((Object *) uin->d)->initEOF();
+    *((Object *) uin->d) = Object(objEOF);
     return 0;
 }
 
@@ -1551,7 +1548,7 @@ static int m_Object_fetch(lua_State * L)
         pdfdoc_changed_error(L);
     uout = new_Object_userdata(L);
     uout->d = new Object();
-    ((Object *) uin->d)->fetch((XRef *) uxref->d, (Object *) uout->d);
+    *((Object *) uout->d) = ((Object *) uin->d)->fetch((XRef *) uxref->d);
     uout->atype = ALLOC_LEPDF;
     uout->pc = uin->pc;
     uout->pd = uin->pd;
@@ -1816,7 +1813,7 @@ static int m_Object_arrayAdd(lua_State *
         pdfdoc_changed_error(L);
     if (!((Object *) uin->d)->isArray())
         luaL_error(L, "Object is not an Array");
-    ((Object *) uin->d)->arrayAdd((Object *) uobj->d);
+    ((Object *) uin->d)->arrayAdd(std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -1833,7 +1830,7 @@ static int m_Object_arrayGet(lua_State *
         if (i > 0 && i <= len) {
             uout = new_Object_userdata(L);
             uout->d = new Object();
-            ((Object *) uin->d)->arrayGet(i - 1, (Object *) uout->d);
+            *((Object *) uout->d) = ((Object *) uin->d)->arrayGet(i - 1);
             uout->atype = ALLOC_LEPDF;
             uout->pc = uin->pc;
             uout->pd = uin->pd;
@@ -1857,7 +1854,7 @@ static int m_Object_arrayGetNF(lua_State
         if (i > 0 && i <= len) {
             uout = new_Object_userdata(L);
             uout->d = new Object();
-            ((Object *) uin->d)->arrayGetNF(i - 1, (Object *) uout->d);
+            *((Object *) uout->d) = ((Object *) uin->d)->arrayGetNF(i - 1);
             uout->atype = ALLOC_LEPDF;
             uout->pc = uin->pc;
             uout->pd = uin->pd;
@@ -1897,7 +1894,7 @@ static int m_Object_dictAdd(lua_State *
         pdfdoc_changed_error(L);
     if (!((Object *) uin->d)->isDict())
         luaL_error(L, "Object is not a Dict");
-    ((Object *) uin->d)->dictAdd(copyString(s), (Object *) uobj->d);
+    ((Object *) uin->d)->dictAdd(copyString(s), std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -1915,7 +1912,7 @@ static int m_Object_dictSet(lua_State *
         pdfdoc_changed_error(L);
     if (!((Object *) uin->d)->isDict())
         luaL_error(L, "Object is not a Dict");
-    ((Object *) uin->d)->dictSet(s, (Object *) uobj->d);
+    ((Object *) uin->d)->dictSet(s, std::move(*((Object *) uobj->d)));
     return 0;
 }
 
@@ -1930,7 +1927,7 @@ static int m_Object_dictLookup(lua_State
     if (((Object *) uin->d)->isDict()) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Object *) uin->d)->dictLookup(s, (Object *) uout->d);
+        *((Object *) uout->d) = ((Object *) uin->d)->dictLookup(s);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -1950,7 +1947,7 @@ static int m_Object_dictLookupNF(lua_Sta
     if (((Object *) uin->d)->isDict()) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((Object *) uin->d)->dictLookupNF(s, (Object *) uout->d);
+        *((Object *) uout->d) = ((Object *) uin->d)->dictLookupNF(s);
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -1991,7 +1988,7 @@ static int m_Object_dictGetVal(lua_State
         if (i > 0 && i <= len) {
             uout = new_Object_userdata(L);
             uout->d = new Object();
-            ((Object *) uin->d)->dictGetVal(i - 1, (Object *) uout->d);
+	    *((Object *) uout->d) = ((Object *) uin->d)->dictGetVal(i - 1);
             uout->atype = ALLOC_LEPDF;
             uout->pc = uin->pc;
             uout->pd = uin->pd;
@@ -2015,7 +2012,7 @@ static int m_Object_dictGetValNF(lua_Sta
         if (i > 0 && i <= len) {
             uout = new_Object_userdata(L);
             uout->d = new Object();
-            ((Object *) uin->d)->dictGetValNF(i - 1, (Object *) uout->d);
+            *((Object *) uout->d) = ((Object *) uin->d)->dictGetValNF(i - 1);
             uout->atype = ALLOC_LEPDF;
             uout->pc = uin->pc;
             uout->pd = uin->pd;
@@ -2243,7 +2240,7 @@ m_poppler_get_poppler(Page, Stream, getM
 m_poppler_get_poppler(Page, Dict, getPieceInfo);
 m_poppler_get_poppler(Page, Dict, getSeparationInfo);
 m_poppler_get_poppler(Page, Dict, getResourceDict);
-m_poppler_get_OBJECT(Page, getAnnots);
+m_poppler_get_OBJECT(Page, getAnnotsObject);
 
 m_poppler_get_OBJECT(Page, getContents);
 
@@ -2270,7 +2267,7 @@ static const struct luaL_Reg Page_m[] =
     {"getPieceInfo", m_Page_getPieceInfo},
     {"getSeparationInfo", m_Page_getSeparationInfo},
     {"getResourceDict", m_Page_getResourceDict},
-    {"getAnnots", m_Page_getAnnots},
+    {"getAnnots", m_Page_getAnnotsObject},
     {"getContents", m_Page_getContents},
     {"__tostring", m_Page__tostring},
     {NULL, NULL}                // sentinel
@@ -2520,7 +2517,7 @@ static int m_PDFDoc_getDocInfo(lua_State
     if (((PdfDocument *) uin->d)->doc->getXRef()->isOk()) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((PdfDocument *) uin->d)->doc->getDocInfo((Object *) uout->d);
+        *((Object *) uout->d) = ((PdfDocument *) uin->d)->doc->getDocInfo();
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -2538,7 +2535,7 @@ static int m_PDFDoc_getDocInfoNF(lua_Sta
     if (((PdfDocument *) uin->d)->doc->getXRef()->isOk()) {
         uout = new_Object_userdata(L);
         uout->d = new Object();
-        ((PdfDocument *) uin->d)->doc->getDocInfoNF((Object *) uout->d);
+        *((Object *) uout->d) = ((PdfDocument *) uin->d)->doc->getDocInfoNF();
         uout->atype = ALLOC_LEPDF;
         uout->pc = uin->pc;
         uout->pd = uin->pd;
@@ -2841,7 +2838,7 @@ static int m_Attribute_getValue(lua_Stat
     uout = new_Object_userdata(L);
     uout->d = new Object();
     origin = (Object *) (((Attribute *) uin->d)->getValue());
-    origin->copy ( ((Object *)uout->d) );
+    *((Object *) uout->d) = origin->copy();
     uout->atype = ALLOC_LEPDF;
     uout->pc = uin->pc;
     uout->pd = uin->pd;
@@ -3320,7 +3317,7 @@ static int m_StructTreeRoot_findParentEl
     parent = root->findParentElement(i-1);
     if (parent != NULL) {
        uout = new_StructElement_userdata(L);
-       uout->d = new StructElement( *parent );
+       uout->d = (StructElement *) parent;
        uout->atype = ALLOC_LEPDF;
        uout->pc = uin->pc;
        uout->pd = uin->pd;
@@ -3370,7 +3367,7 @@ static int m_XRef_fetch(lua_State * L)
     gen = luaL_checkint(L, 3);
     uout = new_Object_userdata(L);
     uout->d = new Object();
-    ((XRef *) uin->d)->fetch(num, gen, (Object *) uout->d);
+    *((Object *) uout->d) = ((XRef *) uin->d)->fetch(num, gen);
     uout->atype = ALLOC_LEPDF;
     uout->pc = uin->pc;
     uout->pd = uin->pd;

$NetBSD: patch-tokyocabinet.c,v 1.1 2013/10/27 13:01:33 obache Exp $

* Lua 5.2 API change

--- tokyocabinet.c.orig	2010-09-19 23:14:07.000000000 +0000
+++ tokyocabinet.c
@@ -369,7 +369,7 @@ int luaopen_tokyocabinet(lua_State *lua)
 
 /* convert a table of Lua into a list object of TC */
 static TCLIST *tabletotclist(lua_State *lua, int index){
-  int len = lua_objlen(lua, index);
+  int len = lua_rawlen(lua, index);
   TCLIST *list = tclistnew2(len);
   for(int i = 1; i <= len; i++){
     lua_rawgeti(lua, index, i);
@@ -536,7 +536,7 @@ static int util_pack(lua_State *lua){
       lua_rawseti(lua, aidx, eidx++);
       break;
     case LUA_TTABLE:
-      len = lua_objlen(lua, i);
+      len = lua_rawlen(lua, i);
       for(int j = 1; j <= len; j++){
         lua_rawgeti(lua, i, j);
         lua_rawseti(lua, aidx, eidx++);
@@ -1200,7 +1200,7 @@ static int util_ucs(lua_State *lua){
     lua_error(lua);
   }
   if(lua_type(lua, 1) == LUA_TTABLE){
-    int anum = lua_objlen(lua, 1);
+    int anum = lua_rawlen(lua, 1);
     uint16_t *ary = tcmalloc(sizeof(*ary) * anum + 1);
     for(int i = 1; i <= anum; i++){
       lua_rawgeti(lua, 1, i);
@@ -1260,7 +1260,7 @@ static int util_dist(lua_State *lua){
 static int util_isect(lua_State *lua){
   int argc = lua_gettop(lua);
   if(argc == 1 && lua_type(lua, 1) == LUA_TTABLE){
-    int len = lua_objlen(lua, 1);
+    int len = lua_rawlen(lua, 1);
     for(int i = 1; i <= len; i++){
       lua_rawgeti(lua, 1, i);
       if(lua_type(lua, -1) == LUA_TTABLE){
@@ -1279,7 +1279,7 @@ static int util_isect(lua_State *lua){
   int rnum = 0;
   for(int i = 1; i <= argc; i++){
     if(lua_type(lua, i) != LUA_TTABLE) continue;
-    int len = lua_objlen(lua, i);
+    int len = lua_rawlen(lua, i);
     if(len < 1){
       lua_settop(lua, 0);
       lua_newtable(lua);
@@ -1293,7 +1293,7 @@ static int util_isect(lua_State *lua){
     TCMAP *latter = NULL;
     for(int i = 1; i <= argc; i++){
       if(lua_type(lua, i) != LUA_TTABLE) continue;
-      int len = lua_objlen(lua, i);
+      int len = lua_rawlen(lua, i);
       if(former){
         latter = tcmapnew2(tclmin(len, tcmaprnum(former)));
         for(int j = 1; j <= len; j++){
@@ -1338,7 +1338,7 @@ static int util_isect(lua_State *lua){
     TCMAP *freq = tcmapnew2(rnum);
     for(int i = 1; i <= argc; i++){
       if(lua_type(lua, i) != LUA_TTABLE) continue;
-      int len = lua_objlen(lua, i);
+      int len = lua_rawlen(lua, i);
       TCMAP *uniq = tcmapnew2(len);
       for(int j = 1; j <= len; j++){
         lua_rawgeti(lua, i, j);
@@ -1379,7 +1379,7 @@ static int util_isect(lua_State *lua){
 static int util_union(lua_State *lua){
   int argc = lua_gettop(lua);
   if(argc == 1 && lua_type(lua, 1) == LUA_TTABLE){
-    int len = lua_objlen(lua, 1);
+    int len = lua_rawlen(lua, 1);
     for(int i = 1; i <= len; i++){
       lua_rawgeti(lua, 1, i);
       if(lua_type(lua, -1) == LUA_TTABLE){
@@ -1397,12 +1397,12 @@ static int util_union(lua_State *lua){
   int rnum = 0;
   for(int i = 1; i <= argc; i++){
     if(lua_type(lua, i) != LUA_TTABLE) continue;
-    rnum += lua_objlen(lua, i);
+    rnum += lua_rawlen(lua, i);
   }
   TCMAP *result = tcmapnew2(rnum);
   for(int i = 1; i <= argc; i++){
     if(lua_type(lua, i) != LUA_TTABLE) continue;
-    int len = lua_objlen(lua, i);
+    int len = lua_rawlen(lua, i);
     for(int j = 1; j <= len; j++){
       lua_rawgeti(lua, i, j);
       size_t size;
@@ -6400,7 +6400,7 @@ static int tdbqry_metasearch(lua_State *
     lua_error(lua);
   }
   TDBQRY *qry = data->qry;
-  int num = lua_objlen(lua, 2);
+  int num = lua_rawlen(lua, 2);
   TDBQRY **qrys = tcmalloc(sizeof(*qrys) * (num + 1));
   int qnum = 0;
   qrys[qnum++] = qry;

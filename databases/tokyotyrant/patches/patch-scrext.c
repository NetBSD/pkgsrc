$NetBSD: patch-scrext.c,v 1.1 2013/07/07 05:19:39 obache Exp $

* Lua-5.2 API change (lua_objlen was renamed lua_rawlen).

--- scrext.c.orig	2010-08-05 06:24:33.000000000 +0000
+++ scrext.c
@@ -389,7 +389,7 @@ char *scrextcallmethod(void *scr, const 
       }
       break;
     case LUA_TTABLE:
-      if(lua_objlen(lua, 1) > 0){
+      if(lua_rawlen(lua, 1) > 0){
         lua_rawgeti(lua, 1, 1);
         switch(lua_type(lua, -1)){
           case LUA_TNUMBER:
@@ -879,7 +879,7 @@ static int serv_misc(lua_State *lua){
         tclistpush(args, aptr, asiz);
         break;
       case LUA_TTABLE:
-        len = lua_objlen(lua, i);
+        len = lua_rawlen(lua, i);
         for(int j = 1; j <= len; j++){
           lua_rawgeti(lua, i, j);
           switch(lua_type(lua, -1)){
@@ -970,7 +970,7 @@ static int serv_mapreduce(lua_State *lua
         tclistpush(keys, kbuf, ksiz);
         break;
       case LUA_TTABLE:
-        len = lua_objlen(lua, 3);
+        len = lua_rawlen(lua, 3);
         keys = tclistnew2(len);
         for(int i = 1; i <= len; i++){
           lua_rawgeti(lua, 3, i);
@@ -1311,7 +1311,7 @@ static int serv_pack(lua_State *lua){
         lua_rawseti(lua, aidx, eidx++);
         break;
       case LUA_TTABLE:
-        len = lua_objlen(lua, i);
+        len = lua_rawlen(lua, i);
         for(int j = 1; j <= len; j++){
           lua_rawgeti(lua, i, j);
           lua_rawseti(lua, aidx, eidx++);
@@ -1983,7 +1983,7 @@ static int serv_ucs(lua_State *lua){
     lua_error(lua);
   }
   if(lua_type(lua, 1) == LUA_TTABLE){
-    int anum = lua_objlen(lua, 1);
+    int anum = lua_rawlen(lua, 1);
     uint16_t *ary = tcmalloc(sizeof(*ary) * anum + 1);
     for(int i = 1; i <= anum; i++){
       lua_rawgeti(lua, 1, i);
@@ -2043,7 +2043,7 @@ static int serv_dist(lua_State *lua){
 static int serv_isect(lua_State *lua){
   int argc = lua_gettop(lua);
   if(argc == 1 && lua_type(lua, 1) == LUA_TTABLE){
-    int len = lua_objlen(lua, 1);
+    int len = lua_rawlen(lua, 1);
     for(int i = 1; i <= len; i++){
       lua_rawgeti(lua, 1, i);
       if(lua_type(lua, -1) == LUA_TTABLE){
@@ -2062,7 +2062,7 @@ static int serv_isect(lua_State *lua){
   int rnum = 0;
   for(int i = 1; i <= argc; i++){
     if(lua_type(lua, i) != LUA_TTABLE) continue;
-    int len = lua_objlen(lua, i);
+    int len = lua_rawlen(lua, i);
     if(len < 1){
       lua_settop(lua, 0);
       lua_newtable(lua);
@@ -2076,7 +2076,7 @@ static int serv_isect(lua_State *lua){
     TCMAP *latter = NULL;
     for(int i = 1; i <= argc; i++){
       if(lua_type(lua, i) != LUA_TTABLE) continue;
-      int len = lua_objlen(lua, i);
+      int len = lua_rawlen(lua, i);
       if(former){
         latter = tcmapnew2(tclmin(len, tcmaprnum(former)));
         for(int j = 1; j <= len; j++){
@@ -2121,7 +2121,7 @@ static int serv_isect(lua_State *lua){
     TCMAP *freq = tcmapnew2(rnum);
     for(int i = 1; i <= argc; i++){
       if(lua_type(lua, i) != LUA_TTABLE) continue;
-      int len = lua_objlen(lua, i);
+      int len = lua_rawlen(lua, i);
       TCMAP *uniq = tcmapnew2(len);
       for(int j = 1; j <= len; j++){
         lua_rawgeti(lua, i, j);
@@ -2162,7 +2162,7 @@ static int serv_isect(lua_State *lua){
 static int serv_union(lua_State *lua){
   int argc = lua_gettop(lua);
   if(argc == 1 && lua_type(lua, 1) == LUA_TTABLE){
-    int len = lua_objlen(lua, 1);
+    int len = lua_rawlen(lua, 1);
     for(int i = 1; i <= len; i++){
       lua_rawgeti(lua, 1, i);
       if(lua_type(lua, -1) == LUA_TTABLE){
@@ -2180,12 +2180,12 @@ static int serv_union(lua_State *lua){
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

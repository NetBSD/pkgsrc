$NetBSD: patch-src_libquvi_lua__wrap.c,v 1.1 2020/04/12 19:48:20 joerg Exp $

Inline part of the Lua 5.1/5.2 compat code.

--- src/libquvi/lua_wrap.c.orig	2020-04-12 16:02:28.082417799 +0000
+++ src/libquvi/lua_wrap.c
@@ -410,17 +410,58 @@ static int lua_files_only(const struct d
 }
 
 /* Init. */
+static const char *my_luaL_findtable (lua_State *L, int idx,
+                                   const char *fname, int szhint) {
+  const char *e;
+  if (idx) lua_pushvalue(L, idx);
+  do {
+    e = strchr(fname, '.');
+    if (e == NULL) e = fname + strlen(fname);
+    lua_pushlstring(L, fname, e - fname);
+    if (lua_rawget(L, -2) == LUA_TNIL) {  /* no such field? */
+      lua_pop(L, 1);  /* remove this nil */
+      lua_createtable(L, 0, (*e == '.' ? 1 : szhint)); /* new table for field */
+      lua_pushlstring(L, fname, e - fname);
+      lua_pushvalue(L, -2);
+      lua_settable(L, -4);  /* set new table into field */
+    }
+    else if (!lua_istable(L, -1)) {  /* field has a non-table value? */
+      lua_pop(L, 2);  /* remove table and value */
+      return fname;  /* return problematic part of the name */
+    }
+    lua_remove(L, -2);  /* remove previous table */
+    fname = e + 1;
+  } while (*e == '.');
+  return NULL;
+}
 
 int init_lua(_quvi_t quvi)
 {
   QUVIcode rc;
+  int size;
+  const luaL_Reg *l;
 
   quvi->lua = luaL_newstate();
   if (!quvi->lua)
     return (QUVI_LUAINIT);
 
   luaL_openlibs(quvi->lua);
-  luaL_openlib(quvi->lua, "quvi", reg_meth, 1);
+
+  for (l = reg_meth, size = 0; l && l->name; l++) size++;
+  my_luaL_findtable(quvi->lua, LUA_REGISTRYINDEX, LUA_LOADED_TABLE, 1);
+  if (lua_getfield(quvi->lua, -1, "quvi") != LUA_TTABLE) {  /* no LOADED["quvi"]? */
+    lua_pop(quvi->lua, 1);  /* remove previous result */
+    /* try global variable (and create one if it does not exist) */
+    lua_pushglobaltable(quvi->lua);
+    if (my_luaL_findtable(quvi->lua, 0, "quvi", size) != NULL)
+      luaL_error(quvi->lua, "name conflict for module '%s'", "quvi");
+    lua_pushvalue(quvi->lua, -1);
+    lua_setfield(quvi->lua, -3, "quvi");  /* LOADED["quvi"] = new table */
+  }
+  lua_remove(quvi->lua, -2);  /* remove LOADED table */
+
+  lua_insert(quvi->lua, -2);
+  luaL_setfuncs(quvi->lua, reg_meth, 1);
 
   rc = scan_known_dirs(&quvi->util_scripts, "lua/util", lua_files_only);
 

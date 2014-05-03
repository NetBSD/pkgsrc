$NetBSD: patch-libluasqlite3.c,v 1.1 2014/05/03 13:01:24 alnsn Exp $

--- libluasqlite3.c.orig	2006-05-11 11:06:16.000000000 +0000
+++ libluasqlite3.c
@@ -302,10 +302,28 @@ static void report_error(lua_State * L, 
 #define checkint(L, narg)	( (int)		checknumber((L), (narg)) )
 #define checkdouble(L, narg)	( (double)	checknumber((L), (narg)) )
 
+#if LUA_VERSION_NUM >= 502 /* Lua 5.2 */
+#define stringlen(L, narg) lua_rawlen(L, narg)
+#else
+#define stringlen(L, narg) lua_strlen(L, narg)
+#endif
+
+/*
+ * Quote from http://www.lua.org/manual/5.2/manual.html#8.3:
+ * luaL_typerror was removed. Write your own version if you need it. 
+ */
+static int typerror(lua_State *L, int narg, const char *tname)
+{
+  const char *msg;
+
+  msg = lua_pushfstring(L, "%s expected, got %s", tname, luaL_typename(L, narg));
+  return luaL_argerror(L, narg, msg);
+}
+
 static void * checkudata(lua_State * L, int narg)
 {
   if (!lua_isuserdata(L, narg))
-    luaL_typerror(L, narg, "userdata");
+    typerror(L, narg, "userdata");
   return lua_touserdata(L, narg);
 }
 
@@ -330,7 +348,7 @@ static int checknilornoneorfunc(lua_Stat
     return 0;
   if (lua_isfunction(L, narg))
     return 1;
-  luaL_typerror(L, narg, "nil, none or function");
+  typerror(L, narg, "nil, none or function");
   return 0; /* never reached, make compiler happy... */
 }
 
@@ -348,14 +366,14 @@ FUNC( l_sqlite3_bind_null )
 
 FUNC( l_sqlite3_bind_text )
 {
-  lua_pushnumber(L, sqlite3_bind_text(checkstmt_stmt(L, 1), checkint(L, 2), checkstr(L, 3), lua_strlen(L, 3), SQLITE_TRANSIENT) );
+  lua_pushnumber(L, sqlite3_bind_text(checkstmt_stmt(L, 1), checkint(L, 2), checkstr(L, 3), stringlen(L, 3), SQLITE_TRANSIENT) );
   return 1;
 }
 
 
 FUNC( l_sqlite3_bind_blob )
 {
-  lua_pushnumber(L, sqlite3_bind_blob(checkstmt_stmt(L, 1), checkint(L, 2), checkstr(L, 3), lua_strlen(L, 3), SQLITE_TRANSIENT) );
+  lua_pushnumber(L, sqlite3_bind_blob(checkstmt_stmt(L, 1), checkint(L, 2), checkstr(L, 3), stringlen(L, 3), SQLITE_TRANSIENT) );
   return 1;
 }
 
@@ -420,7 +438,7 @@ FUNC( l_sqlite3_bind )
       break;
     
     case LUA_TSTRING:
-      lua_pushnumber(L, sqlite3_bind_text(stmt, index, lua_tostring(L, 3), lua_strlen(L, 3), SQLITE_TRANSIENT) );
+      lua_pushnumber(L, sqlite3_bind_text(stmt, index, lua_tostring(L, 3), stringlen(L, 3), SQLITE_TRANSIENT) );
       break;
     
     default:
@@ -764,7 +782,7 @@ FUNC( l_sqlite3_prepare )
   
   DB * db			= checkdb(L, 1);
   const char * sql		= checkstr(L, 2);
-  int sql_size			= lua_strlen(L, 2);
+  int sql_size			= stringlen(L, 2);
   const char * leftover		= 0;
   sqlite3_stmt * sqlite3_stmt 	= 0;
   int error, leftover_size;
@@ -898,7 +916,7 @@ static void func_callback_wrapper(int wh
   if (lua_pcall(L, values ? 3 : 1, 0, 0))
   {
     fprintf(stderr, "libluasqlite3: func_callback_wrapper: Warning: user function error: %s\n", lua_tostring(L, -1));
-    sqlite3_result_error(ctx, lua_tostring(L, -1), lua_strlen(L, -1));
+    sqlite3_result_error(ctx, lua_tostring(L, -1), stringlen(L, -1));
     lua_pop(L, 1);
   }
 }
@@ -1077,7 +1095,7 @@ FUNC( l_sqlite3_result_null )
 
 FUNC( l_sqlite3_result_error )
 {
-  sqlite3_result_error(checkcontext(L, 1), checkstr(L, 2), lua_strlen(L, 2));
+  sqlite3_result_error(checkcontext(L, 1), checkstr(L, 2), stringlen(L, 2));
   return 0;
 }
 
@@ -1111,14 +1129,14 @@ FUNC( l_sqlite3_result_number )
 
 FUNC( l_sqlite3_result_blob )
 {
-  sqlite3_result_blob(checkcontext(L, 1), checkstr(L, 2), lua_strlen(L, 2), SQLITE_TRANSIENT);
+  sqlite3_result_blob(checkcontext(L, 1), checkstr(L, 2), stringlen(L, 2), SQLITE_TRANSIENT);
   return 0;
 }
 
 
 FUNC( l_sqlite3_result_text )
 {
-  sqlite3_result_text(checkcontext(L, 1), checkstr(L, 2), lua_strlen(L, 2), SQLITE_TRANSIENT);
+  sqlite3_result_text(checkcontext(L, 1), checkstr(L, 2), stringlen(L, 2), SQLITE_TRANSIENT);
   return 0;
 }
 
@@ -1161,7 +1179,7 @@ FUNC( l_sqlite3_result )
       break;
     
     case LUA_TSTRING:
-      sqlite3_result_text(context, lua_tostring(L, 2), lua_strlen(L, 2), SQLITE_TRANSIENT);
+      sqlite3_result_text(context, lua_tostring(L, 2), stringlen(L, 2), SQLITE_TRANSIENT);
       break;
     
     default:

$NetBSD: patch-src_lua_lua__task.c,v 1.3 2018/09/07 11:19:07 fhajny Exp $

Fix deprecated Lua call.

--- src/lua/lua_task.c.orig	2018-08-01 14:21:24.000000000 +0000
+++ src/lua/lua_task.c
@@ -1307,7 +1307,7 @@ lua_task_load_from_string (lua_State * L
 {
 	struct rspamd_task *task = NULL, **ptask;
 	const gchar *str_message = luaL_checkstring (L, 1), *err = NULL;
-	gsize message_len = lua_strlen (L, 1);
+	gsize message_len = lua_rawlen (L, 1);
 	struct rspamd_config *cfg = NULL;
 	gboolean res = FALSE;
 

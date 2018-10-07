$NetBSD: patch-test_rspamd__lua__pcall__vs__resume__test.c,v 1.1 2018/10/07 20:10:57 fhajny Exp $

Add Lua 5.3 support.

--- test/rspamd_lua_pcall_vs_resume_test.c.orig	2018-09-24 13:53:53.000000000 +0000
+++ test/rspamd_lua_pcall_vs_resume_test.c
@@ -53,7 +53,11 @@ test_resume(lua_State *L, gint function_
 
 	for (i = 0; i < N; i ++) {
 		lua_rawgeti (L, LUA_REGISTRYINDEX, function_call);
+#if LUA_VERSION_NUM < 503
 		lua_resume (L, 0);
+#else
+		lua_resume (L, NULL, 0);
+#endif
 		lua_pop (L, 1);
 	}
 
@@ -75,7 +79,11 @@ test_resume_get_thread(gint function_cal
 		ent = lua_thread_pool_get_for_config (rspamd_main->cfg);
 
 		lua_rawgeti (ent->lua_state, LUA_REGISTRYINDEX, function_call);
+#if LUA_VERSION_NUM < 503
 		lua_resume (ent->lua_state, 0);
+#else
+		lua_resume (ent->lua_state, NULL, 0);
+#endif
 		lua_pop (ent->lua_state, 1);
 
 		lua_thread_pool_return (rspamd_main->cfg->lua_thread_pool, ent);
@@ -99,7 +107,11 @@ test_resume_get_new_thread(gint function
 		ent = lua_thread_pool_get_for_task (rspamd_main->cfg->lua_thread_pool);
 
 		lua_rawgeti (ent->lua_state, LUA_REGISTRYINDEX, function_call);
+#if LUA_VERSION_NUM < 503
 		lua_resume (ent->lua_state, 0);
+#else
+		lua_resume (ent->lua_state, NULL, 0);
+#endif
 		lua_pop (ent->lua_state, 1);
 
 		/* lua_thread_pool_return (rspamd_main->cfg->lua_thread_pool, ent); */

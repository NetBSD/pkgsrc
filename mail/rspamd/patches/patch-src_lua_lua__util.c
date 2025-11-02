$NetBSD: patch-src_lua_lua__util.c,v 1.4 2025/11/02 21:17:43 wiz Exp $

NetBSD's kinfo_proc is not the same as the other *BSDs.
https://github.com/rspamd/rspamd/issues/5723

--- src/lua/lua_util.c.orig	2025-10-05 18:04:57.000000000 +0000
+++ src/lua/lua_util.c
@@ -2532,7 +2532,7 @@ lua_util_get_memory_usage(lua_State *L)
 		lua_pushinteger(L, info.virtual_size);
 		lua_settable(L, -3);
 	}
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 	struct kinfo_proc kp;
 	size_t len = sizeof(kp);
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};

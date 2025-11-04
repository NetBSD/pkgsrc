$NetBSD: patch-src_lua_lua__util.c,v 1.5 2025/11/04 11:42:45 wiz Exp $

Fix build on NetBSD.
https://github.com/rspamd/rspamd/pull/5726/files

--- src/lua/lua_util.c.orig	2025-10-05 18:04:57.000000000 +0000
+++ src/lua/lua_util.c
@@ -34,6 +34,9 @@
 #ifdef __FreeBSD__
 #include <sys/user.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
 #endif
 #ifdef __APPLE__
 #include <mach/mach.h>
@@ -2532,7 +2535,21 @@ lua_util_get_memory_usage(lua_State *L)
 		lua_pushinteger(L, info.virtual_size);
 		lua_settable(L, -3);
 	}
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__NetBSD__)
+	struct kinfo_proc2 kp;
+	size_t len = sizeof(kp);
+	int mib[6] = {CTL_KERN, KERN_PROC2, KERN_PROC_PID, getpid(), sizeof(struct kinfo_proc2), 1};
+
+	if (sysctl(mib, 6, &kp, &len, NULL, 0) == 0) {
+		lua_pushstring(L, "rss");
+		lua_pushinteger(L, kp.p_vm_rssize * getpagesize());
+		lua_settable(L, -3);
+
+		lua_pushstring(L, "vsize");
+		lua_pushinteger(L, kp.p_vm_vsize * getpagesize());
+		lua_settable(L, -3);
+	}
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 	struct kinfo_proc kp;
 	size_t len = sizeof(kp);
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};

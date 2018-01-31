$NetBSD: patch-src_lua_lua__util.c,v 1.1 2018/01/31 20:09:20 fhajny Exp $

Add fcntl support (namely for SunOS).

--- src/lua/lua_util.c.orig	2017-06-14 14:45:41.000000000 +0000
+++ src/lua/lua_util.c
@@ -1544,6 +1544,15 @@ lua_util_lock_file (lua_State *L)
 	gint fd = -1;
 	gboolean own = FALSE;
 
+#if !HAVE_FLOCK
+	struct flock fl = {
+		.l_type = F_WRLCK,
+		.l_whence = SEEK_SET,
+		.l_start = 0,
+		.l_len = 0
+	};
+#endif
+
 	fpath = luaL_checkstring (L, 1);
 
 	if (fpath) {
@@ -1562,7 +1571,11 @@ lua_util_lock_file (lua_State *L)
 			return 2;
 		}
 
+#if HAVE_FLOCK
 		if (flock (fd, LOCK_EX) == -1) {
+#else
+		if (fcntl (fd, F_SETLKW, &fl) == -1) {
+#endif
 			lua_pushnil (L);
 			lua_pushstring (L, strerror (errno));
 
@@ -1588,6 +1601,15 @@ lua_util_unlock_file (lua_State *L)
 	gint fd = -1, ret, serrno;
 	gboolean do_close = TRUE;
 
+#if !HAVE_FLOCK
+	struct flock fl = {
+		.l_type = F_UNLCK,
+		.l_whence = SEEK_SET,
+		.l_start = 0,
+		.l_len = 0
+	};
+#endif
+
 	if (lua_isnumber (L, 1)) {
 		fd = lua_tonumber (L, 1);
 
@@ -1595,7 +1617,11 @@ lua_util_unlock_file (lua_State *L)
 			do_close = lua_toboolean (L, 2);
 		}
 
+#if HAVE_FLOCK
 		ret = flock (fd, LOCK_UN);
+#else
+		ret = fcntl (fd, F_SETLKW, &fl);
+#endif
 
 		if (do_close) {
 			serrno = errno;

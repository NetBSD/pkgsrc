$NetBSD: patch-ext_posix_posix.c,v 1.1 2013/09/14 09:06:48 ryoon Exp $

--- ext/posix/posix.c.orig	2013-09-09 07:15:14.000000000 +0000
+++ ext/posix/posix.c
@@ -907,6 +907,7 @@ Create a unique temporary directory.
 @return path on success, nil otherwise
 @return error message if failed
 */
+#if defined(HAVE_MKDTEMP)
 static int Pmkdtemp(lua_State *L)
 {
 	const char *path = luaL_checkstring(L, 1);
@@ -925,6 +926,7 @@ static int Pmkdtemp(lua_State *L)
 	lalloc(ud, tmppath, path_len, 0);
 	return (res == NULL) ? pusherror(L, path) : 1;
 }
+#endif
 
 static int runexec(lua_State *L, int use_shell)
 {
@@ -3807,7 +3809,9 @@ static const luaL_Reg R[] =
 	MENTRY( Pmkdir		),
 	MENTRY( Pmkfifo		),
 	MENTRY( Pmkstemp	),
+#if defined(HAVE_MKDTEMP)
 	MENTRY( Pmkdtemp	),
+#endif
 	MENTRY( Pmktime		),
 	MENTRY( Pnice		),
 	MENTRY( Popen		),
@@ -4694,8 +4698,12 @@ LUALIB_API int luaopen_posix_c (lua_Stat
 	MENTRY( AI_PASSIVE	);
 	MENTRY( AI_CANONNAME	);
 	MENTRY( AI_NUMERICHOST	);
+#if defined(HAVE_DECL_AI_V4MAPPED)
 	MENTRY( AI_V4MAPPED	);
+#endif
+#if defined(HAVE_DECL_AI_ALL)
 	MENTRY( AI_ALL		);
+#endif
 	MENTRY( AI_ADDRCONFIG	);
 
 	MENTRY( IPV6_JOIN_GROUP		);

$NetBSD: patch-ext_posix_stdlib.c,v 1.1 2018/03/05 12:46:02 ryoon Exp $

--- ext/posix/stdlib.c.orig	2018-02-21 02:29:31.000000000 +0000
+++ ext/posix/stdlib.c
@@ -99,6 +99,7 @@ Pgrantpt(lua_State *L)
 }
 
 
+# if defined(HAVE_MKDTEMP)
 /***
 Create a unique temporary directory.
 @function mkdtemp
@@ -134,6 +135,7 @@ Pmkdtemp(lua_State *L)
 	return binding_notimplemented(L, "mkdtemp", "C");
 #endif
 }
+#endif
 
 
 /***

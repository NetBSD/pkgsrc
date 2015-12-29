$NetBSD: patch-src_ldo.c,v 1.2 2015/12/29 23:34:50 dholland Exp $

Patch for CVS-2014-5461, from Debian.

--- src/ldo.c.orig	2015-03-22 17:11:01.000000000 +0000
+++ src/ldo.c
@@ -274,7 +274,7 @@ int luaD_precall (lua_State *L, StkId fu
     CallInfo *ci;
     StkId st, base;
     Proto *p = cl->p;
-    luaD_checkstack(L, p->maxstacksize);
+    luaD_checkstack(L, p->maxstacksize + p->numparams);
     func = restorestack(L, funcr);
     if (!p->is_vararg) {  /* no varargs? */
       base = func + 1;

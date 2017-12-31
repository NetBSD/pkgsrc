$NetBSD: patch-texk_web2c_luatexdir_luaffi_ctype.c,v 1.1 2017/12/31 00:36:04 markd Exp $
gcc-7 fix - Dr. Werner Fink <werner@suse.de>

--- texk/web2c/luatexdir/luaffi/ctype.c.orig	2017-02-10 01:03:59.000000000 +0000
+++ texk/web2c/luatexdir/luaffi/ctype.c
@@ -245,6 +245,10 @@ void* to_cdata(lua_State* L, int idx, st
 
     lua_pop(L, 1); /* mt */
     cd = (struct cdata*) lua_touserdata(L, idx);
+    if (!cd) {
+        lua_pushnil(L);
+        return NULL;
+    }
     *ct = cd->type;
     lua_getuservalue(L, idx);
 

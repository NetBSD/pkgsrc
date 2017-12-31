$NetBSD: patch-texk_web2c_luatexdir_lua_lpdfscannerlib.cc,v 1.1 2017/12/31 00:41:19 markd Exp $

Add support for newer poppler's from ArchLinux

--- texk/web2c/luatexdir/lua/lpdfscannerlib.cc.orig	2016-11-25 18:09:15.000000000 +0000
+++ texk/web2c/luatexdir/lua/lpdfscannerlib.cc
@@ -634,7 +634,7 @@ static int scanner_scan(lua_State * L)
       int i;
       for (i=0;i<count;i++) {
 	Object *val = new Object();
-	arrayref->get(i, val);
+	*val = arrayref->get(i);
 	if (val->isStream()) {
 	  ObjectList *rover = self->_streams;
 	  ObjectList *item = (ObjectList *)priv_xmalloc (sizeof(ObjectList));

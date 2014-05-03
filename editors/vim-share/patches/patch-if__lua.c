$NetBSD: patch-if__lua.c,v 1.1 2014/05/03 07:30:19 richard Exp $

--- src/if_lua.c.orig	2013-04-22 08:09:33.000000000 +0000
+++ src/if_lua.c
@@ -734,7 +734,7 @@ luaV_list_newindex (lua_State *L)
     if (li == NULL) return 0;
     if (lua_isnil(L, 3)) /* remove? */
     {
-	list_remove(l, li, li);
+	vimlist_remove(l, li, li);
 	clear_tv(&li->li_tv);
 	vim_free(li);
     }

$NetBSD: patch-src_lib_edje__lua2.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/lib/edje_lua2.c.orig	2013-07-30 14:42:43.000000000 +0000
+++ src/lib/edje_lua2.c
@@ -382,7 +382,7 @@ _elua_push_name(lua_State *L, char *q, i
 
    // A simplistic scan through an identifier, it's wrong, but it's quick,
    // and we don't mind that it's wrong, coz this is only internal.
-   while (isalnum((int)*q))
+   while (isalnum((unsigned char)*q))
       q++;
    temp = *q;
    *q = '\0';
@@ -422,7 +422,7 @@ _elua_scan_params(lua_State *L, int i, c
         char *q;
         Eina_Bool get = EINA_TRUE;
 
-        while (isspace((int)*p))
+        while (isspace((unsigned char)*p))
            p++;
         q = p + 1;
         switch (*p)
@@ -539,7 +539,7 @@ _elua_ret(lua_State *L, char *params, ..
         char *q;
         Eina_Bool set = EINA_TRUE;
 
-        while (isspace((int)*p))
+        while (isspace((unsigned char)*p))
            p++;
         q = p + 1;
         switch (*p)

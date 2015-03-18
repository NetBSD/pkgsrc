$NetBSD: patch-env.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- env.cpp.orig	2015-03-17 21:56:51.000000000 +0000
+++ env.cpp
@@ -710,7 +710,7 @@ int env_set(const wcstring &key, const w
 
     int is_universal = 0;
 
-    if (val && contains(key, L"PWD", L"HOME"))
+    if (val && contains(&key, L"PWD", L"HOME"))
     {
         /* Canoncalize our path; if it changes, recurse and try again. */
         wcstring val_canonical = val;

$NetBSD: patch-getdefs_getdefs.c,v 1.1 2026/09/12 12:14:41 wiz Exp $

Bound the two name copies in buildPreamble().

A long definition name walks off a stack buffer.  Upstream 6da941a9 is a
363-line restructuring that cannot be taken here.  Savannah sr #111449.

--- getdefs/getdefs.c.orig	2018-08-27 02:41:23.000000000 +0000
+++ getdefs/getdefs.c
@@ -374,7 +374,7 @@
     char * pzDef      = *ppzDef;
     char * pzOut      = *ppzOut;
 
-    char   def_bf[  MAXNAMELEN ];
+    char   def_bf[  MAXNAMELEN * 2 + sizeof(long) ];
     char   name_bf[ MAXNAMELEN ];
     char * def_str    = def_bf;
     char * pzIfText   = NULL;
@@ -383,9 +383,22 @@
      *  Copy out the name of the entry type
      */
     *def_str++ = '`';
-    while (isalnum(*pzDef) || (*pzDef == '_') || (*pzDef == '.')
-          || (*pzDef == '[') || (*pzDef == ']'))
-        *def_str++ = *pzDef++;
+    {
+        char const * scan = pzDef;
+        size_t       len;
+
+        while (isalnum(*pzDef) || (*pzDef == '_') || (*pzDef == '.')
+              || (*pzDef == '[') || (*pzDef == ']'))
+            pzDef++;
+
+        len = (size_t)(pzDef - scan);
+        if (len >= MAXNAMELEN) {
+            fprintf(stderr, zNoData, fname, line);
+            return FAILURE;
+        }
+        memcpy(def_str, scan, len);
+        def_str += len;
+    }
 
     *def_str = NUL;
 
@@ -395,10 +408,19 @@
      *  Copy out the name for this entry of the above entry type.
      */
     {
-        char * name_str = name_bf;
+        char const * scan = pzDef;
+        size_t       len;
+
         while (isalnum(*pzDef) || (*pzDef == '_'))
-            *name_str++ = *pzDef++;
-        *name_str = NUL;
+            pzDef++;
+
+        len = (size_t)(pzDef - scan);
+        if (len >= MAXNAMELEN) {
+            fprintf(stderr, zNoData, fname, line);
+            return FAILURE;
+        }
+        memcpy(name_bf, scan, len);
+        name_bf[len] = NUL;
     }
 
     if (  (def_bf[1]  == NUL)

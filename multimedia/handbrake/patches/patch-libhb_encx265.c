$NetBSD: patch-libhb_encx265.c,v 1.1 2025/01/27 16:20:22 wiz Exp $

Fix build with latest x265.

--- libhb/encx265.c.orig	2023-01-22 16:36:49.000000000 +0000
+++ libhb/encx265.c
@@ -441,10 +441,10 @@ int encx265Init(hb_work_object_t *w, hb_
     /* statsfile (but not 2-pass) */
     if (param->logLevel >= X265_LOG_DEBUG)
     {
-        if (param->csvfn == NULL)
+        if (param->csvfn[0] == '\0')
         {
             pv->csvfn = hb_get_temporary_filename("x265.csv");
-            param->csvfn = strdup(pv->csvfn);
+            snprintf(param->csvfn, X265_MAX_STRING_SIZE, "%s", pv->csvfn);
         }
         else
         {

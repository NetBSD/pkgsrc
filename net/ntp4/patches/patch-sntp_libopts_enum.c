$NetBSD: patch-sntp_libopts_enum.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- sntp/libopts/enum.c.orig	2015-12-05 20:28:17.000000000 +0000
+++ sntp/libopts/enum.c
@@ -253,7 +253,7 @@ find_name(char const * name, tOptions * 
 char const *
 optionKeywordName(tOptDesc * pOD, unsigned int enum_val)
 {
-    tOptDesc od = { 0 };
+    tOptDesc od = { .optIndex = 0 };
     od.optArg.argEnum = enum_val;
 
     (*(pOD->pOptProc))(OPTPROC_RETURN_VALNAME, &od );

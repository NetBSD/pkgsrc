$NetBSD: patch-lib_ttyui_pgpOutput.c,v 1.1 2014/11/28 10:53:40 bsiegert Exp $

--- lib/ttyui/pgpOutput.c.orig	2014-11-28 10:49:41.000000000 +0000
+++ lib/ttyui/pgpOutput.c
@@ -38,7 +38,7 @@ char OutputHeader[OUTPUT_LAST + 1][4] =
 Boolean gShowHeaders = FALSE;
 
 static PREFS *pInternalLanguageStrings = NULL;
-static FILE *OutputHandle[OUTPUT_LAST];
+static FILE *OutputHandle[OUTPUT_LAST + 1];
 static int RawOutputID(int OutputType,
 		       PgpSeverityLevel Level,
 		       Boolean DisplayHeader,

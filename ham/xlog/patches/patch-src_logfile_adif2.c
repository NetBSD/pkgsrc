$NetBSD: patch-src_logfile_adif2.c,v 1.1 2014/12/23 18:52:54 joerg Exp $

--- src/logfile/adif2.c.orig	2014-12-23 17:34:08.000000000 +0000
+++ src/logfile/adif2.c
@@ -56,8 +56,6 @@ extern preferencestype preferences;
  */
 static const gint adif_fields[] = { DATE, GMT, CALL, BAND, MODE, RST, MYRST,
 	QSLOUT, QSLIN, REMARKS, POWER, GMTEND, NAME, QTH, LOCATOR, U1, U2 };
-static const gint adif_widths[] = { 15, 8, 15, 15, 8, 8, 8, 8, 8, 80, 8, 8, 8,
-	8, 6, 8, 8 };
 static const gint adif_field_nr = 17;
 
 static LOGDB *adif_handle;

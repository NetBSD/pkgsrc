$NetBSD: patch-contrib-pcl3-src-gdevpcl3.c,v 1.1 2026/01/03 03:50:17 dholland Exp $

Remove extraneous argument. This can't have ever worked.

--- contrib/pcl3/src/gdevpcl3.c~	2012-08-08 08:01:36.000000000 +0000
+++ contrib/pcl3/src/gdevpcl3.c
@@ -127,7 +127,7 @@ static const ms_MediaCode
 /*****************************************************************************/
 
 /* Forward declaration */
-static void pcl3_flag_mismatch_reporter(FILE *err,
+static void pcl3_flag_mismatch_reporter(
   const struct s_eprn_Device *eprn, bool no_match);
 
 /* Macro for creating device structure instances */
@@ -428,7 +428,7 @@ static void init(pcl3_Device *dev)
 
 ******************************************************************************/
 
-static void pcl3_flag_mismatch_reporter(FILE *err,
+static void pcl3_flag_mismatch_reporter(
   const struct s_eprn_Device *eprn, bool no_match)
 {
   const char *epref = eprn->CUPS_messages? CUPS_ERRPREF: "";

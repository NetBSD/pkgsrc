$NetBSD: patch-main_astmm.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- main/astmm.c.orig	2013-09-09 23:21:46.000000000 +0000
+++ main/astmm.c
@@ -1423,7 +1423,7 @@ void __ast_mm_init_phase_2(void)
 
 	mmlog = fopen(filename, "a+");
 	if (mmlog) {
-		fprintf(mmlog, "%ld - New session\n", (long) time(NULL));
+		fprintf(mmlog, "%jd - New session\n", (intmax_t) time(NULL));
 		fflush(mmlog);
 	} else {
 		ast_log(LOG_ERROR, "Could not open malloc debug log file: %s\n", filename);

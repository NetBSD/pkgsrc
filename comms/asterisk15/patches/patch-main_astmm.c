$NetBSD: patch-main_astmm.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/astmm.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/astmm.c
@@ -1487,7 +1487,7 @@ void __ast_mm_init_phase_2(void)
 
 	mmlog = fopen(filename, "a+");
 	if (mmlog) {
-		fprintf(mmlog, "%ld - New session\n", (long) time(NULL));
+		fprintf(mmlog, "%jd - New session\n", (intmax_t) time(NULL));
 		fflush(mmlog);
 	} else {
 		ast_log(LOG_ERROR, "Could not open malloc debug log file: %s\n", filename);

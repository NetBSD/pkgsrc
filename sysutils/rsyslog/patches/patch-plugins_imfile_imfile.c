$NetBSD: patch-plugins_imfile_imfile.c,v 1.4 2015/08/26 00:55:33 fhajny Exp $

Avoid unresolved symbol on inotify-less platforms.
--- plugins/imfile/imfile.c.orig	2015-08-10 10:24:49.000000000 +0000
+++ plugins/imfile/imfile.c
@@ -1840,11 +1840,14 @@ BEGINrunInput
 CODESTARTrunInput
 	DBGPRINTF("imfile: working in %s mode\n", 
 		 (runModConf->opMode == OPMODE_POLLING) ? "polling" : "inotify");
+#if HAVE_INOTIFY_INIT
 	if(runModConf->opMode == OPMODE_POLLING)
 		iRet = doPolling();
 	else
 		iRet = do_inotify();
-
+#else
+	iRet = doPolling();
+#endif
 	DBGPRINTF("imfile: terminating upon request of rsyslog core\n");
 ENDrunInput
 

$NetBSD: patch-plugins_imfile_imfile.c,v 1.2 2014/12/12 12:47:46 fhajny Exp $

Avoid unresolved symbol on inotify-less platforms.
--- plugins/imfile/imfile.c.orig	2014-12-02 10:15:16.000000000 +0000
+++ plugins/imfile/imfile.c
@@ -1709,11 +1709,14 @@ BEGINrunInput
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
 

$NetBSD: patch-plugins_imfile_imfile.c,v 1.5 2016/01/26 15:20:33 fhajny Exp $

Avoid unresolved symbol on inotify-less platforms.
--- plugins/imfile/imfile.c.orig	2016-01-22 07:54:28.000000000 +0000
+++ plugins/imfile/imfile.c
@@ -1839,10 +1839,14 @@ BEGINrunInput
 CODESTARTrunInput
 	DBGPRINTF("imfile: working in %s mode\n",
 		 (runModConf->opMode == OPMODE_POLLING) ? "polling" : "inotify");
+#if HAVE_INOTIFY_INIT
 	if(runModConf->opMode == OPMODE_POLLING)
 		iRet = doPolling();
 	else
 		iRet = do_inotify();
+#else
+	iRet = doPolling();
+#endif
 
 	DBGPRINTF("imfile: terminating upon request of rsyslog core\n");
 ENDrunInput

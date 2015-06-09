$NetBSD: patch-plugins_imfile_imfile.c,v 1.3 2015/06/09 15:00:33 fhajny Exp $

Avoid unresolved symbol on inotify-less platforms.
--- plugins/imfile/imfile.c.orig	2015-05-19 08:53:40.000000000 +0000
+++ plugins/imfile/imfile.c
@@ -1763,11 +1763,14 @@ BEGINrunInput
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
 
@@ -1869,12 +1872,14 @@ CODESTARTmodExit
 	objRelease(errmsg, CORE_COMPONENT);
 	objRelease(prop, CORE_COMPONENT);
 	objRelease(ruleset, CORE_COMPONENT);
+#if HAVE_INOTIFY_INIT
 	if(dirs != NULL) {
 		free(dirs->active.listeners);
 		free(dirs->configured.listeners);
 		free(dirs);
 	}
 	free(wdmap);
+#endif /* #if HAVE_INOTIFY_INIT */
 ENDmodExit
 
 

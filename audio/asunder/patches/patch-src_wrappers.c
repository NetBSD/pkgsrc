$NetBSD: patch-src_wrappers.c,v 1.1 2014/02/04 11:36:44 obache Exp $

skip missing WIFCONTINUED

--- src/wrappers.c.orig	2013-12-18 16:17:29.000000000 +0000
+++ src/wrappers.c
@@ -135,8 +135,10 @@ void sigchld(int signum)
         debugLog("killed by signal %d\n", WTERMSIG(status));
     else if (WIFSTOPPED(status))
         debugLog("stopped by signal %d\n", WSTOPSIG(status));
+#if defined(WIFCONTINUED)
     else if (WIFCONTINUED(status))
         debugLog("continued\n");
+#endif
 
     if (status != 0)
     {

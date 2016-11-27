$NetBSD: patch-signer_src_daemon_engine.c,v 1.1 2016/11/27 14:25:41 he Exp $

xmlCleanupThreads already done by xmlCleanupParser, and calling
xmlCleanupThreads twice leads to abort with NetBSD 7.0 pthread.

--- signer/src/daemon/engine.c.orig	2016-10-17 12:32:58.000000000 +0000
+++ signer/src/daemon/engine.c
@@ -531,7 +531,6 @@ engine_setup(engine_type* engine)
                 engine = NULL;
                 xmlCleanupParser();
                 xmlCleanupGlobals();
-                xmlCleanupThreads();
                 exit(0);
         }
         if (setsid() == -1) {
@@ -1085,7 +1084,6 @@ earlyexit:
     ods_log_close();
     xmlCleanupParser();
     xmlCleanupGlobals();
-    xmlCleanupThreads();
 }
 
 

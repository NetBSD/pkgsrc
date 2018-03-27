$NetBSD: patch-signer_src_daemon_engine.c,v 1.2 2018/03/27 11:40:22 he Exp $

xmlCleanupThreads already done by xmlCleanupParser, and calling
xmlCleanupThreads twice leads to abort with NetBSD 7.0 pthread.
Remove notify handler from netio on zone removal, ref.
https://github.com/opendnssec/opendnssec/pull/713/files

--- signer/src/daemon/engine.c.orig	2017-01-20 14:57:50.000000000 +0000
+++ signer/src/daemon/engine.c
@@ -531,7 +531,6 @@ engine_setup(engine_type* engine)
                 engine = NULL;
                 xmlCleanupParser();
                 xmlCleanupGlobals();
-                xmlCleanupThreads();
                 exit(0);
         }
         if (setsid() == -1) {
@@ -806,6 +805,8 @@ engine_update_zones(engine_type* engine,
             lock_basic_unlock(&zone->zone_lock);
             netio_remove_handler(engine->xfrhandler->netio,
                 &zone->xfrd->handler);
+	    netio_remove_handler(engine->xfrhandler->netio,
+		&zone->notify->handler);
             zone_cleanup(zone);
             zone = NULL;
             continue;
@@ -1085,7 +1086,6 @@ earlyexit:
     ods_log_close();
     xmlCleanupParser();
     xmlCleanupGlobals();
-    xmlCleanupThreads();
 }
 
 

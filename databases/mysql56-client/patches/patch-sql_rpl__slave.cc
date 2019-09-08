$NetBSD: patch-sql_rpl__slave.cc,v 1.3.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Allow build with OpenSSL 1.1.

--- sql/rpl_slave.cc.orig	2019-06-10 10:25:32.000000000 +0000
+++ sql/rpl_slave.cc
@@ -5143,7 +5143,9 @@ err:
   mysql_mutex_unlock(&mi->run_lock);
   DBUG_LEAVE;                                   // Must match DBUG_ENTER()
   my_thread_end();
-  ERR_remove_state(0);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   pthread_exit(0);
   return(0);                                    // Avoid compiler warnings
 }
@@ -5334,7 +5336,9 @@ err:
   }
 
   my_thread_end();
-  ERR_remove_state(0);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   pthread_exit(0);
   DBUG_RETURN(0); 
 }
@@ -6482,7 +6486,9 @@ log '%s' at position %s, relay log '%s' 
 
   DBUG_LEAVE;                            // Must match DBUG_ENTER()
   my_thread_end();
-  ERR_remove_state(0);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   pthread_exit(0);
   return 0;                             // Avoid compiler warnings
 }

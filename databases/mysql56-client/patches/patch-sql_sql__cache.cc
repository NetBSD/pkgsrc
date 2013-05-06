$NetBSD: patch-sql_sql__cache.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_cache.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_cache.cc
@@ -1209,8 +1209,8 @@ void Query_cache::store_query(THD *thd, 
     Query_cache_query_flags flags;
     // fill all gaps between fields with 0 to get repeatable key
     memset(&flags, 0, QUERY_CACHE_FLAGS_SIZE);
-    flags.client_long_flag= test(thd->client_capabilities & CLIENT_LONG_FLAG);
-    flags.client_protocol_41= test(thd->client_capabilities &
+    flags.client_long_flag= my_test(thd->client_capabilities & CLIENT_LONG_FLAG);
+    flags.client_protocol_41= my_test(thd->client_capabilities &
                                    CLIENT_PROTOCOL_41);
     /*
       Protocol influences result format, so statement results in the binary
@@ -1220,10 +1220,10 @@ void Query_cache::store_query(THD *thd, 
     flags.protocol_type= (unsigned int) thd->protocol->type();
     /* PROTOCOL_LOCAL results are not cached. */
     DBUG_ASSERT(flags.protocol_type != (unsigned int) Protocol::PROTOCOL_LOCAL);
-    flags.more_results_exists= test(thd->server_status &
+    flags.more_results_exists= my_test(thd->server_status &
                                     SERVER_MORE_RESULTS_EXISTS);
     flags.in_trans= thd->in_active_multi_stmt_transaction();
-    flags.autocommit= test(thd->server_status & SERVER_STATUS_AUTOCOMMIT);
+    flags.autocommit= my_test(thd->server_status & SERVER_STATUS_AUTOCOMMIT);
     flags.pkt_nr= net->pkt_nr;
     flags.character_set_client_num=
       thd->variables.character_set_client->number;
@@ -1584,14 +1584,14 @@ Query_cache::send_result_to_client(THD *
 
   // fill all gaps between fields with 0 to get repeatable key
   memset(&flags, 0, QUERY_CACHE_FLAGS_SIZE);
-  flags.client_long_flag= test(thd->client_capabilities & CLIENT_LONG_FLAG);
-  flags.client_protocol_41= test(thd->client_capabilities &
+  flags.client_long_flag= my_test(thd->client_capabilities & CLIENT_LONG_FLAG);
+  flags.client_protocol_41= my_test(thd->client_capabilities &
                                  CLIENT_PROTOCOL_41);
   flags.protocol_type= (unsigned int) thd->protocol->type();
-  flags.more_results_exists= test(thd->server_status &
+  flags.more_results_exists= my_test(thd->server_status &
                                   SERVER_MORE_RESULTS_EXISTS);
   flags.in_trans= thd->in_active_multi_stmt_transaction();
-  flags.autocommit= test(thd->server_status & SERVER_STATUS_AUTOCOMMIT);
+  flags.autocommit= my_test(thd->server_status & SERVER_STATUS_AUTOCOMMIT);
   flags.pkt_nr= thd->net.pkt_nr;
   flags.character_set_client_num= thd->variables.character_set_client->number;
   flags.character_set_results_num=
@@ -3040,7 +3040,7 @@ my_bool Query_cache::register_all_tables
 	 tmp++)
       unlink_table(tmp);
   }
-  return test(n);
+  return my_test(n);
 }
 
 

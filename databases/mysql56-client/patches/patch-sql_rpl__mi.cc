$NetBSD: patch-sql_rpl__mi.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/rpl_mi.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/rpl_mi.cc
@@ -478,10 +478,10 @@ bool Master_info::read_info(Rpl_info_han
       DBUG_RETURN(true);
   }
 
-  ssl= (my_bool) test(temp_ssl);
-  ssl_verify_server_cert= (my_bool) test(temp_ssl_verify_server_cert);
+  ssl= (my_bool) my_test(temp_ssl);
+  ssl_verify_server_cert= (my_bool) my_test(temp_ssl_verify_server_cert);
   master_log_pos= (my_off_t) temp_master_log_pos;
-  auto_position= test(temp_auto_position);
+  auto_position= my_test(temp_auto_position);
 
   if (auto_position != 0 && gtid_mode != 3)
   {

$NetBSD: patch-sql_mysqld.cc,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

NetBSD does not have SI_KERNEL...

--- sql/mysqld.cc.orig	2020-01-26 20:43:53.000000000 +0000
+++ sql/mysqld.cc
@@ -3282,7 +3282,11 @@ pthread_handler_t signal_hand(void *arg 
       }
       break;
     case SIGHUP:
+#ifdef SI_KERNEL
       if (!abort_loop && origin != SI_KERNEL)
+#else
+      if (!abort_loop)
+#endif
       {
         int not_used;
 	mysql_print_status();		// Print some debug info

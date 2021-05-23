$NetBSD: patch-support-files_mysql.server.sh,v 1.1 2021/05/23 15:32:47 nia Exp $

Shell portability.

--- support-files/mysql.server.sh.orig	2020-01-26 20:43:57.000000000 +0000
+++ support-files/mysql.server.sh
@@ -436,7 +436,7 @@ case "$mode" in
     exit $r
     ;;
   'bootstrap')
-      if test "$_use_systemctl" == 1 ; then
+      if test "$_use_systemctl" = 1 ; then
         log_failure_msg "Please use galera_new_cluster to start the mariadb service with --wsrep-new-cluster"
         exit 1
       fi

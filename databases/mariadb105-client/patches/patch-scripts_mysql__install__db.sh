$NetBSD: patch-scripts_mysql__install__db.sh,v 1.1 2021/05/23 15:32:47 nia Exp $

NetBSD does not have SO_PEERCRED, so there is no auth_socket.

--- scripts/mysql_install_db.sh.orig	2021-02-18 23:22:29.000000000 +0000
+++ scripts/mysql_install_db.sh
@@ -37,7 +37,7 @@ force=0
 in_rpm=0
 ip_only=0
 cross_bootstrap=0
-auth_root_authentication_method=socket
+auth_root_authentication_method=normal
 auth_root_socket_user=""
 skip_test_db=0
 

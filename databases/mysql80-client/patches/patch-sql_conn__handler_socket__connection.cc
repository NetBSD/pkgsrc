$NetBSD: patch-sql_conn__handler_socket__connection.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

--- sql/conn_handler/socket_connection.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ sql/conn_handler/socket_connection.cc
@@ -950,9 +950,11 @@ bool check_connection_refused_by_tcp_wra
   signal(SIGCHLD, SIG_DFL);
   request_init(&req, RQ_DAEMON, libwrap_name, RQ_FILE,
                mysql_socket_getfd(connect_sock), NULL);
-  fromhost(&req);
+  void (*my_fromhost) (void *) = (void (*) (void *)) fromhost;
+  my_fromhost(&req);
 
-  if (!hosts_access(&req)) {
+  int (*my_host_access) (void *) = (int (*) (void *)) host_access;
+  if (!myhosts_access(&req)) {
     /*
       This may be stupid but refuse() includes an exit(0)
       which we surely don't want...
@@ -964,8 +966,9 @@ bool check_connection_refused_by_tcp_wra
       This is unproblematic as TCP-wrapper is unix specific,
       anyway.
     */
+    char *(*my_eval_client) (void *) = (char *(*) (void *) eval_client;
     syslog(LOG_AUTH | LOG_WARNING, "refused connect from %s",
-           eval_client(&req));
+           my_eval_client(&req));
 
 #ifdef HAVE_LIBWRAP_PROTOTYPES
     // Some distros have patched tcpd.h to have proper prototypes

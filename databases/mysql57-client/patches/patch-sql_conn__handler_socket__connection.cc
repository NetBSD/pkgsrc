$NetBSD: patch-sql_conn__handler_socket__connection.cc,v 1.2 2017/04/11 20:49:15 adam Exp $

--- sql/conn_handler/socket_connection.cc.orig	2017-03-18 07:45:14.000000000 +0000
+++ sql/conn_handler/socket_connection.cc
@@ -942,17 +942,20 @@ Channel_info* Mysqld_socket_listener::li
     signal(SIGCHLD, SIG_DFL);
     request_init(&req, RQ_DAEMON, m_libwrap_name, RQ_FILE,
                  mysql_socket_getfd(connect_sock), NULL);
-    fromhost(&req);
+    void (*my_fromhost) (void *) = (void (*)(void *)) fromhost;
+    my_fromhost(&req);
 
-    if (!hosts_access(&req))
+    int (*my_hosts_access) (void *) = (int (*) (void *)) hosts_access;
+    if (!my_hosts_access(&req))
     {
       /*
         This may be stupid but refuse() includes an exit(0)
         which we surely don't want...
         clean_exit() - same stupid thing ...
       */
+      char *(*my_eval_client) (void *) = (char *(*) (void *)) eval_client;
       syslog(LOG_AUTH | m_deny_severity,
-             "refused connect from %s", eval_client(&req));
+             "refused connect from %s", my_eval_client(&req));
 
 #ifdef HAVE_LIBWRAP_PROTOTYPES
       // Some distros have patched tcpd.h to have proper prototypes

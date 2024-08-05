$NetBSD: patch-client_mysqladmin.cc,v 1.1 2024/08/05 01:23:59 jnemeth Exp $

Redefine signals for Irix.

--- client/mysqladmin.cc.orig	2022-03-23 13:49:36.000000000 +0000
+++ client/mysqladmin.cc
@@ -408,8 +408,14 @@ int main(int argc, char *argv[]) {
 
   commands = temp_argv;
 
-  (void)signal(SIGINT, endprog);  /* Here if abort */
-  (void)signal(SIGTERM, endprog); /* Here if abort */
+#ifdef IRIX5
+#define _MYSQL_END_TYPE (void (*)(...))
+#else
+#define _MYSQL_END_TYPE
+#endif
+
+  (void) signal(SIGINT,_MYSQL_END_TYPE endprog); /* Here if abort */
+  (void) signal(SIGTERM,_MYSQL_END_TYPE endprog);/* Here if abort */
 
   mysql_init(&mysql);
   if (opt_bind_addr) mysql_options(&mysql, MYSQL_OPT_BIND, opt_bind_addr);

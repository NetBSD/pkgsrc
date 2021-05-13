$NetBSD: patch-client_mysqladmin.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

Redefine signals for Irix.

--- client/mysqladmin.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ client/mysqladmin.cc
@@ -413,8 +413,14 @@ int main(int argc, char *argv[]) {
   commands = temp_argv;
   if (tty_password) opt_password = get_tty_password(NullS);
 
-  (void)signal(SIGINT, endprog);  /* Here if abort */
-  (void)signal(SIGTERM, endprog); /* Here if abort */
+#ifdef IRIX5
+#define _MYSQL_END_TYPE (void (*)(...))
+#else
+#define _MYSQL_END_TYPE
+#endif
+
+  (void)signal(SIGINT, _MYSQL_END_TYPE endprog);  /* Here if abort */
+  (void)signal(SIGTERM, _MYSQL_END_TYPE endprog); /* Here if abort */
 
   if (opt_bind_addr) mysql_options(&mysql, MYSQL_OPT_BIND, opt_bind_addr);
   if (opt_compress) mysql_options(&mysql, MYSQL_OPT_COMPRESS, NullS);

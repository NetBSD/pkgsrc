$NetBSD: patch-client_mysqladmin.cc,v 1.1.1.1 2011/04/25 21:12:53 adam Exp $

Redefine signals for Irix.

--- client/mysqladmin.cc.orig	2010-02-04 11:36:52.000000000 +0000
+++ client/mysqladmin.cc
@@ -322,8 +322,14 @@ int main(int argc,char *argv[])
   if (tty_password)
     opt_password = get_tty_password(NullS);
 
-  (void) signal(SIGINT,endprog);			/* Here if abort */
-  (void) signal(SIGTERM,endprog);		/* Here if abort */
+#ifdef IRIX5
+#define _MYSQL_END_TYPE (void (*)(...))
+#else
+#define _MYSQL_END_TYPE
+#endif
+
+  (void) signal(SIGINT,_MYSQL_END_TYPE endprog); /* Here if abort */
+  (void) signal(SIGTERM,_MYSQL_END_TYPE endprog);/* Here if abort */
 
   if (opt_compress)
     mysql_options(&mysql,MYSQL_OPT_COMPRESS,NullS);

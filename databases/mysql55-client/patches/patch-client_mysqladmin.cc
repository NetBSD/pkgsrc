$NetBSD: patch-client_mysqladmin.cc,v 1.3 2014/07/18 13:42:24 ryoon Exp $

Redefine signals for Irix.

--- client/mysqladmin.cc.orig	2014-01-14 08:16:26.000000000 +0000
+++ client/mysqladmin.cc
@@ -29,6 +29,11 @@
 #define SHUTDOWN_DEF_TIMEOUT 3600		/* Wait for shutdown */
 #define MAX_TRUNC_LENGTH 3
 
+#if defined(_SCO_DS)
+#include "../strtoull.c"
+#define strtoull	pkgsrc_strtoull
+#endif
+
 char *host= NULL, *user= 0, *opt_password= 0,
      *default_charset= (char*) MYSQL_AUTODETECT_CHARSET_NAME;
 char truncated_var_names[MAX_MYSQL_VAR][MAX_TRUNC_LENGTH];
@@ -332,8 +337,14 @@ int main(int argc,char *argv[])
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

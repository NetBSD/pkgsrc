$NetBSD: patch-client_mysqlshow.c,v 1.1 2014/07/18 13:42:24 ryoon Exp $

--- client/mysqlshow.c.orig	2014-01-14 08:16:26.000000000 +0000
+++ client/mysqlshow.c
@@ -29,6 +29,11 @@
 #include <sslopt-vars.h>
 #include <welcome_copyright_notice.h>   /* ORACLE_WELCOME_COPYRIGHT_NOTICE */
 
+#if defined(_SCO_DS)
+#include "../strtoull.c"
+#define strtoull	pkgsrc_strtoull
+#endif
+
 static char * host=0, *opt_password=0, *user=0;
 static my_bool opt_show_keys= 0, opt_compress= 0, opt_count=0, opt_status= 0;
 static my_bool tty_password= 0, opt_table_type= 0;

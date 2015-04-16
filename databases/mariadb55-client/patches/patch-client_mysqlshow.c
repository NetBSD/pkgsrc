$NetBSD: patch-client_mysqlshow.c,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- client/mysqlshow.c.orig	2015-02-13 12:07:00.000000000 +0000
+++ client/mysqlshow.c
@@ -30,6 +30,11 @@
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

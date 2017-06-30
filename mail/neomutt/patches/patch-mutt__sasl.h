$NetBSD: patch-mutt__sasl.h,v 1.1 2017/06/30 11:07:26 jperkin Exp $

Handle include-what-you-use breakage.

--- mutt_sasl.h.orig	2017-06-09 10:52:07.000000000 +0000
+++ mutt_sasl.h
@@ -23,9 +23,11 @@
 #include <stddef.h>
 #include <sasl/sasl.h>
 
+#ifdef HOW_ON_EARTH_IS_THIS_SUPPOSED_TO_WORK_AT_ALL
 typedef struct sasl_conn sasl_conn_t;
 typedef struct sasl_interact  sasl_interact_t;
 typedef unsigned sasl_ssf_t;
+#endif
 struct Connection;
 
 int mutt_sasl_client_new(struct Connection *conn, sasl_conn_t **saslconn);

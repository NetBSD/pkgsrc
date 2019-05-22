$NetBSD: patch-main.c,v 1.1 2019/05/22 08:45:11 jmcneill Exp $

--- main.c.orig	2019-03-20 02:36:05.000000000 +0000
+++ main.c
@@ -17,7 +17,9 @@
 #include "sslreq.h"
 #include "warnp.h"
 
+#ifndef CERTFILE
 #define CERTFILE "/usr/local/share/certs/ca-root-nss.crt"
+#endif
 #define PARTSZ (10 * 1024 * 1024)
 
 /* Elastic string type. */

$NetBSD: patch-lib_strings__mosq.c,v 1.1 2021/12/31 23:59:17 triaxx Exp $

Suppress warning by including missing header.

--- lib/strings_mosq.c.orig	2021-11-17 00:28:35.000000000 +0000
+++ lib/strings_mosq.c
@@ -20,6 +20,9 @@ Contributors:
 
 #include <errno.h>
 #include <string.h>
+#if defined(__NetBSD__)
+#include <strings.h>
+#endif
 
 #include "mosquitto.h"
 #include "mqtt_protocol.h"

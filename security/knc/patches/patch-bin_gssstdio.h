$NetBSD: patch-bin_gssstdio.h,v 1.1 2011/12/22 16:33:51 joerg Exp $

--- bin/gssstdio.h.orig	2011-12-22 14:40:13.000000000 +0000
+++ bin/gssstdio.h
@@ -56,6 +56,7 @@
 
 #ifdef HEIMDAL
 #include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
 #else
 #define HAS_INTTYPES_H
 #include <gssapi/gssapi_krb5.h>

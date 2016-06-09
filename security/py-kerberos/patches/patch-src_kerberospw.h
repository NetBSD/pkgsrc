$NetBSD: patch-src_kerberospw.h,v 1.1 2016/06/09 02:06:18 markd Exp $

Support heimdal

--- src/kerberospw.h.orig	2015-03-26 21:53:18.000000000 +0000
+++ src/kerberospw.h
@@ -15,9 +15,15 @@
  *
  **/
 
+#ifdef HEIMDAL
+#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
+#include <krb5.h>
+#else
 #include <gssapi/gssapi.h>
 #include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
+#endif
 
 #define krb5_get_err_text(context,code) error_message(code)
 

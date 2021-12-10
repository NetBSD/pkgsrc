$NetBSD: patch-src_kerberosgss.h,v 1.2 2021/12/10 22:42:35 joerg Exp $

Support heimdal

--- src/kerberosgss.h.orig	2021-01-07 23:03:04.000000000 +0000
+++ src/kerberosgss.h
@@ -14,11 +14,20 @@
  * limitations under the License.
  **/
 
+#ifdef HEIMDAL
+#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
+#include <krb5.h>
+#define gss_krb5_nt_service_name    GSS_KRB5_NT_PRINCIPAL_NAME
+#else
 #include <gssapi/gssapi.h>
 #include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
+#endif
 
+#ifndef HEIMDAL
 #define krb5_get_err_text(context,code) error_message(code)
+#endif
 
 #define AUTH_GSS_ERROR      -1
 #define AUTH_GSS_COMPLETE    1

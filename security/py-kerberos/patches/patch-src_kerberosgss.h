$NetBSD: patch-src_kerberosgss.h,v 1.1 2016/06/09 02:06:18 markd Exp $

Support heimdal

--- src/kerberosgss.h.orig	2016-01-25 17:51:33.000000000 +0000
+++ src/kerberosgss.h
@@ -14,9 +14,16 @@
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
 
 #define krb5_get_err_text(context,code) error_message(code)
 

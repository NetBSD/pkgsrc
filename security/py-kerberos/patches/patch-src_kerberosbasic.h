$NetBSD: patch-src_kerberosbasic.h,v 1.2 2021/12/10 22:42:35 joerg Exp $

Support heimdal

--- src/kerberosbasic.h.orig	2021-01-07 23:03:04.000000000 +0000
+++ src/kerberosbasic.h
@@ -14,11 +14,19 @@
  * limitations under the License.
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
 
+#ifndef HEIMDAL
 #define krb5_get_err_text(context,code) error_message(code)
+#endif
 
 int authenticate_user_krb5pwd(
     const char *user, const char *pswd, const char *service,

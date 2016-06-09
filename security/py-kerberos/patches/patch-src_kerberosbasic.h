$NetBSD: patch-src_kerberosbasic.h,v 1.1 2016/06/09 02:06:18 markd Exp $

Support heimdal

--- src/kerberosbasic.h.orig	2016-01-25 17:51:33.000000000 +0000
+++ src/kerberosbasic.h
@@ -14,9 +14,15 @@
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
 
 #define krb5_get_err_text(context,code) error_message(code)
 

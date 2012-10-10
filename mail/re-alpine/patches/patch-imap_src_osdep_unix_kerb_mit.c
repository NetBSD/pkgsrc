$NetBSD: patch-imap_src_osdep_unix_kerb_mit.c,v 1.1 2012/10/10 19:49:08 markd Exp $

heimdal support from imap-uw package.

--- imap/src/osdep/unix/kerb_mit.c.orig	2008-06-04 18:18:34.000000000 +0000
+++ imap/src/osdep/unix/kerb_mit.c
@@ -26,9 +26,18 @@
  * Last Edited:	30 August 2006
  */
 
+#ifdef HEIMDAL_KRB5
+#include <gssapi/gssapi.h>
+#ifdef GSSAPI_GSSAPI_H_ /* older heimdals use GSSAPI_H_ */
+#include <gssapi/gssapi_krb5.h>
+#endif
+#include <krb5.h>
+#define gss_nt_service_name	GSS_C_NT_HOSTBASED_SERVICE
+#else
 #define PROTOTYPE(x) x
 #include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
+#endif
 
 
 long kerberos_server_valid (void);

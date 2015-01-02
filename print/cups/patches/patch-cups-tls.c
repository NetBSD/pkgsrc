$NetBSD: patch-cups-tls.c,v 1.1 2015/01/02 02:03:42 christos Exp $

Add missing stub.

--- cups/tls.c.orig	2014-08-29 11:19:40.000000000 -0400
+++ cups/tls.c	2014-12-24 14:59:52.000000000 -0500
@@ -50,6 +50,13 @@
 #    include "tls-sspi.c"
 #  endif /* HAVE_GNUTLS */
 #else
+
+void                                    
+_httpTLSSetOptions(int options)         /* I - Options */
+{                                       
+	(void)options;
+}
+
 /* Stubs for when TLS is not supported/available */
 int
 httpCopyCredentials(http_t *http, cups_array_t **credentials)

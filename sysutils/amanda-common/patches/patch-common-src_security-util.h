$NetBSD: patch-common-src_security-util.h,v 1.1 2012/09/09 22:21:54 spz Exp $

--- common-src/security-util.h.orig	2012-02-21 11:36:51.000000000 +0000
+++ common-src/security-util.h
@@ -52,7 +52,11 @@
 #define H_EOF   -2		/* this connection has been shut down */
 
 #ifdef KRB5_SECURITY
-#  define KRB5_DEPRECATED 1
+#  if !defined(__NetBSD__)  /* expecting more OSes to need this */
+#    define KRB5_DEPRECATED 1
+#  else
+#    define KRB5_DEPRECATED
+#  endif __NetBSD__
 #  ifndef KRB5_HEIMDAL_INCLUDES
 #    include <gssapi/gssapi_generic.h>
 #  else

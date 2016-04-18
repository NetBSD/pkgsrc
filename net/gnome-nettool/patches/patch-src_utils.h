$NetBSD: patch-src_utils.h,v 1.1 2016/04/18 12:14:29 jperkin Exp $

Fix SunOS build, from OpenIndiana.

--- src/utils.h.orig	2009-04-18 14:59:27.000000000 +0000
+++ src/utils.h
@@ -29,6 +29,11 @@
 #  include <config.h>
 #endif
 
+#ifdef __sun
+#define gethostbyname2(name, domain) getipnodebyname((name), (domain), 0, &g_n_err_macro)
+int g_n_err_macro;
+#endif
+
 #if (GLIB_MINOR_VERSION < 2)
 
 #  define _g_vsprintf  vsprintf

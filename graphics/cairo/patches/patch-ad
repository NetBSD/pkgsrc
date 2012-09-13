$NetBSD: patch-ad,v 1.11 2012/09/13 15:50:08 jperkin Exp $

The variable name is self-explanatory :)

--- util/cairo-missing/getline.c.orig	Thu Sep 13 15:45:55 2012
+++ util/cairo-missing/getline.c	Thu Sep 13 15:46:18 2012
@@ -87,4 +87,6 @@
     return ret;
 }
 #undef GETLINE_BUFFER_SIZE
+#else
+int solaris_ld_requires_at_least_one_symbol = 0;
 #endif

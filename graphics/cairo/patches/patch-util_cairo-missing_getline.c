$NetBSD: patch-util_cairo-missing_getline.c,v 1.1 2023/11/14 13:48:19 wiz Exp $

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

$NetBSD: patch-include_stdinc.h,v 1.1 2012/02/16 13:46:52 hans Exp $

--- include/stdinc.h.orig	2008-02-11 03:58:08.000000000 +0100
+++ include/stdinc.h	2012-01-20 00:50:03.416296368 +0100
@@ -46,6 +46,10 @@
 #include <libgen.h>
 #include <dirent.h>
 
+#ifdef __sun
+#undef boolean_t
+#endif
+
 typedef mowgli_boolean_t boolean_t;
 
 #endif

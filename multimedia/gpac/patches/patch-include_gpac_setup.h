$NetBSD: patch-include_gpac_setup.h,v 1.1 2025/10/31 21:46:23 adam Exp $

Fix build on NetBSD: S_IRUSR and other need _NETBSD_SOURCE=1.

--- include/gpac/setup.h.orig	2025-10-31 21:32:04.742649874 +0000
+++ include/gpac/setup.h
@@ -312,7 +312,9 @@ char * my_str_lwr(char *str);
 #include <assert.h>
 
 /*! file descriptor support*/
+#if !defined(__NetBSD__)
 #define GPAC_HAS_FD
+#endif
 
 #if __APPLE__ && defined GPAC_CONFIG_IOS
 #include <TargetConditionals.h>

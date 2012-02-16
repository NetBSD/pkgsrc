$NetBSD: patch-mal_common_AGUtilUnix.h,v 1.1 2012/02/16 17:25:16 hans Exp $

--- mal/common/AGUtilUnix.h.orig	2000-05-14 23:17:36.000000000 +0200
+++ mal/common/AGUtilUnix.h	2012-01-26 17:39:25.909557059 +0100
@@ -46,8 +46,6 @@ extern "C" {
 #include <httpd.h>
 #include <ap.h>
 #endif
-#define snprintf ap_snprintf
-#define vsnprintf ap_vsnprintf
 #endif
 
 #endif /* __unix__ */

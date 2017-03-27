$NetBSD: patch-libgupnp_guul.c,v 1.1 2017/03/27 13:47:50 jperkin Exp $

Find native SunOS libuuid.

--- libgupnp/guul.c.orig	2016-06-20 19:22:31.000000000 +0000
+++ libgupnp/guul.c
@@ -22,8 +22,12 @@
 #include <guul.h>
 
 #if defined(GUUL_PLATFORM_GENERIC) || defined(GUUL_PLATFORM_BSD)
+#ifdef __sun
+#   include <uuid/uuid.h>
+#else
 #   include <uuid.h>
 #endif
+#endif
 
 #if defined(GUUL_PLATFORM_OSX)
 #   include <uuid/uuid.h>

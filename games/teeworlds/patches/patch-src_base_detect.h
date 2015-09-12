$NetBSD: patch-src_base_detect.h,v 1.1 2015/09/12 18:53:17 wiz Exp $

====================================================================
This patch adds NetBSD as a known platform.

Upstream already applied it in their repository, so it should become
unnecessary with later versions.
====================================================================


--- src/base/detect.h.orig
+++ src/base/detect.h
@@ -32,6 +32,13 @@
 	#define CONF_PLATFORM_STRING "freebsd"
 #endif
 
+#if defined(__NetBSD__)
+	#define CONF_FAMILY_UNIX 1
+	#define CONF_FAMILY_STRING "unix"
+	#define CONF_PLATFORM_NETBSD 1
+	#define CONF_PLATFORM_STRING "netbsd"
+#endif
+
 #if defined(__OpenBSD__)
 	#define CONF_FAMILY_UNIX 1
 	#define CONF_FAMILY_STRING "unix"
@@ -78,7 +85,7 @@
 
 /* use gcc endianness definitions when available */
 #if defined(__GNUC__) && !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__sun)
-	#if defined(__FreeBSD__) || defined(__OpenBSD__)
+	#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		#include <sys/endian.h>
 	#else
 		#include <endian.h>

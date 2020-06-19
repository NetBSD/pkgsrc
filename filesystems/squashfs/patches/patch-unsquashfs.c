$NetBSD: patch-unsquashfs.c,v 1.2 2020/06/19 21:17:46 scole Exp $

Some workarounds for not using autoconf

--- unsquashfs.c.orig	2019-08-29 01:58:04.000000000 +0000
+++ unsquashfs.c
@@ -32,8 +32,18 @@
 #include "stdarg.h"
 #include "fnmatch_compat.h"
 
-#include <sys/sysinfo.h>
-#include <sys/sysmacros.h>
+/* XXX need autoconf HAVE_SYS_SYSCTL_H */
+#if ( defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__) || \
+      defined(__FreeBSD__) || defined(__OpenBSD__) )
+ #include <sys/sysctl.h>
+#endif
+
+/* XXX probably others... */
+#if defined(__linux__) 
+ #include <sys/sysinfo.h>
+ #include <sys/sysmacros.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>

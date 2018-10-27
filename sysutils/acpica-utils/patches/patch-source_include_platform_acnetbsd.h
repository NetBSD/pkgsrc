$NetBSD: patch-source_include_platform_acnetbsd.h,v 1.2 2018/10/27 21:44:53 abs Exp $

NetBSD versions prior to 7 lack sem_timedwait() in librt

--- source/include/platform/acnetbsd.h.orig	2015-04-10 17:27:17.000000000 +0200
+++ source/include/platform/acnetbsd.h	2015-12-10 14:15:22.000000000 +0100
@@ -112,4 +112,10 @@
 #define ACPI_USE_SYSTEM_CLIBRARY
 #define ACPI_USE_NATIVE_DIVIDE
 
+/* NetBSD versions prior to 7 lack sem_timedwait() in librt */
+#include <sys/param.h>
+#if (__NetBSD_Version__ < 700000000)       /* NetBSD 7 */
+#define ACPI_USE_ALTERNATE_TIMEOUT
+#endif
+
 #endif /* __ACNETBSD_H__ */

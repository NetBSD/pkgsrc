$NetBSD: patch-include_sys__dependencies.h,v 1.1 2026/05/05 10:21:46 jperkin Exp $

Support illumos.

--- include/sys_dependencies.h.orig	2026-05-05 08:17:10.311811997 +0000
+++ include/sys_dependencies.h
@@ -39,7 +39,7 @@
 #define SWTPM_SYS_DEPENDENCIES_H
 
 #if !defined __OpenBSD__ && !defined __FreeBSD__ && !defined __NetBSD__ \
- && !defined __APPLE__ && !defined __DragonFly__
+ && !defined __APPLE__ && !defined __DragonFly__ && !defined __illumos__
  #define _GNU_SOURCE
  #include <features.h>
 #endif
@@ -70,4 +70,4 @@
 # include <endian.h>
 #endif
 
-#endif /* SWTPM_SYS_DEPENDENCIES_H */
\ No newline at end of file
+#endif /* SWTPM_SYS_DEPENDENCIES_H */

$NetBSD: patch-src_jdk.management_bsd_native_libmanagement__ext_UnixOperatingSystem.c,v 1.1 2019/10/01 12:36:34 tnn Exp $

sys/user.h was removed from NetBSD.

--- src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c
@@ -29,7 +29,9 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/time.h>
+#ifndef __NetBSD__
 #include <sys/user.h>
+#endif
 #include <unistd.h>
 
 #include "jvm.h"

$NetBSD: patch-src_jdk.management_bsd_native_libmanagement__ext_UnixOperatingSystem.c,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c
@@ -29,7 +29,9 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/time.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 #include <unistd.h>
 
 #include "jvm.h"

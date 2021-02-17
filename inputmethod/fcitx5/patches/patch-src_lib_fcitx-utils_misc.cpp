$NetBSD: patch-src_lib_fcitx-utils_misc.cpp,v 1.1 2021/02/17 15:16:25 ryoon Exp $

* NetBSD has no sys/user.h.

--- src/lib/fcitx-utils/misc.cpp.orig	2020-12-25 17:51:34.717115200 +0000
+++ src/lib/fcitx-utils/misc.cpp
@@ -16,7 +16,9 @@
 #include <kvm.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 #elif defined(__APPLE__)
 #include <libproc.h>
 #endif

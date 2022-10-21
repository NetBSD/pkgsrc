$NetBSD: patch-cryptcommon_ZrtpRandom.h,v 1.1 2022/10/21 16:10:37 nros Exp $

* include stdbool.h so that bool is defined in C

--- cryptcommon/ZrtpRandom.h.orig	2020-02-01 18:04:00.000000000 +0000
+++ cryptcommon/ZrtpRandom.h
@@ -28,6 +28,7 @@
 #if !(defined(_WIN32) || defined(_WIN64))
 #include <unistd.h>
 #endif
+#include <stdbool.h>
 #include <stdint.h>
 #include <sys/types.h>
 

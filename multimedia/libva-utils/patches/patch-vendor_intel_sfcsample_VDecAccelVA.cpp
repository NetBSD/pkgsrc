$NetBSD: patch-vendor_intel_sfcsample_VDecAccelVA.cpp,v 1.1 2019/12/29 01:32:53 ryoon Exp $

--- vendor/intel/sfcsample/VDecAccelVA.cpp.orig	2019-08-13 09:22:19.000000000 +0000
+++ vendor/intel/sfcsample/VDecAccelVA.cpp
@@ -32,7 +32,9 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <sys/ioctl.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>

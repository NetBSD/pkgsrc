$NetBSD: patch-.._vendor_lzma-sys-0.1.20_xz-5.2_src_common_mythread.h,v 1.1 2025/12/05 20:32:17 pin Exp $

Add missing header for gettimeofday().

--- ../vendor/lzma-sys-0.1.20/xz-5.2/src/common/mythread.h.orig	2025-11-13 12:05:32.744181097 +0000
+++ ../vendor/lzma-sys-0.1.20/xz-5.2/src/common/mythread.h
@@ -14,6 +14,7 @@
 #define MYTHREAD_H
 
+#include <sys/time.h>
 #include "sysdefs.h"
 
 // If any type of threading is enabled, #define MYTHREAD_ENABLED.
 #if defined(MYTHREAD_POSIX) || defined(MYTHREAD_WIN95) \

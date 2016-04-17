$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util__bsd.cc,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util_bsd.cc.orig	2015-06-08 17:49:21.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util_bsd.cc
@@ -9,6 +9,9 @@
 #include <sys/wait.h>
 
 #include <fcntl.h>
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
 #include <unistd.h>
 
 #include <string>

$NetBSD: patch-ipc_chromium_src_base_process__util__bsd.cc,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Darwin does not provide kvm_getprocs(3). The code for OS_MACOSX is
simply copied from process_util_mac.mm

--- ipc/chromium/src/base/process_util_bsd.cc.orig	2014-10-11 09:06:28.000000000 +0000
+++ ipc/chromium/src/base/process_util_bsd.cc
@@ -9,6 +9,9 @@
 #include <sys/wait.h>
 
 #include <fcntl.h>
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
 #include <unistd.h>
 
 #include <string>

$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util__bsd.cc,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util_bsd.cc.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util_bsd.cc
@@ -10,6 +10,10 @@
 #include <spawn.h>
 #include <sys/wait.h>
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
+
 #include <string>
 
 #include "base/eintr_wrapper.h"

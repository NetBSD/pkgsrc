$NetBSD: patch-src_tl_tl_tlTimer.cc,v 1.1 2026/08/07 00:57:21 mef Exp $

implemented Timer::memory_size() on NetBSD

--- src/tl/tl/tlTimer.cc.orig	2026-08-02 01:50:00.084645671 +0000
+++ src/tl/tl/tlTimer.cc
@@ -34,6 +34,12 @@
 #  include <sys/times.h>
 #  include <unistd.h>
 #  include <libproc.h>
+#elif defined(__NetBSD__)
+#  include <kvm.h>
+#  include <sys/param.h>
+#  include <sys/sysctl.h>
+#  include <sys/times.h>
+#  include <unistd.h>
 #else
 #  include <sys/times.h>
 #  include <unistd.h>
@@ -273,6 +279,36 @@ Timer::memory_size ()
 
   return size_t (memsize) * size_t (getpagesize ());
 
+#elif defined(__NetBSD__)
+  pid_t pid;
+  char errbuf[_POSIX2_LINE_MAX];
+  kvm_t *kd = NULL;
+  struct kinfo_proc2 *p = NULL;
+  int count;
+  int pagesize;
+  size_t memory_size = 0;
+
+  kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf);
+  if (!kd) {
+    tl::error << tr ("Failed to open kvm: ") << errbuf;
+    goto end;
+  }
+
+  pid = getpid();
+  p = kvm_getproc2(kd, KERN_PROC_PID, pid, sizeof(struct kinfo_proc2), &count);
+  if (!p) {
+    tl::error << tr ("Failed to get kvm process: ") << kvm_geterr(kd);
+    goto end;
+  }
+
+  pagesize = getpagesize();
+  memory_size = p->p_vm_rssize * pagesize;
+
+end:
+  if (kd) {
+    kvm_close(kd);
+  }
+  return memory_size;
 #else
 #  error Unsupported platform
 #endif

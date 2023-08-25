$NetBSD: patch-src_base_sysinfo.cc,v 1.2 2023/08/25 16:38:42 adam Exp $

Get mappings from procfs on NetBSD

--- src/base/sysinfo.cc.orig	2023-08-11 19:32:36.000000000 +0000
+++ src/base/sysinfo.cc
@@ -54,7 +54,7 @@
 #include <mach-o/loader.h>    // for iterating over dll's in ProcMapsIter
 #include <sys/types.h>
 #include <sys/sysctl.h>       // how we figure out numcpu's on OS X
-#elif defined __FreeBSD__
+#elif defined __FreeBSD__ || defined __NetBSD__
 #include <sys/sysctl.h>
 #elif defined __sun__         // Solaris
 #include <procfs.h>           // for, e.g., prmap_t
@@ -582,6 +582,13 @@ void ProcMapsIterator::Init(pid_t pid, B
     ConstructFilename("/proc/%d/map", pid, ibuf_, Buffer::kBufSize);
   }
   NO_INTR(fd_ = open(ibuf_, O_RDONLY));
+#elif defined(__NetBSD__)
+  if (pid == 0) {
+    ConstructFilename("/proc/curproc/maps", 1, ibuf_, Buffer::kBufSize);
+  } else {
+    ConstructFilename("/proc/%d/maps", pid, ibuf_, Buffer::kBufSize);
+  }
+  NO_INTR(fd_ = open(ibuf_, O_RDONLY));
 #elif defined(__sun__)
   if (pid == 0) {
     ConstructFilename("/proc/self/map", 1, ibuf_, Buffer::kBufSize);

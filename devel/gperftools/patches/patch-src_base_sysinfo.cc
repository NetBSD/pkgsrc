$NetBSD: patch-src_base_sysinfo.cc,v 1.1 2019/11/28 12:19:58 bouyer Exp $

Get mappings from procfs on NetBSD

--- src/base/sysinfo.cc.orig	2017-11-28 15:38:09.000000000 +0100
+++ src/base/sysinfo.cc	2019-11-27 19:01:54.000000000 +0100
@@ -47,7 +47,7 @@
 #include <mach-o/loader.h>    // for iterating over dll's in ProcMapsIter
 #include <sys/types.h>
 #include <sys/sysctl.h>       // how we figure out numcpu's on OS X
-#elif defined __FreeBSD__
+#elif defined __FreeBSD__ || defined __NetBSD__
 #include <sys/sysctl.h>
 #elif defined __sun__         // Solaris
 #include <procfs.h>           // for, e.g., prmap_t
@@ -273,7 +273,7 @@
 
 // ----------------------------------------------------------------------
 
-#if defined __linux__ || defined __FreeBSD__ || defined __sun__ || defined __CYGWIN__ || defined __CYGWIN32__
+#if defined __linux__ || defined __FreeBSD__ || defined __sun__ || defined __CYGWIN__ || defined __CYGWIN32__ || defined __NetBSD__
 static void ConstructFilename(const char* spec, pid_t pid,
                               char* buf, int buf_size) {
   CHECK_LT(snprintf(buf, buf_size,
@@ -425,7 +425,7 @@
                               char *flags, uint64 *offset,
                               int *major, int *minor, int64 *inode,
                               unsigned *filename_offset) {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   /*
    * It's similar to:
    * sscanf(text, "%"SCNx64"-%"SCNx64" %4s %"SCNx64" %x:%x %"SCNd64" %n",
@@ -518,6 +518,13 @@
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
@@ -575,7 +582,7 @@
                                uint64 *anon_mapping, uint64 *anon_pages,
                                dev_t *dev) {
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__CYGWIN32__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__CYGWIN32__) || defined __NetBSD__
   do {
     // Advance to the start of the next line
     stext_ = nextline_;
@@ -615,7 +622,7 @@
     int64 tmpinode;
     int major, minor;
     unsigned filename_offset = 0;
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
     // for now, assume all linuxes have the same format
     if (!ParseProcMapsLine(
         stext_,

$NetBSD: patch-src_main_cpp_blaze__util__bsd.cc,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- src/main/cpp/blaze_util_bsd.cc.orig	2023-11-29 06:03:37.228876616 +0000
+++ src/main/cpp/blaze_util_bsd.cc
@@ -15,6 +15,8 @@
 #if defined(__FreeBSD__)
 # define HAVE_PROCSTAT
 # define STANDARD_JAVABASE "/usr/local/openjdk8"
+#elif defined(__NetBSD__)
+# define STANDARD_JAVABASE "/usr/pkg/java/openjdk11"
 #elif defined(__OpenBSD__)
 # define STANDARD_JAVABASE "/usr/local/jdk-17"
 #else
@@ -36,6 +38,7 @@
 #include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
+#include <sys/statvfs.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/un.h>
@@ -74,8 +77,8 @@ string GetOutputRoot() {
 }
 
 void WarnFilesystemType(const blaze_util::Path &output_base) {
-  struct statfs buf = {};
-  if (statfs(output_base.AsNativePath().c_str(), &buf) < 0) {
+  struct statvfs buf = {};
+  if (statvfs(output_base.AsNativePath().c_str(), &buf) < 0) {
     BAZEL_LOG(WARNING) << "couldn't get file system type information for '"
                        << output_base.AsPrintablePath()
                        << "': " << strerror(errno);
@@ -112,7 +115,7 @@ string GetSelfPath(const char* argv0) {
   }
   procstat_close(procstat);
   return string(buffer);
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
   // OpenBSD does not provide a way for a running process to find a path to its
   // own executable, so we try to figure out a path by inspecting argv[0]. In
   // theory this is inadequate, since the parent process can set argv[0] to

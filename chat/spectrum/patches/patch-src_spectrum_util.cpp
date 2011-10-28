$NetBSD: patch-src_spectrum_util.cpp,v 1.1 2011/10/28 00:27:58 schnoebe Exp $

revise the memory usage statistics handling to work only on FreeBSD
(where it was designed.)

--- src/spectrum_util.cpp.orig	2011-06-11 13:17:44.000000000 +0000
+++ src/spectrum_util.cpp
@@ -28,7 +28,7 @@
 #include "protocols/abstractprotocol.h"
 #include "transport.h"
 #include <sys/param.h>
-#ifdef BSD
+#if defined(__FreeBSD_version) /* should also include a tested version, but */
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/param.h>
@@ -117,7 +117,7 @@ const std::string generateUUID() {
 }
 
 #ifndef WIN32
-#ifdef BSD
+#ifdef __FreeBSD_version
 void process_mem_usage(double& vm_usage, double& resident_set) {
 	int mib[4];
 	size_t size;
@@ -151,7 +151,7 @@ void process_mem_usage(double& vm_usage,
 	resident_set = (double) (proc.ki_rssize * pagesize / 1024);
 	vm_usage = (double) proc.ki_size;
 }
-#else /* BSD */
+#else /* __FreeBSD_version */
 void process_mem_usage(double& vm_usage, double& resident_set) {
 	using std::ios_base;
 	using std::ifstream;
@@ -190,7 +190,7 @@ void process_mem_usage(double& vm_usage,
 	vm_usage     = vsize / 1024.0;
 	resident_set = rss * page_size_kb;
 }
-#endif /* else BSD */
+#endif /* else __FreeBSD_version */
 #endif /* WIN32 */
 
 std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {

$NetBSD: patch-src_openrct2_platform_Platform.Linux.cpp,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/platform/Platform.Linux.cpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/platform/Platform.Linux.cpp
@@ -7,12 +7,12 @@
  * OpenRCT2 is licensed under the GNU General Public License version 3.
  *****************************************************************************/
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__linux__) && !defined(__ANDROID__))
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || (defined(__linux__) && !defined(__ANDROID__))
 
 #    include <limits.h>
 #    include <pwd.h>
 #    include <vector>
-#    if defined(__FreeBSD__)
+#    if defined(__FreeBSD__) || defined(__NetBSD__)
 #        include <stddef.h>
 #        include <sys/param.h>
 #        include <sys/sysctl.h>
@@ -129,7 +129,7 @@ namespace Platform
         {
             log_fatal("failed to read /proc/self/exe");
         }
-#    elif defined(__FreeBSD__)
+#    elif defined(__FreeBSD__) || defined(__NetBSD__)
         const int32_t mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
         auto exeLen = sizeof(exePath);
         if (sysctl(mib, 4, exePath, &exeLen, nullptr, 0) == -1)

$NetBSD: patch-source_core_slang-io.cpp,v 1.1 2026/09/24 18:41:26 ktnb Exp $

use NetBSD sysctl(3) instead of the Linux way.

--- source/core/slang-io.cpp.orig	2026-09-23 15:19:58.072004104 +0000
+++ source/core/slang-io.cpp
@@ -22,7 +22,7 @@
 // clang-format on
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__) || SLANG_APPLE_FAMILY || SLANG_WASM
+#if SLANG_LINUX_FAMILY || SLANG_APPLE_FAMILY || SLANG_WASM
 #include <fcntl.h>
 #include <unistd.h>
 // For Path::find
@@ -37,6 +37,10 @@
 #include <mach-o/dyld.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #include <filesystem>
 #include <limits.h> /* PATH_MAX */
 #include <stdio.h>
@@ -1025,6 +1029,19 @@ static SlangResult _calcExectuablePath(char* outPath, 
     }
     // Zero terminate
     outPath[resSize] = 0;
+    return SLANG_OK;
+#elif defined(__NetBSD__)
+    int mib[4] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+    size_t len = bufferSize;
+    if (::sysctl(mib, 4, outPath, &len, nullptr, 0) != 0)
+    {
+        if (errno == ENOMEM)
+        {
+            *ioSize = len;
+            return SLANG_E_BUFFER_TOO_SMALL;
+        }
+        return SLANG_FAIL;
+    }
     return SLANG_OK;
 #else
     String text = Slang::File::readAllText("/proc/self/maps");

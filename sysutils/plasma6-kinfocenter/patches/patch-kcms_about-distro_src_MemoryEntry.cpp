$NetBSD: patch-kcms_about-distro_src_MemoryEntry.cpp,v 1.1 2025/12/23 08:48:26 markd Exp $

get Memory for NetBSD

--- kcms/about-distro/src/MemoryEntry.cpp.orig	2025-11-04 14:59:20.000000000 +0000
+++ kcms/about-distro/src/MemoryEntry.cpp
@@ -12,8 +12,9 @@
 #ifdef UDEV_FOUND
 #include <libudev.h>
 #endif
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
 // clang-format off
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 // clang-format on
@@ -58,6 +59,11 @@ std::optional<qlonglong> MemoryEntry::ca
     }
 
     return totalBytes;
+#elif defined(Q_OS_OPENBSD)
+    long phys_pages = sysconf(_SC_PHYS_PAGES);
+    long pagesize = sysconf(_SC_PAGESIZE);
+    if (phys_pages != -1 && pagesize != -1)
+        return ((uint64_t)phys_pages * (uint64_t)pagesize);
 #endif
 
     /*
@@ -86,6 +92,15 @@ std::optional<qlonglong> MemoryEntry::ca
     if (sysctlbyname("hw.physmem", &memory, &len, NULL, 0) == 0) {
         return memory;
     }
+#elif defined(Q_OS_NETBSD)
+    /* Stuff for sysctl */
+    size_t len;
+
+    unsigned long memory;
+    len = sizeof(memory);
+    if (sysctlbyname("hw.physmem64", &memory, &len, NULL, 0) == 0) {
+        return memory;
+    }
 #endif
 
     return {};

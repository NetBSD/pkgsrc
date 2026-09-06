$NetBSD: patch-kcms_about-distro_src_MemoryEntry.cpp,v 1.2 2026/09/06 10:23:30 markd Exp $

get Memory for NetBSD

--- kcms/about-distro/src/MemoryEntry.cpp.orig	2026-08-04 09:20:46.000000000 +0000
+++ kcms/about-distro/src/MemoryEntry.cpp
@@ -12,7 +12,7 @@
 #ifdef UDEV_FOUND
 #include <libudev.h>
 #endif
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
 // clang-format off
 #include <unistd.h>
 #include <sys/types.h>
@@ -104,6 +104,15 @@ std::optional<qlonglong> MemoryEntry::ca
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

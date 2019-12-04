$NetBSD: patch-src_hotspot_cpu_aarch64_vm__version__aarch64.cpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

NetBSD/evbarm-aarch64 support

--- src/hotspot/cpu/aarch64/vm_version_aarch64.cpp.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
@@ -195,7 +195,7 @@ void VM_Version::get_processor_features(
     }
     fclose(f);
   }
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   char buf[512];
   int cpu_lines = 0;
   unsigned long auxv = os_get_processor_features();

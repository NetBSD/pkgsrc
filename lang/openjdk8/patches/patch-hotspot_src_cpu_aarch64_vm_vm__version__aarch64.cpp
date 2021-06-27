$NetBSD: patch-hotspot_src_cpu_aarch64_vm_vm__version__aarch64.cpp,v 1.1 2021/06/27 18:30:26 tnn Exp $

NetBSD/evbarm-aarch64 support

--- hotspot/src/cpu/aarch64/vm/vm_version_aarch64.cpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/cpu/aarch64/vm/vm_version_aarch64.cpp
@@ -188,7 +188,7 @@ void VM_Version::get_processor_features(
     }
     fclose(f);
   }
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   char buf[512];
   int cpu_lines = 0;
   unsigned long auxv = os_get_processor_features();

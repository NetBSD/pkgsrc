$NetBSD: patch-lscpu.c,v 1.2 2023/07/11 19:32:00 vins Exp $

* Fix architecture detection on FreeBSD.
* Fix CPU model detection on NetBSD.

--- lscpu.c.orig	2018-05-05 02:25:31.000000000 +0000
+++ lscpu.c
@@ -926,7 +926,11 @@ int main(int argc, char **argv) 
     };
 
     sysctl_get_cpu_info sysctl_array[] = {
+#ifdef __FreeBSD__
+        {HW_MACHINE_ARCH, gen_info.arch, sizeof(gen_info.arch), "HW_MACHINE_ARCH"},
+#else
         {HW_MACHINE, gen_info.arch, sizeof(gen_info.arch), "HW_MACHINE"},
+#endif
         {HW_BYTEORDER, &(gen_info.byte_order), sizeof(gen_info.byte_order), "HW_BYTEORDER"},
         {HW_MODEL, gen_info.model, sizeof(gen_info.model), "HW_MODEL"},
         {HW_NCPU, &(gen_info.active_cpu_num), sizeof(gen_info.active_cpu_num), "HW_NCPU"},
@@ -972,6 +976,14 @@ int main(int argc, char **argv) 
         }
     }
 
+#if defined(__NetBSD__) && (defined(__amd64__) || defined(__i386__))
+{
+       size_t sz = sizeof (gen_info.model);
+       if (sysctlbyname("machdep.cpu_brand", gen_info.model, &sz, NULL, 0) == -1)
+               err(1, "MACHDEP.CPU_BRAND");
+}
+#endif
+
 #if defined(__amd64__) || defined(__i386__)
     get_x86_cpu_info(&x86_info);
 #endif

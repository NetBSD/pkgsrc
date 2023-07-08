$NetBSD: patch-lscpu.c,v 1.1 2023/07/08 21:29:33 vins Exp $

Fix architecture detection on FreeBSD.

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

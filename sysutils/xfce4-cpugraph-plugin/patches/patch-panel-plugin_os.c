$NetBSD: patch-panel-plugin_os.c,v 1.3 2019/07/13 00:40:22 gutteridge Exp $

Fix NetBSD support.

--- panel-plugin/os.c.orig	2019-07-02 23:18:51.000000000 +0000
+++ panel-plugin/os.c
@@ -226,7 +226,7 @@ read_cpu_data (CpuData *data, guint nb_c
     data[0].load = 0;
     for (i = 1; i <= nb_cpu; i++)
     {
-        cp_time1 = cp_time + CPUSTATE * (i - 1);
+        cp_time1 = cp_time + CPUSTATES * (i - 1);
         used = cp_time1[CP_USER] + cp_time1[CP_NICE] + cp_time1[CP_SYS] + cp_time1[CP_INTR];
         total = used + cp_time1[CP_IDLE];
 

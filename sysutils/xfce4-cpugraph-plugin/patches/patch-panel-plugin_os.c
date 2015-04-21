$NetBSD: patch-panel-plugin_os.c,v 1.1 2015/04/21 08:56:40 jperkin Exp $

Fix NetBSD support.
--- panel-plugin/os.c.orig	2012-04-18 21:27:33.000000000 +0000
+++ panel-plugin/os.c
@@ -211,7 +211,7 @@ gboolean read_cpu_data( CpuData *data, g
 	data[0].load = 0;
 	for( i = 1 ; i <= nb_cpu ; i++ )
 	{
-		cp_time1 = cp_time + CPUSTATE * (i - 1);
+		cp_time1 = cp_time + CPUSTATES * (i - 1);
 		used = cp_time1[CP_USER] + cp_time1[CP_NICE] + cp_time1[CP_SYS] + cp_time1[CP_INTR];
 		total = used + cp_time1[CP_IDLE];
 

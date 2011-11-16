$NetBSD: patch-xymond_rrd_do__vmstat.c,v 1.1 2011/11/16 21:12:35 spz Exp $

at least NetBSD 4-5.99 vmstat gives you two disks if you don't specify any,
no matter how many you actually have

--- xymond/rrd/do_vmstat.c.orig	2011-07-31 21:01:52.000000000 +0000
+++ xymond/rrd/do_vmstat.c
@@ -154,13 +154,12 @@ static vmstat_layout_t vmstat_netbsd_lay
 	{ 10, "sr" },
 	{ 11, "dsk_f0" },
 	{ 12, "dsk_m0" },
-	{ 13, "dsk_w0" },
-	{ 14, "cpu_int" },
-	{ 15, "cpu_syc" },
-	{ 16, "cpu_csw" },
-	{ 17, "cpu_usr" },
-	{ 18, "cpu_sys" },
-	{ 19, "cpu_idl" },
+	{ 13, "cpu_int" },
+	{ 14, "cpu_syc" },
+	{ 15, "cpu_csw" },
+	{ 16, "cpu_usr" },
+	{ 17, "cpu_sys" },
+	{ 18, "cpu_idl" },
 	{ -1, NULL }
 };
 

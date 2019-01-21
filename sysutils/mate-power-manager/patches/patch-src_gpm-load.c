$NetBSD: patch-src_gpm-load.c,v 1.1 2019/01/21 13:12:32 youri Exp $

Add cpu times calculations for *BSD.

--- src/gpm-load.c.orig	2018-01-29 14:50:11.000000000 +0000
+++ src/gpm-load.c
@@ -151,6 +151,33 @@ out:
 	return FALSE;
 }
 
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+
+/**
+ * gpm_load_get_cpu_values:
+ * @cpu_idle: The idle time reported by the CPU
+ * @cpu_total: The total time reported by the CPU
+ * Return value: Success of reading of the kern.cp_time sysctl.
+ **/
+static gboolean
+gpm_load_get_cpu_values (long unsigned *cpu_idle, long unsigned *cpu_total)
+{
+	long cpts[CPUSTATES];
+	size_t length;
+
+	length = sizeof (cpts);
+	if (sysctlbyname ("kern.cp_time", cpts, &length, NULL, 0)) {
+		return FALSE;
+	}
+
+	*cpu_idle = (unsigned long) cpts[CP_IDLE];
+	*cpu_total = (unsigned long) (cpts[CP_USER] + cpts[CP_NICE] + \
+			cpts[CP_SYS] + cpts[CP_IDLE] + cpts[CP_INTR]);
+
+	return TRUE;
+}
+
+
 #else
 
 /**

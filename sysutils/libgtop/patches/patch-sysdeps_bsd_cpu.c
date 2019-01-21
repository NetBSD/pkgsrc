$NetBSD: patch-sysdeps_bsd_cpu.c,v 1.1 2019/01/21 03:31:06 youri Exp $

Fix multi-processor cpu load calculations

--- sysdeps/bsd/cpu.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/bsd/cpu.c
@@ -24,6 +24,8 @@
 #include <glibtop/error.h>
 #include <glibtop/cpu.h>
 
+#include <err.h>
+
 #include <glibtop_suid.h>
 
 #ifdef __NetBSD__
@@ -84,6 +86,7 @@ glibtop_get_cpu_p (glibtop *server, glib
 	/* sysctl vars*/
 	struct clockinfo ci;
 	size_t length;
+	int ncpu, i = 0;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_CPU), 0);
 
@@ -93,6 +96,10 @@ glibtop_get_cpu_p (glibtop *server, glib
 	if (server->sysdeps.cpu == 0)
 		return;
 
+	size_t len = sizeof(ncpu);
+	if (sysctlbyname("hw.ncpu", &ncpu, &len, NULL, 0) < 0)
+		errx(1, "Failed to get hw.cpu\n");
+
 #ifdef KERN_CP_TIME
 	length = sizeof (cpts);
 	if (sysctl (mib2, mib_length, cpts, &length, NULL, 0)) {
@@ -125,18 +132,43 @@ glibtop_get_cpu_p (glibtop *server, glib
 	/* set iowait (really just interrupt) time */
 	buf->iowait = cpts [CP_INTR];
 
-	/* set frequency */
-	/*
-	   FIXME --  is hz, tick, profhz or stathz wanted?
-	   buf->frequency = sysctl("kern.clockrate", ...);
-
-	   struct clockinfo
-	*/
 	buf->frequency = ci.hz;
+
 	/* set total */
 	buf->total = cpts [CP_USER] + cpts [CP_NICE]
 		+ cpts [CP_SYS] + cpts [CP_IDLE];
 
+
+	u_int64_t *cp_times;
+        length = sizeof(cp_times[0]) * CPUSTATES * ncpu;
+        cp_times = g_malloc(length);
+	int mib[] = { CTL_KERN, KERN_CP_TIME };
+	if (sysctl (mib, 2, cp_times, &length, NULL, 0) < 0) {
+		g_free(cp_times);
+		errx(1,"Failed to get kern.cp_time\n");
+	}
+	for (i = 0; i < ncpu; i++) {
+		if (cp_times) {
+			int offset = i * CPUSTATES;
+			buf->xcpu_user[i] = cp_times[offset + CP_USER]; 
+			buf->xcpu_nice[i] = cp_times[offset + CP_NICE]; 
+			buf->xcpu_sys[i] = cp_times[offset + CP_SYS];
+			buf->xcpu_idle[i] = cp_times[offset + CP_IDLE];
+			buf->xcpu_irq[i] = cp_times[offset + CP_INTR];
+		} else {
+			buf->xcpu_user[i] = cpts[CP_USER] / ncpu;
+			buf->xcpu_nice[i] = cpts[CP_NICE] / ncpu;
+			buf->xcpu_sys[i] = cpts[CP_SYS] / ncpu;
+			buf->xcpu_idle[i] = cpts[CP_IDLE] / ncpu;
+			buf->xcpu_irq[i] = cpts[CP_INTR] / ncpu;
+		}
+		buf->xcpu_total[i] = buf->xcpu_user[i] + buf->xcpu_nice[i] \
+				     + buf->xcpu_sys[i] + buf->xcpu_idle[i] \
+				     + buf->xcpu_irq[i];
+	}
+
+	g_free(cp_times);
+
 	/* Set the flags last. */
 	buf->flags = _glibtop_sysdeps_cpu;
 }

$NetBSD: patch-sysdeps_solaris_procopenfiles.c,v 1.2 2016/04/28 22:18:58 jperkin Exp $

Implement stub functions for Solaris to at least get the package to
build.  Help filling them out with actual data would be very welcome.

--- sysdeps/solaris/procopenfiles.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/solaris/procopenfiles.c
@@ -22,7 +22,10 @@
 #include <config.h>
 #include <glibtop.h>
 #include <glibtop/error.h>
+#include <glibtop/procaffinity.h>
 #include <glibtop/procopenfiles.h>
+#include <glibtop/procwd.h>
+#include <glibtop/sysinfo.h>
 #include <sys/types.h>
 #include <fcntl.h>
 #include <sys/stat.h>
@@ -126,3 +129,67 @@ glibtop_get_proc_open_files_s (glibtop *
 
 	return (glibtop_open_files_entry*)g_array_free(entries, FALSE);
 }
+
+/*
+ * Stub functions, currently unimplemented on Solaris
+ */
+void
+_glibtop_init_proc_wd_s (glibtop *server)
+{
+	server->sysdeps.proc_wd =
+	    (1 << GLIBTOP_PROC_WD_EXE) |
+	    (1 << GLIBTOP_PROC_WD_ROOT) |
+	    (1 << GLIBTOP_PROC_WD_NUMBER);
+}
+char **
+glibtop_get_proc_wd_s (glibtop *server, glibtop_proc_wd *buf, pid_t pid)
+{
+	memset (buf, 0, sizeof (glibtop_proc_wd));
+	return NULL;
+}
+
+void
+_glibtop_init_proc_affinity_s(glibtop *server)
+{
+	server->sysdeps.proc_affinity =
+	    (1 << GLIBTOP_PROC_AFFINITY_NUMBER) |
+	    (1 << GLIBTOP_PROC_AFFINITY_ALL);
+}
+guint16 *
+glibtop_get_proc_affinity_s(glibtop *server, glibtop_proc_affinity *buf, pid_t pid)
+{
+	memset(buf, 0, sizeof (glibtop_proc_affinity));
+	return NULL;
+}
+
+static const unsigned long _glibtop_sysdeps_sysinfo =
+(1L << GLIBTOP_SYSINFO_CPUINFO);
+
+static glibtop_sysinfo sysinfo = { .flags = 0 };
+
+static void
+init_sysinfo (glibtop *server)
+{
+	guint ncpus = sysconf(_SC_NPROCESSORS_CONF);
+
+	glibtop_init_s (&server, GLIBTOP_SYSDEPS_CPU, 0);
+
+	for (sysinfo.ncpu = 0;
+	     sysinfo.ncpu < GLIBTOP_NCPU && sysinfo.ncpu < ncpus;
+	     sysinfo.ncpu++) {
+		glibtop_entry * const cpuinfo = &sysinfo.cpuinfo[sysinfo.ncpu];
+		cpuinfo->labels = g_ptr_array_new ();
+		cpuinfo->values = g_hash_table_new_full(g_str_hash,
+							g_str_equal,
+							NULL, g_free);
+	}
+
+	sysinfo.flags = _glibtop_sysdeps_sysinfo;
+}
+
+const glibtop_sysinfo *
+glibtop_get_sysinfo_s (glibtop *server)
+{
+	init_sysinfo (server);
+	return &sysinfo;
+}

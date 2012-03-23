$NetBSD: patch-sysdeps_freebsd_procwd.c,v 1.1 2012/03/23 17:29:52 marino Exp $

--- sysdeps/freebsd/procwd.c.orig	2012-03-23 16:53:25.085432000 +0000
+++ sysdeps/freebsd/procwd.c
@@ -100,8 +100,6 @@ parse_output(const char *output, glibtop
 char**
 glibtop_get_proc_wd_s(glibtop *server, glibtop_proc_wd *buf, pid_t pid)
 {
-	int exe_mib[4];
-	size_t len;
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
 	struct kinfo_file *freep, *kif;
 	GPtrArray *dirs;
@@ -116,6 +114,16 @@ glibtop_get_proc_wd_s(glibtop *server, g
 #endif
 
 	memset (buf, 0, sizeof (glibtop_proc_wd));
+#if defined(__DragonFly__)
+	char path[MAXPATHLEN];
+
+	g_snprintf(path, sizeof(path), "/proc/%u/file", pid);
+	if (safe_readlink(path, buf->exe, sizeof(buf->exe)))
+		buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
+#else
+	int exe_mib[4];
+	size_t len;
+
 	len = 0;
 
 	exe_mib[0] = CTL_KERN;
@@ -129,6 +137,7 @@ glibtop_get_proc_wd_s(glibtop *server, g
 		if (sysctl(exe_mib, 4, buf->exe, &len, NULL, 0) == 0)
 			buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
 	}
+#endif
 
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
 #ifndef HAVE_KINFO_GETFILE

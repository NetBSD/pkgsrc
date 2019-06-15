$NetBSD: patch-osdep-netbsd.c,v 1.4 2019/06/15 09:42:52 leot Exp $

Add support for KERN_PROC_CWD.

--- osdep-netbsd.c.orig	2019-03-26 14:34:58.000000000 +0000
+++ osdep-netbsd.c
@@ -135,11 +135,24 @@ osdep_get_cwd(int fd)
 	static char	target[PATH_MAX + 1];
 	char		*path;
 	pid_t		pgrp;
-	ssize_t		n;
 
 	if ((pgrp = tcgetpgrp(fd)) == -1)
 		return (NULL);
 
+#ifdef KERN_PROC_CWD
+	int		mib[4];
+	size_t		len;
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC_ARGS;
+	mib[2] = pgrp;
+	mib[3] = KERN_PROC_CWD;
+	len = sizeof(target);
+	if (sysctl(mib, 4, target, &len, NULL, 0) == 0)
+		return (target);
+#else
+	ssize_t		n;
+
 	xasprintf(&path, "/proc/%lld/cwd", (long long) pgrp);
 	n = readlink(path, target, sizeof(target) - 1);
 	free(path);
@@ -147,6 +160,7 @@ osdep_get_cwd(int fd)
 		target[n] = '\0';
 		return (target);
 	}
+#endif
 
 	return (NULL);
 }

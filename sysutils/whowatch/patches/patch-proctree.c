$NetBSD: patch-proctree.c,v 1.2 2017/06/23 18:57:13 kamil Exp $

Add DragonFly support (kernel proc can return pid of -1, skip)
kinfo structure is unique on DragonFly

<sys/user.h> is freebsdism in this usage-context, it's now absent in NetBSD 8.99.1

--- proctree.c.orig	2000-06-06 09:03:28.000000000 +0000
+++ proctree.c
@@ -16,8 +16,10 @@
 #ifdef HAVE_PROCESS_SYSCTL
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
 #endif
+#endif
 
 #include "proctree.h"
 
@@ -170,8 +172,14 @@ int update_tree(void del(void*))
 #ifdef HAVE_PROCESS_SYSCTL
 	el = get_all_info(&pi);
 	for(i = 0; i < el; i++) {
+#ifdef __DragonFly__
+		if (pi[i].kp_pid == -1) continue;
+		p = validate_proc(pi[i].kp_pid);
+		q = validate_proc(pi[i].kp_ppid);
+#else
 		p = validate_proc(pi[i].kp_proc.p_pid);
 		q = validate_proc(pi[i].kp_eproc.e_ppid);
+#endif
 #else
 
 	d=opendir(PROCDIR);

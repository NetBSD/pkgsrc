$NetBSD: patch-proctree.c,v 1.1 2012/08/08 18:37:07 marino Exp $

Add DragonFly support (kernel proc can return pid of -1, skip)
kinfo structure is unique on DragonFly

--- proctree.c.orig	2000-06-06 09:03:28.000000000 +0000
+++ proctree.c
@@ -170,8 +170,14 @@ int update_tree(void del(void*))
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

$NetBSD: patch-src_task-manager-bsd.c,v 1.1 2015/04/21 08:56:41 jperkin Exp $

Attempt to bring netbsd, DragonFly while keeping OpenBSD support.
--- src/task-manager-bsd.c.orig	2014-12-23 20:40:14.000000000 +0000
+++ src/task-manager-bsd.c
@@ -25,8 +25,18 @@
 #include <sys/param.h>
 #include <sys/sched.h>
 #include <sys/sysctl.h>
+
+#ifdef __DragonFly__
+#include <sys/kinfo.h>
+#include <sys/resource.h>
+#include <vm/vm_param.h>
+#else
 /* for swapctl() */
 #include <sys/swap.h>
+#include <uvm/uvm_extern.h>
+#endif
+
+#include <kvm.h>
 /* for strlcpy() */
 #include <string.h>
 /* for getpagesize() */
@@ -46,108 +56,107 @@ char	*state_abbrev[] = {
 
 gboolean get_task_list (GArray *task_list)
 {
-	int mib[6];
-	size_t size;
-#ifdef __OpenBSD__
-	struct kinfo_proc *kp;
-#else
-	struct kinfo_proc2 *kp;
-#endif
-	Task t;
-	struct passwd *passwdp;
-	char **args;
-	gchar* buf;
-	int nproc, i;
+        Task t;
+#ifdef __NetBSD__
+	struct kinfo_proc2 *kp = NULL;
+#else
+        struct kinfo_proc *kp = NULL;
+#endif
+
+        struct passwd *passwdp;
+        char **args = NULL;
+        char *buf = NULL;
+        unsigned int i = 0;
+        int nproc = 0;
+
+
+        /* get process number, stolen from ps */
+        /* example with kvm functions */
+        char errbuf[_POSIX2_LINE_MAX];
+        kvm_t *kdp = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, errbuf);
+        if (kdp == NULL)
+                errx(1, "%s", errbuf);
+
+        /* fill kinfo_proc2 structure */
+        /* XXX does it return sleeping processes ? */
+#ifdef	__OpenBSD__
+	if (!(kp = kvm_getprocs(kdp, KERN_PROC_ALL, 0,
+	            sizeof(struct kinfo_proc), &nproc)))
+#elif __DragonFly__
+	if (!(kp = kvm_getprocs(kdp, KERN_PROC_ALL, 0, &nproc)))
+#else /* probably NetBSD or MirBSD */
+        if (!(kp = kvm_getproc2(kdp, KERN_PROC_ALL, 0,
+                    sizeof(struct kinfo_proc2), &nproc)))
+#endif
+                err(1, "%s", kvm_geterr(kdp));
+
+        for (i = 0; i < nproc; i++) {
+		if (kp[i].p_pid < 1)
+			continue; /* not valid */
 
-	mib[0] = CTL_KERN;
-#ifdef __OpenBSD__
-	mib[1] = KERN_PROC;
-#else
-	mib[1] = KERN_PROC2;
-#endif
-	mib[2] = KERN_PROC_ALL;
-	mib[3] = 0;
-#ifdef __OpenBSD__
-	mib[4] = sizeof(struct kinfo_proc);
-#else
-	mib[4] = sizeof(struct kinfo_proc2);
-#endif
-	mib[5] = 0;
-	if (sysctl(mib, 6, NULL, &size, NULL, 0) < 0)
-#ifdef __OpenBSD__
-		errx(1, "could not get kern.proc size");
-#else
-		errx(1, "could not get kern.proc2 size");
-#endif
-	size = 5 * size / 4;		/* extra slop */
-	if ((kp = malloc(size)) == NULL)
-		errx(1,"failed to allocate memory for proc structures");
-#ifdef __OpenBSD__
-	mib[5] = (int)(size / sizeof(struct kinfo_proc));
-#else
-	mib[5] = (int)(size / sizeof(struct kinfo_proc2));
-#endif
-	if (sysctl(mib, 6, kp, &size, NULL, 0) < 0)
-#ifdef __OpenBSD__
-		errx(1, "could not read kern.proc");
-	nproc = (int)(size / sizeof(struct kinfo_proc));
-#else
-		errx(1, "could not read kern.proc2");
-	nproc = (int)(size / sizeof(struct kinfo_proc2));
-#endif
-	for (i=0 ; i < nproc ; i++)
-	{
-#ifdef __OpenBSD__
-		struct kinfo_proc p = kp[i];
-#else
+                /* get per-process information in our entry */
+#ifdef __NetBSD__
 		struct kinfo_proc2 p = kp[i];
+#else
+                struct kinfo_proc p = kp[i];
 #endif
-		t.pid = p.p_pid;
-		t.ppid = p.p_ppid;
-		t.uid = p.p_uid;
-		t.prio = p.p_priority - PZERO;
-		t.vsz = p.p_vm_dsize + p.p_vm_ssize + p.p_vm_tsize;
-		t.vsz *= getpagesize();
-		t.rss = p.p_vm_rssize * getpagesize();
-		g_snprintf(t.state, sizeof t.state, "%s", state_abbrev[p.p_stat]);
-		g_strlcpy(t.name, p.p_comm, strlen(p.p_comm) + 1);
-		/* shamelessly stolen from top/machine.c */
-		if (!P_ZOMBIE(&p)) {
-			size = 128;
-			if ((args = malloc(size)) == NULL)
-				errx(1,"failed to allocate memory for argv structures at %zu", size);
-			for (;; size *= 2) {
-				if ((args = realloc(args, size)) == NULL)
-					errx(1,"failed to allocate memory (size=%zu) for argv structures of pid %d", size, t.pid);
-				mib[0] = CTL_KERN;
-				mib[1] = KERN_PROC_ARGS;
-				mib[2] = t.pid;
-				mib[3] = KERN_PROC_ARGV;
-				if (sysctl(mib, 4, args, &size, NULL, 0) == 0)
-					break;
-				if (errno != ENOMEM) { /* ESRCH: process disappeared */
-					 /* printf ("process with pid %d disappeared, errno=%d\n", t.pid, errno); */
-					args[0] ='\0';
-					args[1] = NULL;
-					break;
-				}
-			}
-			buf = g_strjoinv(" ", args);
-			g_assert(g_utf8_validate(buf, -1, NULL));
-			g_strlcpy(t.cmdline, buf, sizeof t.cmdline);
-			g_free(buf);
-			free(args);
-		}
-
-		t.cpu_user = (100.0 * ((double) p.p_pctcpu / FSCALE));
-		t.cpu_system = 0; /* TODO ? */
-		/* get username from uid */
-		passwdp = getpwuid(t.uid);
-		if(passwdp != NULL && passwdp->pw_name != NULL)
-			g_strlcpy(t.uid_name, passwdp->pw_name, sizeof t.uid_name);
-		g_array_append_val(task_list, t);
-	}
-	free(kp);
+
+#ifdef	__DragonFly__
+                t.pid = p.kp_pid;
+                t.ppid = p.kp_ppid;
+                t.uid = p.kp_uid;
+                t.prio = p.kp_nice;
+                t.vsz = p.kp_vm_dsize + p.kp_vm_ssize + p.kp_vm_tsize;
+                t.vsz *= getpagesize();
+                t.rss = p.kp_vm_rssize * getpagesize();
+                g_snprintf(t.state, sizeof(t.state), "%s",
+                    state_abbrev[p.kp_stat]);
+                g_strlcpy(t.name, p.kp_comm, strlen(p.kp_comm) + 1);
+#else
+                t.pid = p.p_pid;
+                t.ppid = p.p_ppid;
+                t.uid = p.p_uid;
+	        t.prio = p.p_priority - PZERO;
+                t.vsz = p.p_vm_dsize + p.p_vm_ssize + p.p_vm_tsize;
+                t.vsz *= getpagesize();
+                t.rss = p.p_vm_rssize * getpagesize();
+                g_snprintf(t.state, sizeof(t.state), "%s",
+                    state_abbrev[p.p_stat]);
+                g_strlcpy(t.name, p.p_comm, strlen(p.p_comm) + 1);
+#endif
+#ifdef __DragonFly__
+                if (!(p.kp_stat == SDEAD)) { /* same as OpenBSD P_ZOMBIE */
+#else
+                if (!(p.p_stat == SDEAD)) {
+#endif
+                        /* get process args */
+#ifdef __NetBSD__
+                        args = kvm_getargv2(kdp, &kp[i], BUFSIZ);
+#else
+			args = kvm_getargv(kdp, &kp[i], BUFSIZ);
+#endif
+                        if (args != NULL) {
+                                buf = g_strjoinv(" ", args);
+                                g_strlcpy(t.cmdline, buf,
+                                    sizeof(t.cmdline));
+                        }
+#ifdef __DragonFly__
+			t.cpu_user = 0; /* TODO */
+#else
+                        t.cpu_user = (100.0 *
+                            ((double) p.p_pctcpu / FSCALE));
+#endif
+                        t.cpu_system = 0; /* XXX TODO */
+                        passwdp = getpwuid(t.uid);
+                        if (passwdp != NULL && passwdp->pw_name != NULL)
+                                g_strlcpy(t.uid_name, passwdp->pw_name,
+                                    sizeof(t.uid_name));
+                        g_array_append_val(task_list, t);
+                }
+        }
+	g_free(args);
+        g_free(buf);
+        g_free(kp);
 
 	return TRUE;
 }
@@ -156,26 +165,26 @@ gboolean
 pid_is_sleeping (guint pid)
 {
 	int mib[6];
-#ifdef __OpenBSD__
-	struct kinfo_proc kp;
-	size_t size = sizeof(struct kinfo_proc);
-#else
+#ifdef __NetBSD__
 	struct kinfo_proc2 kp;
 	size_t size = sizeof(struct kinfo_proc2);
+#else
+	struct kinfo_proc kp;
+	size_t size = sizeof(struct kinfo_proc);
 #endif
 
 	mib[0] = CTL_KERN;
-#ifdef __OpenBSD__
-	mib[1] = KERN_PROC;
-#else
+#ifdef __NetBSD__
 	mib[1] = KERN_PROC2;
+#else
+	mib[1] = KERN_PROC;
 #endif
 	mib[2] = KERN_PROC_PID;
 	mib[3] = pid;
-#ifdef __OpenBSD__
-	mib[4] = sizeof(struct kinfo_proc);
-#else
+#ifdef __NetBSD__
 	mib[4] = sizeof(struct kinfo_proc2);
+#else
+	mib[4] = sizeof(struct kinfo_proc);
 #endif
 	mib[5] = 1;
 	if (sysctl(mib, 6, &kp, &size, NULL, 0) < 0)
@@ -184,7 +193,11 @@ pid_is_sleeping (guint pid)
 #else
 		errx(1, "could not read kern.proc2 for pid %d", pid);
 #endif
+#ifdef __DragonFly__
+	return (kp.kp_stat == SSTOP ? TRUE : FALSE);
+#else
 	return (kp.p_stat == SSTOP ? TRUE : FALSE);
+#endif
 }
 
 gboolean get_cpu_usage (gushort *cpu_count, gfloat *cpu_user, gfloat *cpu_system)
@@ -192,12 +205,31 @@ gboolean get_cpu_usage (gushort *cpu_cou
 	static gulong cur_user = 0, cur_system = 0, cur_total = 0;
 	static gulong old_user = 0, old_system = 0, old_total = 0;
 
-	int mib[] = {CTL_KERN, KERN_CPTIME};
- 	glong cp_time[CPUSTATES];
- 	gsize size = sizeof( cp_time );
+#if defined(__DragonFly__)
+	int mib[2];
+	struct kinfo_cputime percpu;
+	size_t size = sizeof(percpu);
+	uint64_t cp_time[CPUSTATES];
+
+	if (sysctlbyname("kern.cputime", &percpu, &size, NULL, 0) < 0)
+		errx(1, "failed to sysctl kern.cputime");
+
+	cp_time[CP_USER] = percpu.cp_user;
+	cp_time[CP_NICE] = percpu.cp_nice;
+	cp_time[CP_SYS]	 = percpu.cp_sys;
+	cp_time[CP_INTR] = percpu.cp_intr;
+	cp_time[CP_IDLE] = percpu.cp_idle;
+#else
+#ifdef __NetBSD__
+	int mib[] = {CTL_KERN, KERN_CP_TIME};
+#else
+        int mib[] = {CTL_KERN, KERN_CPTIME};
+#endif
+	glong cp_time[CPUSTATES];
+	gsize size = sizeof( cp_time );
 	if (sysctl(mib, 2, &cp_time, &size, NULL, 0) < 0)
 		errx(1,"failed to get kern.cptime");
-
+#endif
 	old_user = cur_user;
 	old_system = cur_system;
 	old_total = cur_total;
@@ -217,65 +249,72 @@ gboolean get_cpu_usage (gushort *cpu_cou
 		errx(1,"failed to get cpu count");
 	return TRUE;
 }
-
 /* vmtotal values in #pg */
 #define pagetok(nb) ((nb) * (getpagesize()))
 
 gboolean get_memory_usage (guint64 *memory_total, guint64 *memory_free, guint64 *memory_cache, guint64 *memory_buffers, guint64 *swap_total, guint64 *swap_free)
 {
 #ifdef __OpenBSD__
-	int mib[] = {CTL_VM, VM_UVMEXP};
-	struct uvmexp  uvmexp;
+        int mib[] = {CTL_VM, VM_UVMEXP};
+        struct uvmexp  uvmexp;
 #else
-	int mib[] = {CTL_VM, VM_METER};
-	struct vmtotal vmtotal;
+        int mib[] = {CTL_VM, VM_METER};
+        struct vmtotal vmtotal;
 #endif
-	struct swapent *swdev;
-	int nswap, i;
-	size_t size;
-#ifdef __OpenBSD__
-	size = sizeof(uvmexp);
-	if (sysctl(mib, 2, &uvmexp, &size, NULL, 0) < 0)
-		errx(1,"failed to get vm.uvmexp");
-	/* cheat : rm = tot used, add free to get total */
-	*memory_free = pagetok((guint64)uvmexp.free);
-	*memory_total = pagetok((guint64)uvmexp.npages);
-	*memory_cache = 0;
-	*memory_buffers = 0; /*pagetok(uvmexp.npages - uvmexp.free - uvmexp.active);*/
-#else
-	size = sizeof(vmtotal);
-	if (sysctl(mib, 2, &vmtotal, &size, NULL, 0) < 0)
-		errx(1,"failed to get vm.meter");
-	/* cheat : rm = tot used, add free to get total */
-	*memory_total = pagetok(vmtotal.t_rm + vmtotal.t_free);
-	*memory_free = pagetok(vmtotal.t_free);
-	*memory_cache = 0;
-	*memory_buffers = pagetok(vmtotal.t_rm - vmtotal.t_arm);
-#endif
-
-	/* get swap stats */
-	if ((nswap = swapctl(SWAP_NSWAP, 0, 0)) == 0)
-		errx(1,"failed to get swap device count");
-
-	if ((swdev = calloc(nswap, sizeof(*swdev))) == NULL)
-		errx(1,"failed to allocate memory for swdev structures");
-
-	if (swapctl(SWAP_STATS, swdev, nswap) == -1) {
-		free(swdev);
-		errx(1,"failed to get swap stats");
-	}
-
-	/* Total things up */
-	*swap_total = *swap_free = 0;
-	for (i = 0; i < nswap; i++) {
-		if (swdev[i].se_flags & SWF_ENABLE) {
-			*swap_free += (swdev[i].se_nblks - swdev[i].se_inuse);
-			*swap_total += swdev[i].se_nblks;
-		}
-	}
-	*swap_total *= DEV_BSIZE;
-	*swap_free *= DEV_BSIZE;
-	free(swdev);
-	return TRUE;
+        struct swapent *swdev;
+        int nswap, i;
+        size_t size;
+#ifdef __OpenBSD__
+        size = sizeof(uvmexp);
+        if (sysctl(mib, 2, &uvmexp, &size, NULL, 0) < 0)
+                errx(1,"failed to get vm.uvmexp");
+        /* cheat : rm = tot used, add free to get total */
+        *memory_free = pagetok((guint64)uvmexp.free);
+        *memory_total = pagetok((guint64)uvmexp.npages);
+        *memory_cache = 0;
+        *memory_buffers = 0; /*pagetok(uvmexp.npages - uvmexp.free - uvmexp.active);*/
+#else
+        size = sizeof(vmtotal);
+        if (sysctl(mib, 2, &vmtotal, &size, NULL, 0) < 0)
+                errx(1,"failed to get vm.meter");
+
+        mib[0] = CTL_HW;
+        mib[1] = HW_PHYSMEM64;
+        uint64_t physmem;
+        size_t physmemlen = sizeof(physmem);
+
+        if (sysctl(mib, 2, &physmem, &physmemlen, NULL, 0) < 0)
+            errx(1, "failed to get physmem");
+
+        *memory_total = (guint64)physmem;
+        *memory_free = pagetok((guint64)vmtotal.t_free);
+        *memory_cache = 0;
+        *memory_buffers = pagetok(vmtotal.t_rm - vmtotal.t_arm);
+#endif
+
+        /* get swap stats */
+        if ((nswap = swapctl(SWAP_NSWAP, 0, 0)) == 0)
+                errx(1,"failed to get swap device count");
+
+        if ((swdev = calloc(nswap, sizeof(*swdev))) == NULL)
+                errx(1,"failed to allocate memory for swdev structures");
+
+        if (swapctl(SWAP_STATS, swdev, nswap) == -1) {
+                free(swdev);
+                errx(1,"failed to get swap stats");
+        }
+
+        /* Total things up */
+        *swap_total = *swap_free = 0;
+        for (i = 0; i < nswap; i++) {
+                if (swdev[i].se_flags & SWF_ENABLE) {
+                        *swap_free += (swdev[i].se_nblks - swdev[i].se_inuse);
+                        *swap_total += swdev[i].se_nblks;
+                }
+        }
+        *swap_total *= DEV_BSIZE;
+        *swap_free *= DEV_BSIZE;
+        free(swdev);
+        return TRUE;
 }
 

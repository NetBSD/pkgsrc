$NetBSD: patch-src_processes.c,v 1.8 2017/11/21 16:02:20 he Exp $

Add a port to NetBSD.

--- src/processes.c.orig	2017-06-06 18:13:54.693164693 +0000
+++ src/processes.c
@@ -97,14 +97,16 @@
 /* #endif KERNEL_LINUX */
 
 #elif HAVE_LIBKVM_GETPROCS &&                                                  \
-    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD)
+    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD)
 #include <kvm.h>
 #include <sys/param.h>
 #include <sys/proc.h>
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 /* #endif HAVE_LIBKVM_GETPROCS && (HAVE_STRUCT_KINFO_PROC_FREEBSD ||
- * HAVE_STRUCT_KINFO_PROC_OPENBSD) */
+ * HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD) */
 
 #elif HAVE_PROCINFO_H
 #include <procinfo.h>
@@ -286,10 +288,15 @@ static void ps_fill_details(const procst
 /* #endif KERNEL_LINUX */
 
 #elif HAVE_LIBKVM_GETPROCS &&                                                  \
-    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD)
+    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD)
 static int pagesize;
+
+#if KERNEL_NETBSD
+int maxslp;
+#endif
+
 /* #endif HAVE_LIBKVM_GETPROCS && (HAVE_STRUCT_KINFO_PROC_FREEBSD ||
- * HAVE_STRUCT_KINFO_PROC_OPENBSD) */
+ * HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD) */
 
 #elif HAVE_PROCINFO_H
 static struct procentry64 procentry[MAXPROCENTRY];
@@ -673,10 +680,21 @@ static int ps_init(void) {
 /* #endif KERNEL_LINUX */
 
 #elif HAVE_LIBKVM_GETPROCS &&                                                  \
-    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD)
+    (HAVE_STRUCT_KINFO_PROC_FREEBSD || HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD)
+#if KERNEL_NETBSD
+  int mib[2];
+  size_t size;
+
+  mib[0] = CTL_VM;
+  mib[1] = VM_MAXSLP;
+  size = sizeof(maxslp);
+  if (sysctl(mib, 2, &maxslp, &size, NULL, 0) == -1)
+    maxslp = 20;    /* reasonable default? */
+#endif
+
   pagesize = getpagesize();
 /* #endif HAVE_LIBKVM_GETPROCS && (HAVE_STRUCT_KINFO_PROC_FREEBSD ||
- * HAVE_STRUCT_KINFO_PROC_OPENBSD) */
+ * HAVE_STRUCT_KINFO_PROC_OPENBSD || HAVE_STRUCT_KINFO_PROC2_NETBSD) */
 
 #elif HAVE_PROCINFO_H
   pagesize = getpagesize();
@@ -2074,6 +2092,197 @@ static int ps_read(void) {
     ps_submit_proc_list(ps_ptr);
 /* #endif HAVE_LIBKVM_GETPROCS && HAVE_STRUCT_KINFO_PROC_FREEBSD */
 
+#elif HAVE_LIBKVM_GETPROCS && HAVE_STRUCT_KINFO_PROC2_NETBSD
+  int running  = 0;
+  int sleeping = 0;
+  int zombies  = 0;
+  int stopped  = 0;
+  int blocked  = 0;
+  int idle     = 0;
+  int wait     = 0;
+
+  kvm_t *kd;
+  char errbuf[_POSIX2_LINE_MAX];
+  struct kinfo_proc2 *procs;          /* array of processes */
+  struct kinfo_proc2 *proc_ptr = NULL;
+  struct kinfo_proc2 *p;
+  int count;                         /* returns number of processes */
+  int i;
+  int l, nlwps;
+  struct kinfo_lwp *kl;
+
+  procstat_t *ps_ptr;
+  process_entry_t pse;
+
+  ps_list_reset ();
+
+  /* Open the kvm interface, get a descriptor */
+  kd = kvm_openfiles (NULL, NULL, NULL, KVM_NO_FILES, errbuf);
+  if (kd == NULL)
+  {
+    ERROR ("processes plugin: Cannot open kvm interface: %s",
+      errbuf);
+    return (0);
+  }
+
+  /* Get the list of processes. */
+  procs = kvm_getproc2(kd, KERN_PROC_ALL, 0,
+                       sizeof(struct kinfo_proc2), &count);
+  if (procs == NULL)
+  {
+    ERROR ("processes plugin: Cannot get kvm processes list: %s",
+           kvm_geterr(kd));
+    kvm_close (kd);
+    return (0);
+  }
+
+  /* Iterate through the processes in kinfo_proc */
+  for (i = 0; i < count; i++)
+  {
+    /* Create only one process list entry per _process_, i.e.
+     * filter out threads (duplicate PID entries). */
+    if ((proc_ptr == NULL) || (proc_ptr->p_pid != procs[i].p_pid))
+    {
+      char cmdline[CMDLINE_BUFFER_SIZE] = "";
+      _Bool have_cmdline = 0;
+
+      proc_ptr = &(procs[i]);
+      /* Don't probe system processes and processes without arguments */
+      if (((procs[i].p_flag & P_SYSTEM) == 0)
+          && (procs[i].p_comm[0] != 0))
+      {
+        char **argv;
+        int argc;
+        int status;
+
+        /* retrieve the arguments */
+        argv = kvm_getargv2 (kd, proc_ptr, 0);
+        argc = 0;
+        if ((argv != NULL) && (argv[0] != NULL))
+        {
+          while (argv[argc] != NULL)
+            argc++;
+
+          status = strjoin (cmdline, sizeof (cmdline), argv, argc, " ");
+          if (status < 0)
+            WARNING ("processes plugin: Command line did not fit into buffer.");
+          else
+            have_cmdline = 1;
+        }
+      } /* if (process has argument list) */
+
+      memset(&pse, 0, sizeof(pse));
+      pse.id = procs[i].p_pid;
+
+      pse.num_proc = 1;
+      pse.num_lwp = procs[i].p_nlwps;
+
+      pse.vmem_size = procs[i].p_uru_maxrss * pagesize;
+      pse.vmem_rss = procs[i].p_vm_rssize * pagesize;
+      pse.vmem_data = procs[i].p_vm_dsize * pagesize;
+      pse.vmem_code = procs[i].p_vm_tsize * pagesize;
+      pse.stack_size = procs[i].p_vm_ssize * pagesize;
+      pse.vmem_minflt_counter = procs[i].p_uru_minflt;
+      pse.vmem_majflt_counter = procs[i].p_uru_majflt;
+
+      pse.cpu_user_counter = 0;
+      pse.cpu_system_counter = 0;
+      /* context switch counters not implemented */
+      pse.cswitch_vol = -1;
+      pse.cswitch_invol = -1;
+
+      /*
+       * The u-area might be swapped out, and we can't get
+       * at it because we have a crashdump and no swap.
+       * If it's here fill in these fields, otherwise, just
+       * leave them 0.
+       */
+      if (procs[i].p_flag & P_INMEM)
+      {
+        pse.cpu_user_counter = procs[i].p_uutime_usec
+          + (1000000lu * procs[i].p_uutime_sec);
+        pse.cpu_system_counter = procs[i].p_ustime_usec
+          + (1000000lu * procs[i].p_ustime_sec);
+      }
+
+      /* no I/O data */
+      pse.io_rchar = -1;
+      pse.io_wchar = -1;
+      pse.io_syscr = procs[i].p_uru_inblock;
+      pse.io_syscw = procs[i].p_uru_oublock;
+
+      /* file descriptor count not implemented */
+      pse.num_fd = 0;
+
+      /* Number of memory mappings */
+      pse.num_maps = 0;
+
+      /* context switch counters not implemented */
+      pse.cswitch_vol = -1;
+      pse.cswitch_invol = -1;
+
+      ps_list_add (procs[i].p_comm, have_cmdline ? cmdline : NULL, &pse);
+    } /* if ((proc_ptr == NULL) || (proc_ptr->ki_pid != procs[i].ki_pid)) */
+
+     /* system processes' LWPs end up in "running" state */
+    if ((procs[i].p_flag & P_SYSTEM) != 0)
+      continue;
+
+    switch (procs[i].p_realstat)
+    {
+    case SSTOP:
+    case SACTIVE:
+    case SIDL:
+      p = &(procs[i]);
+      /* get info about LWPs */
+      kl = kvm_getlwps(kd, p->p_pid, (u_long)p->p_paddr,
+                       sizeof(struct kinfo_lwp), &nlwps);
+
+      for (l = 0; kl && l < nlwps; l++) {
+        switch (kl[l].l_stat) {
+        case LSONPROC:
+        case LSRUN:
+          running++;
+          break;
+        case LSSLEEP:
+          if (kl[l].l_flag & L_SINTR) {
+            if (kl[l].l_slptime > maxslp)
+              idle++;
+            else
+              sleeping++;
+          } else
+              blocked++;
+          break;
+        case LSSTOP:
+          stopped++; break;
+        case LSIDL:
+          idle++; break;
+        }
+      }
+      break;
+    case SZOMB:
+    case SDYING:
+    case SDEAD:
+      zombies++; break;
+
+    }
+  }
+
+  kvm_close(kd);
+
+  ps_submit_state ("running",  running);
+  ps_submit_state ("sleeping", sleeping);
+  ps_submit_state ("zombies",  zombies);
+  ps_submit_state ("stopped",  stopped);
+  ps_submit_state ("blocked",  blocked);
+  ps_submit_state ("idle",     idle);
+  ps_submit_state ("wait",     wait);
+
+  for (ps_ptr = list_head_g; ps_ptr != NULL; ps_ptr = ps_ptr->next)
+       ps_submit_proc_list (ps_ptr);
+/* #endif HAVE_LIBKVM_GETPROCS && HAVE_STRUCT_KINFO_PROC2_NETBSD */
+
+
 #elif HAVE_LIBKVM_GETPROCS && HAVE_STRUCT_KINFO_PROC_OPENBSD
   int running = 0;
   int sleeping = 0;

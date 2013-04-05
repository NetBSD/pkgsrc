$NetBSD: patch-agent_mibgroup_hardware_cpu_cpu__sysctl.c,v 1.4 2013/04/05 07:59:20 tron Exp $

--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c	2013-04-04 20:55:47.000000000 -0400
@@ -10,6 +10,7 @@
 
 #include <stdlib.h>
 #include <unistd.h>
+#include <errno.h>
 #include <sys/types.h>
 
 #if defined(__FreeBSD__)
@@ -24,6 +25,9 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
+#ifdef HAVE_UVM_UVM_EXTERN_H
+#include <uvm/uvm_extern.h>
+#endif
 #ifdef HAVE_VM_VM_PARAM_H
 #include <vm/vm_param.h>
 #endif
@@ -43,7 +47,7 @@
     int               i, n;
     size_t            siz;
     int               ncpu_mib[]  = { CTL_HW, HW_NCPU };
-#if !(defined(__NetBSD__) && ( defined(__i386__) || defined(__x86_64__) ) )
+#if !(defined(__FreeBSD__) && ( defined(__i386__) || defined(__x86_64__) ) )
     int               model_mib[] = { CTL_HW, HW_MODEL };
 #endif
     char              descr[ SNMP_MAXBUF ];
@@ -51,14 +55,17 @@
     strcpy(cpu->name, "Overall CPU statistics");
 
     siz = sizeof(n);
-    sysctl(ncpu_mib, 2, &n, &siz, NULL, 0);
+    if (sysctl(ncpu_mib, 2, &n, &siz, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl hw.ncpu failed (errno %d)\n", errno);
     if ( n <= 0 )
         n = 1;   /* Single CPU system */
     siz = sizeof(descr);
-#if defined(__NetBSD__) && ( defined(__i386__) || defined(__x86_64__) )
-    sysctlbyname("machdep.cpu_brand", descr, &siz, NULL, 0);
+#if defined(__FreeBSD__) && ( defined(__i386__) || defined(__x86_64__) )
+    if (sysctlbyname("machdep.cpu_brand", descr, &siz, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl machdep.cpu_brand failed (errno %d)\n", errno)
 #else
-    sysctl(model_mib, 2, descr, &siz, NULL, 0);
+    if (sysctl(model_mib, 2, descr, &siz, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl hw.model failed (errno %d)\n", errno);
 #endif
     for ( i = 0; i < n; i++ ) {
         cpu = netsnmp_cpu_get_byIdx( i, 1 );
@@ -174,9 +181,11 @@
     netsnmp_cpu_info *cpu = netsnmp_cpu_get_byIdx( -1, 0 );
 
 #if (defined(__FreeBSD__) || defined(__NetBSD__))
-    sysctlbyname("kern.cp_time", cpu_stats, &cpu_size, NULL, 0);
+    if (sysctlbyname("kern.cp_time", cpu_stats, &cpu_size, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl kern.cp_time failed (errno %d)\n", errno);
 #else
-    sysctl(cpu_mib, 2,  cpu_stats, &cpu_size, NULL, 0);
+    if (sysctl(cpu_mib, 2,  cpu_stats, &cpu_size, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl kern.cpu failed (errno %d)\n", errno);
 #endif
     cpu->user_ticks = (unsigned long long)cpu_stats[CP_USER];
     cpu->nice_ticks = (unsigned long long)cpu_stats[CP_NICE];
@@ -190,7 +199,8 @@
          * Interrupt/Context Switch statistics
          *   XXX - Do these really belong here ?
          */
-    sysctl(mem_mib, 2, &mem_stats, &mem_size, NULL, 0);
+    if (sysctl(mem_mib, 2, &mem_stats, &mem_size, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl vm.vm_meter failed (errno %d)\n", errno);
     cpu->nInterrupts  = (unsigned long long)mem_stats.NS_VM_INTR;
     cpu->nCtxSwitches = (unsigned long long)mem_stats.NS_VM_SWTCH;
     cpu->swapIn       = (unsigned long long)mem_stats.NS_VM_SWAPIN;
@@ -201,11 +211,37 @@
 #ifdef NS_VM_PAGEOUT
     cpu->pageOut      = (unsigned long long)mem_stats.NS_VM_PAGEOUT;
 #endif
+#if defined(__NetBSD__)
+    {
+	NETSNMP_CPU_STATS *ncpu_stats;
+	size_t ncpu_size = sizeof(*ncpu_stats) * cpu_num * CPUSTATES;
+	ncpu_stats = malloc(ncpu_size);
+	int i;
+	if (ncpu_stats == NULL) {
+	    snmp_log(LOG_ERR, "no memory for kern.cp_time (errno %d)\n", errno);
+	    return;
+	}
+	if (sysctlbyname("kern.cp_time", ncpu_stats, &ncpu_size, NULL, 0) == -1)
+	    snmp_log(LOG_ERR, "sysctl kern.cp_time failed (errno %d)\n", errno);
+	for (i = 0; i < cpu_num; i++) {
+	    netsnmp_cpu_info  *ncpu = netsnmp_cpu_get_byIdx( i, 1 );
+	    size_t j = i * CPUSTATES;
+	    ncpu->user_ticks = (unsigned long long)ncpu_stats[j + CP_USER];
+	    ncpu->nice_ticks = (unsigned long long)ncpu_stats[j + CP_NICE];
+	    ncpu->sys2_ticks = (unsigned long long)ncpu_stats[j + CP_SYS]+cpu_stats[j + CP_INTR];
+	    ncpu->kern_ticks = (unsigned long long)ncpu_stats[j + CP_SYS];
+	    ncpu->idle_ticks = (unsigned long long)ncpu_stats[j + CP_IDLE];
+	    ncpu->intrpt_ticks = (unsigned long long)ncpu_stats[j + CP_INTR];
+	}
+	free(ncpu_stats);
+    }
+#endif
 
 #ifdef NETSNMP_KERN_MCPU
     mcpu_size  = cpu_num*sizeof(NETSNMP_KERN_MCPU_TYPE);
     mcpu_stats = malloc(mcpu_size);
-    sysctl(mcpu_mib, 2, mcpu_stats, &mcpu_size, NULL, 0);
+    if (sysctl(mcpu_mib, 2, mcpu_stats, &mcpu_size, NULL, 0) == -1)
+	snmp_log(LOG_ERR, "sysctl kern.mcpu failed (errno %d)\n", errno);
     for ( i = 0; i < cpu_num; i++ ) {
         cpu = netsnmp_cpu_get_byIdx( i, 0 );
         /* XXX - per-CPU statistics - mcpu_mib[i].??? */

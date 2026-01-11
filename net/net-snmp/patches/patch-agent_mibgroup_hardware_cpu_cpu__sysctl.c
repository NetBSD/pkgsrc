$NetBSD: patch-agent_mibgroup_hardware_cpu_cpu__sysctl.c,v 1.9 2026/01/11 05:07:59 wiz Exp $

--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig	2025-12-20 15:03:33.000000000 +0000
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c
@@ -10,6 +10,7 @@
 
 #include <stdlib.h>
 #include <unistd.h>
+#include <errno.h>
 #include <sys/types.h>
 
 #if defined(freebsd3)
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
@@ -46,7 +50,7 @@ void init_cpu_sysctl( void ) {
     int               i, n;
     size_t            siz;
     int               ncpu_mib[]  = { CTL_HW, HW_NCPU };
-#if !(defined(__NetBSD__) && ( defined(__i386__) || defined(__x86_64__) ) )
+#if !(defined(__FreeBSD__) && ( defined(__i386__) || defined(__x86_64__) ) )
     int               model_mib[] = { CTL_HW, HW_MODEL };
 #endif
     char              descr[ SNMP_MAXBUF ];
@@ -174,7 +178,7 @@ struct __vmmeter {
     /*
      * Load the latest CPU usage statistics
      */
-int netsnmp_cpu_arch_load( netsnmp_cache *cache, void *magic ) {
+int __attribute__((optimize("O0"))) netsnmp_cpu_arch_load( netsnmp_cache *cache, void *magic ) {
 
     /*
      * Strictly speaking, BSDi ought to use
@@ -253,6 +257,32 @@ int netsnmp_cpu_arch_load( netsnmp_cache *cache, void 
 #endif
 #ifdef NS_VM_PAGEOUT
     cpu->pageOut      = mem_stats.NS_VM_PAGEOUT;
+#endif
+
+#if defined(__NetBSD__)
+    {
+	NETSNMP_CPU_STATS *ncpu_stats;
+	int i;
+	size_t ncpu_size = sizeof(*ncpu_stats) * cpu_num * CPUSTATES;
+	ncpu_stats = malloc(ncpu_size);
+	if (ncpu_stats == NULL) {
+	    snmp_log(LOG_ERR, "no memory for kern.cp_time (errno %d)\n", errno);
+	    return -1;
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
 #endif
 
 #ifdef NETSNMP_KERN_MCPU

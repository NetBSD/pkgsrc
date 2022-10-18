$NetBSD: patch-agent_mibgroup_ucd-snmp_memory__netbsd1.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/ucd-snmp/memory_netbsd1.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/ucd-snmp/memory_netbsd1.c
@@ -165,7 +165,7 @@ var_extensible_mem(struct variable *vp,
     static char     errmsg[1024];
 
     static struct uvmexp uvmexp;
-    int             uvmexp_size = sizeof(uvmexp);
+    size_t          uvmexp_size = sizeof(uvmexp);
     int             uvmexp_mib[] = { CTL_VM, VM_UVMEXP };
     static struct vmtotal total;
     size_t          total_size = sizeof(total);
@@ -181,13 +181,22 @@ var_extensible_mem(struct variable *vp,
     /*
      * Memory info 
      */
-    sysctl(uvmexp_mib, 2, &uvmexp, &uvmexp_size, NULL, 0);
-    sysctl(total_mib, 2, &total, &total_size, NULL, 0);
+    if (sysctl(uvmexp_mib, 2, &uvmexp, &uvmexp_size, NULL, 0) == -1) {
+        snmp_log(LOG_ERR, "sysctl VM_UVMEXP failed (errno %d)\n", errno);
+        return NULL;
+    }
+    if (sysctl(total_mib, 2, &total, &total_size, NULL, 0) == -1) {
+        snmp_log(LOG_ERR, "sysctl VM_METER failed (errno %d)\n", errno);
+        return NULL;
+    }
 
     /*
      * Physical memory 
      */
-    sysctl(phys_mem_mib, 2, &phys_mem, &phys_mem_size, NULL, 0);
+    if (sysctl(phys_mem_mib, 2, &phys_mem, &phys_mem_size, NULL, 0) == -1) {
+        snmp_log(LOG_ERR, "sysctl HW_USERMEM failed (errno %d)\n", errno);
+        return NULL;
+    }
 
     long_ret = 0;               /* set to 0 as default */
 

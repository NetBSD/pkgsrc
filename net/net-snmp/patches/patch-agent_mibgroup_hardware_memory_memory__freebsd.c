$NetBSD: patch-agent_mibgroup_hardware_memory_memory__freebsd.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/hardware/memory/memory_freebsd.c
@@ -36,6 +36,12 @@ int netsnmp_mem_arch_load( netsnmp_cache
     long           pagesize;
     int            nswap;
 
+#ifdef dragonfly
+    struct vmstats vms;
+    size_t vms_size = sizeof(vms);
+    size_t vmem_size = sizeof(struct vmmeter);
+#endif
+
 #if !defined(VM_TOTAL)
     unsigned int   free_mem;
     size_t         free_size = sizeof(free_mem);
@@ -76,11 +82,17 @@ int netsnmp_mem_arch_load( netsnmp_cache
     sysctlbyname("vm.stats.vm.v_inactive_count", &inact_count, &inact_size, NULL, 0);
     sysctlbyname("vfs.bufspace",    &bufspace,    &buf_size, NULL, 0);
     sysctlbyname("vfs.maxbufspace", &maxbufspace, &buf_size, NULL, 0);
+#ifdef dragonfly
+    pagesize = getpagesize();
+    sysctlbyname("vm.vmstats", &vms, &vms_size, NULL, 0);
+    sysctlbyname("vm.vmmeter", &vmem, &vmem_size, NULL, 0);
+#else
 #ifndef freebsd4
     pagesize = 1024;
 #else
     pagesize = getpagesize();
 #endif
+#endif
 
     /*
      * ... and save this in a standard form.
@@ -91,6 +103,11 @@ int netsnmp_mem_arch_load( netsnmp_cache
     } else {
         if (!mem->descr)
              mem->descr = strdup("Physical memory");
+#ifdef dragonfly
+        mem->units = vms.v_page_size;
+        mem->size  = vms.v_cache_max;
+        mem->free  = vms.v_cache_max - vms.v_cache_count;
+#else
         mem->units = pagesize;
         mem->size  = phys_mem/pagesize;
 #if !defined(VM_TOTAL)
@@ -98,6 +115,7 @@ int netsnmp_mem_arch_load( netsnmp_cache
 #else
         mem->free  = total.t_free;
 #endif
+#endif
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_USERMEM, 1 );

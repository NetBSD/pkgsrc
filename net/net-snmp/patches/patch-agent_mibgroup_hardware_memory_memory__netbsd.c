$NetBSD: patch-agent_mibgroup_hardware_memory_memory__netbsd.c,v 1.2 2013/04/04 19:59:07 christos Exp $

--- agent/mibgroup/hardware/memory/memory_netbsd.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ agent/mibgroup/hardware/memory/memory_netbsd.c	2013-04-04 15:09:23.000000000 -0400
@@ -48,8 +48,8 @@
     int             uvmexp_mib[] = { CTL_VM, VM_UVMEXP };
     int             total_mib[] = { CTL_VM, VM_METER };
 #else
-    unsigned int    bufspace;
-    unsigned int    maxbufspace;
+    uint64_t        bufspace;
+    uint64_t        maxbufspace;
     size_t          buf_size  = sizeof(bufspace);
 #endif
 
@@ -102,6 +102,7 @@
         mem->units = pagesize;
         mem->size  = phys_mem/pagesize;
         mem->free  = total.t_free;
+	mem->other = -1;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_USERMEM, 1 );
@@ -113,6 +114,7 @@
         mem->units = pagesize;
         mem->size  = user_mem/pagesize;
         mem->free  = uvmexp.free;
+	mem->other = -1;
     }
 
 #if 1
@@ -125,6 +127,7 @@
         mem->units = pagesize;
         mem->size  = total.t_vm;
         mem->free  = total.t_avm;
+	mem->other = -1;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SHARED, 1 );
@@ -136,6 +139,7 @@
         mem->units = pagesize;
         mem->size  = total.t_vmshr;
         mem->free  = total.t_avmshr;
+	mem->other = -1;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SHARED2, 1 );
@@ -147,6 +151,7 @@
         mem->units = pagesize;
         mem->size  = total.t_rmshr;
         mem->free  = total.t_armshr;
+	mem->other = -1;
     }
 #endif
 
@@ -174,7 +179,8 @@
              mem->descr = strdup("Memory buffers");
         mem->units = 1024;
         mem->size  =  maxbufspace            /1024;
-        mem->size  = (maxbufspace - bufspace)/1024;
+        mem->free  = (maxbufspace - bufspace)/1024;
+	mem->other = -1;
     }
 #endif
 
@@ -199,18 +205,28 @@
          * If there's only one swap device, don't bother
          */
     n = swapctl( SWAP_NSWAP, NULL, 0 );
-    if ( n <= 1 )
+    if ( n <= 1 ) {
+	if (n == -1)
+	    snmp_log_perror("error getting swap");
         return;
+    }
 
-    s = (struct swapent*)calloc(n, sizeof(struct swapent));
-    swapctl( SWAP_STATS, s, n );
-
+    s = calloc(n, sizeof(struct swapent));
+    if (s == NULL) {
+        snmp_log_perror("Out of memory for swap");
+	return;
+    }
+    if (swapctl( SWAP_STATS, s, n ) == -1) {
+	snmp_log_perror("error getting swap");
+	return;
+    }
     for (i = 0; i < n; ++i) {
         mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SWAP+1+i, 1 );
-        if (!mem)
+        if (!mem) {
+	    snmp_log_perror("no swapindex");
             continue;
+	}
         if (!mem->descr) {
-         /* sprintf(buf, "swap #%d", s[i].se_dev); */
             sprintf(buf, "swap %s",  s[i].se_path);
             mem->descr = strdup( buf );
         }
@@ -219,5 +235,6 @@
         mem->free  = s[i].se_nblks - s[i].se_inuse;
         mem->other = -1;
     }
+/*###238 [cc] error: expected identifier or '(' before '}' token%%%*/
 }
 #endif

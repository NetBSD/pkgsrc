$NetBSD: patch-target_hppa_mem__helper.c,v 1.1 2019/04/25 11:33:02 skrll Exp $

--- target/hppa/mem_helper.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ target/hppa/mem_helper.c
@@ -154,8 +154,7 @@ int hppa_get_physical_address(CPUHPPASta
 
     if (unlikely(!(prot & type))) {
         /* The access isn't allowed -- Inst/Data Memory Protection Fault.  */
-        ret = (type & PAGE_EXEC ? EXCP_IMP :
-               prot & PAGE_READ ? EXCP_DMP : EXCP_DMAR);
+        ret = (type & PAGE_EXEC) ? EXCP_IMP : EXCP_DMAR;
         goto egress;
     }
 

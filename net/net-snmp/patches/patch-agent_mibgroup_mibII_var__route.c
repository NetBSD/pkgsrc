$NetBSD: patch-agent_mibgroup_mibII_var__route.c,v 1.2 2024/02/21 10:21:01 wiz Exp $

Fix for systems with RTF_LLDATA in place of RTF_LLINFO.

--- agent/mibgroup/mibII/var_route.c.orig	2023-08-15 20:32:01.000000000 +0000
+++ agent/mibgroup/mibII/var_route.c
@@ -956,8 +956,12 @@ load_rtentries(struct radix_node *pt)
         }
 #ifdef CHECK_RT_FLAGS
         if (((rt.rt_flags & RTF_CLONING) != RTF_CLONING)
+#ifdef RTF_LLDATA
+            && ((rt.rt_flags & RTF_LLDATA) != RTF_LLDATA)) {
+#else
             && ((rt.rt_flags & RTF_LLINFO) != RTF_LLINFO)) {
 #endif
+#endif
             /*
              * check for space and malloc 
              */

$NetBSD: patch-agent_mibgroup_var__route.c,v 1.1 2016/04/29 19:47:21 adam Exp $

Fix for systems with RTF_LLDATA in place of RTF_LLINFO.

--- agent/mibgroup/mibII/var_route.c.orig	2016-04-29 19:35:23.000000000 +0000
+++ agent/mibgroup/mibII/var_route.c
@@ -954,8 +954,12 @@ load_rtentries(struct radix_node *pt)
         }
 #if CHECK_RT_FLAGS
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

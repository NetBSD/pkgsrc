$NetBSD: patch-dyn__load.c,v 1.1 2014/10/29 17:01:09 wiz Exp $

Current GC_FirstDLOpenedLinkMap() for NetBSD calls dlinfo(RTLD_SELF,
RTLD_DI_LINKMAP, &lm) to find link_map.  So it will find link_map of
libgc.

With guile's case, libgc is link to libguile and libguile is linked to
the guile command, so libgc is not the first one in the link_map chain.

That's why, data section of libguile, where scm_protects exists, isn't
added to GC root and GC_is_visible fails.

--- dyn_load.c.orig	2014-06-03 06:08:02.000000000 +0000
+++ dyn_load.c
@@ -687,8 +687,16 @@ GC_FirstDLOpenedLinkMap(void)
     if( cachedResult == 0 ) {
 #     if defined(NETBSD) && defined(RTLD_DI_LINKMAP)
         struct link_map *lm = NULL;
-        if (!dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &lm))
-            cachedResult = lm;
+        if (!dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &lm) && lm != NULL) {
+            /*
+             * Now, lm points link_map object of libgc.  Since it
+             * might not be the first dynamically linked object,
+             * try to find it (object next to the main object).
+             */
+            while (lm->l_prev)
+                lm = lm->l_prev;
+            cachedResult = lm->l_next;
+        }
 #     else
         int tag;
         for( dp = _DYNAMIC; (tag = dp->d_tag) != 0; dp++ ) {

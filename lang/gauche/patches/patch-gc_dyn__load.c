$NetBSD: patch-gc_dyn__load.c,v 1.1 2012/05/30 02:50:11 enami Exp $

commit a378494312ac9aedcb08fa7a9593506ce5620878
Author: Shiro Kawai <shiro@acm.org>
Date:   Mon May 28 17:22:14 2012 -1000

    Backport a gc patch for NetBSD 6

--- gc/dyn_load.c.orig	2012-05-26 10:42:03.000000000 +0000
+++ gc/dyn_load.c
@@ -77,6 +77,8 @@ STATIC GC_has_static_roots_func GC_has_s
 #endif
 
 #if defined(NETBSD)
+#   include <sys/param.h>
+#   include <dlfcn.h>
 #   include <machine/elf_machdep.h>
 #   define ELFSIZE ARCH_ELFSIZE
 #endif
@@ -644,6 +646,15 @@ GC_FirstDLOpenedLinkMap(void)
         return(0);
     }
     if( cachedResult == 0 ) {
+#if defined(NETBSD) && defined(RTLD_DI_LINKMAP)
+        struct link_map *lm = NULL;
+        int rv = dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &lm); 
+        if (rv != 0)
+            return (0);
+        if (lm == NULL)
+            return (0);
+        cachedResult = lm;
+#else  /* !(defined(NETBSD) && defined(RTLD_DI_LINKMAP)) */
         int tag;
         for( dp = _DYNAMIC; (tag = dp->d_tag) != 0; dp++ ) {
             if( tag == DT_DEBUG ) {
@@ -653,6 +664,7 @@ GC_FirstDLOpenedLinkMap(void)
                 break;
             }
         }
+#endif /* !(defined(NETBSD) && defined(RTLD_DI_LINKMAP)) */
     }
     return cachedResult;
 }

$NetBSD: patch-nsprpub_pr_include_md_prosdep.h,v 1.1 2012/01/07 18:47:39 marino Exp $

--- nsprpub/pr/include/md/prosdep.h.orig	2011-09-02 20:15:44.000000000 +0000
+++ nsprpub/pr/include/md/prosdep.h
@@ -66,7 +66,7 @@ PR_BEGIN_EXTERN_C
 #if defined(AIX)
 #include "md/_aix.h"
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__DragonFly__)
 #include "md/_freebsd.h"
 
 #elif defined(NETBSD)

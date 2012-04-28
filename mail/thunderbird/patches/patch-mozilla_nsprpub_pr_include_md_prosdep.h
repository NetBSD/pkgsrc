$NetBSD: patch-mozilla_nsprpub_pr_include_md_prosdep.h,v 1.2 2012/04/28 16:56:59 ryoon Exp $

--- mozilla/nsprpub/pr/include/md/prosdep.h.orig	2012-04-20 22:40:20.000000000 +0000
+++ mozilla/nsprpub/pr/include/md/prosdep.h
@@ -66,7 +66,7 @@ PR_BEGIN_EXTERN_C
 #if defined(AIX)
 #include "md/_aix.h"
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__DragonFly__)
 #include "md/_freebsd.h"
 
 #elif defined(NETBSD)

$NetBSD: patch-fnm__extmatch.h,v 1.1 2016/09/09 15:40:17 scole Exp $
Define FNM_EXTMATCH if not already defined

--- fnm_extmatch.h.orig	2016-09-09 14:49:14.000000000 +0000
+++ fnm_extmatch.h
@@ -0,0 +1,9 @@
+/*
+ * this is defined in external/gpl[23]/gnulib various fnmatch_.h
+ * with _GNU_SOURCE or various _POSIX_C_SOURCE but not
+ * pksrgc/pkgtools/libnbcompat pkg/include/nbcompat/fnmatch.h or
+ * usr/include/fnmatch.h, what is best way to fix?
+ */
+#ifndef FNM_EXTMATCH
+# define FNM_EXTMATCH	(1 << 5) /* Use ksh-like extended matching. */	      
+#endif

$NetBSD: patch-misc_fts.h,v 1.1 2013/09/13 12:41:32 ryoon Exp $

* Definition for NetBSD.

--- misc/fts.h.orig	2013-06-10 15:55:10.000000000 +0000
+++ misc/fts.h
@@ -61,6 +61,10 @@
 # define _D_EXACT_NAMLEN(d) (strlen((d)->d_name))
 #endif
 
+#if defined(__NetBSD__)
+# define _D_EXACT_NAMLEN(d) ((d)->d_reclen)
+#endif
+
 #endif
 
 #include <sys/types.h>

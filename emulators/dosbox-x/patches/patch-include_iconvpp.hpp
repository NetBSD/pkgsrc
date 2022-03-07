$NetBSD: patch-include_iconvpp.hpp,v 1.1 2022/03/07 16:37:52 nia Exp $

Support NetBSD 9.x and earlier.

--- include/iconvpp.hpp.orig	2022-03-07 16:24:10.486063951 +0000
+++ include/iconvpp.hpp
@@ -31,6 +31,15 @@
 # define ICONV_BIG_ENDIAN BIG_ENDIAN
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
@@ -247,7 +256,11 @@ public:
             iconv(context,NULL,NULL,NULL,NULL);
 
             /* Ref: [http://man7.org/linux/man-pages/man3/iconv.3.html] */
+#if defined(__sun) || (defined(__NetBSD__) && !defined(NETBSD_POSIX_ICONV))
+            int ret = iconv(context,(&(pclass::src_ptr)),&src_left,(char**)(&(pclass::dst_ptr)),&dst_left);
+#else
             int ret = iconv(context,(char**)(&(pclass::src_ptr)),&src_left,(char**)(&(pclass::dst_ptr)),&dst_left);
+#endif
 
             pclass::src_adv = (size_t)(pclass::src_ptr - i_src);
             pclass::dst_adv = (size_t)(pclass::dst_ptr - i_dst);

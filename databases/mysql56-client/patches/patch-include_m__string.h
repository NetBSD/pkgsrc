$NetBSD: patch-include_m__string.h,v 1.1.2.2 2019/09/08 16:55:17 bsiegert Exp $

* Stop useless warnings.

--- include/m_string.h.orig	2019-06-10 10:25:32.000000000 +0000
+++ include/m_string.h
@@ -43,7 +43,9 @@
 #endif
 
 #define bfill please_use_memset_rather_than_bfill()
+#ifndef bzero
 #define bzero please_use_memset_rather_than_bzero()
+#endif
 
 #if !defined(HAVE_MEMCPY) && !defined(HAVE_MEMMOVE)
 # define memcpy(d, s, n)	bcopy ((s), (d), (n))

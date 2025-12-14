$NetBSD: patch-include_support.h,v 1.1 2025/12/14 10:07:19 vins Exp $

Fix call to non-constexpr function 'long int _sysconf(int)'. 

--- include/support.h.orig	2025-06-17 09:01:32.000000000 +0000
+++ include/support.h
@@ -53,7 +53,11 @@
 
 #ifdef PAGESIZE
 // Some platforms like ppc64 have page sizes of 64K, so uint16_t isn't enough.
+# ifdef __sun
+const uint32_t host_pagesize = {PAGESIZE};
+# else
 constexpr uint32_t host_pagesize = {PAGESIZE};
+# endif
 #else
 constexpr uint16_t host_pagesize = 4096;
 #endif

$NetBSD: patch-include_sort__r.h,v 1.1 2022/01/10 02:30:23 khorben Exp $

Fix the build for NetBSD

--- include/sort_r.h.orig	2021-11-21 15:39:01.000000000 +0000
+++ include/sort_r.h
@@ -25,7 +25,7 @@ Slightly modified to work with hashcat t
 */
 
 #if (defined __APPLE__ || defined __MACH__ || defined __DARWIN__ || \
-     defined __FreeBSD__ || defined __DragonFly__)
+     defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__)
 #  define _SORT_R_BSD
 #  define _SORT_R_INLINE inline
 #elif (defined __linux__) || defined (__CYGWIN__)
@@ -202,7 +202,12 @@ static _SORT_R_INLINE void sort_r_simple
       struct sort_r_data tmp;
       tmp.arg = arg;
       tmp.compar = compar;
-      qsort_r(base, nel, width, &tmp, sort_r_arg_swap);
+
+      #if defined __NetBSD__
+        sort_r_simple(base, nel, width, compar, arg);
+      #else
+        qsort_r(base, nel, width, &tmp, sort_r_arg_swap);
+      #endif
 
     #elif defined _SORT_R_WINDOWS
 

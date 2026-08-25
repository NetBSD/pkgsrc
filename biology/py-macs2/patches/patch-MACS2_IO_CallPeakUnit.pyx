$NetBSD: patch-MACS2_IO_CallPeakUnit.pyx,v 1.2 2026/08/25 09:26:21 wiz Exp $

# Fix cython 3 error

--- MACS2/IO/CallPeakUnit.pyx.orig	2023-07-21 14:25:59.000000000 +0000
+++ MACS2/IO/CallPeakUnit.pyx
@@ -197,7 +197,7 @@ cdef wtd_find_summit(chrom, np.ndarray plus, np.ndarra
     wtd_list = np.zeros( search_end - search_start + 1, dtype="float32")
     i = 0
     for j in range(search_start, search_end+1):
-        wtd_list[i] = max((2 * (watson_left * crick_right)**0.5 - watson_right - crick_left),0) # minimum score is 0
+        wtd_list[i] = max((2 * (watson_left * crick_right)**0.5 - watson_right - crick_left),complex(0)) # minimum score is 0
         watson_left += left_forward(watson, j, window_size)
         watson_right += right_forward(watson, j, window_size)
         crick_left += left_forward(crick, j, window_size)
@@ -1854,7 +1854,8 @@ cdef class CallerFromAlignments:
             int32_t c, m, i, j, pre_i, pre_j, pos, startpos, endpos
             np.ndarray plus, minus, rt_plus, rt_minus
             bytes chrom
-            set pchrnames, chrnames
+            list pchrnames
+            set chrnames
             list temp, retval, cpeaks
             np.ndarray adjusted_summits, passflags
 

$NetBSD: patch-MACS2_IO_CallPeakUnit.pyx,v 1.1 2023/12/23 16:15:02 bacon Exp $

# Fix cython 3 error

--- MACS2/IO/CallPeakUnit.pyx.orig	2023-12-23 15:31:06.614325825 +0000
+++ MACS2/IO/CallPeakUnit.pyx
@@ -197,7 +197,7 @@ cdef wtd_find_summit(chrom, np.ndarray p
     wtd_list = np.zeros( search_end - search_start + 1, dtype="float32")
     i = 0
     for j in range(search_start, search_end+1):
-        wtd_list[i] = max((2 * (watson_left * crick_right)**0.5 - watson_right - crick_left),0) # minimum score is 0
+        wtd_list[i] = max((2 * (watson_left * crick_right)**0.5 - watson_right - crick_left),complex(0)) # minimum score is 0
         watson_left += left_forward(watson, j, window_size)
         watson_right += right_forward(watson, j, window_size)
         crick_left += left_forward(crick, j, window_size)

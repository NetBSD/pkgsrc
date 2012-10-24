$NetBSD: patch-stat__out.c,v 1.1 2012/10/24 15:38:05 joerg Exp $

--- stat_out.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ stat_out.c
@@ -1,20 +1,8 @@
-extern main();
-extern data_array[];
-extern data_return_param;
-extern flag_data_return[];
-extern memory_number;
-extern mode1;
-extern mode2;
-extern mode3;
-extern narrow1;
-extern narrow2;
-extern narrow3;
-extern narrow4;
-extern narrow5;
-extern narrow6;
-extern white_space;
+#include "yaesu.h"
 
-stat_out(int fdSer, int current_freq_mode) {
+void find_mode(int, int);
+
+void stat_out(int fdSer, int current_freq_mode) {
 /*
  *  This function is intended to be called via some other function
  *  that needs some kind of output.  current_freq_mode is the 
@@ -55,7 +43,7 @@ output_freq: 
       freq_fl = freq;
       freq_fl = freq_fl/100000;
       find_mode(data_array[7], data_array[9]);
-      printf("\nThe current VFO frequency in VFO A is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
+      printf("\nThe current VFO frequency in VFO A is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
 /*      printf("\nThe current VFO frequency in VFO A is %d.%d%d MHz, operating in %c%c%c%c%c%c%c%c%c%c%c.\n", freq_MHz, freq_kHz, freq_htHz, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); */
    }
    if (vfo_a_b_op == 1 && vfo_b_op == 1 && mem_op == 0) {
@@ -71,7 +59,7 @@ output_freq: 
       freq_fl = freq;
       freq_fl = freq_fl/100000;
       find_mode(data_array[16], data_array[18]);
-      printf("\nThe current VFO frequency in VFO B is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
+      printf("\nThe current VFO frequency in VFO B is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
 /*      printf("\nThe current VFO frequency in VFO B is %d.%d%d MHz, operating in %c%c%c%c%c%c%c%c%c%c%c.\n", freq_MHz, freq_kHz, freq_htHz, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); */
 
    }
@@ -92,12 +80,12 @@ output_freq: 
       freq_fl = freq;
       freq_fl = freq_fl/100000; 
       find_mode(data_array[16], data_array[18]);
-      printf("\nThe current memory frequency displayed is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
+      printf("\nThe current memory frequency displayed is %.5f MHz, operating in %c%c%c%c%c%c%c%c%c%c.\n", freq_fl, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); 
 /*      printf("\nThe current memory frequency displayed is %d.%d%d MHz, operating in %c%c%c%c%c%c%c%c%c%c.\n", freq_MHz, freq_kHz, freq_htHz, mode1, mode2, mode3, white_space, narrow1, narrow2, narrow3, narrow4, narrow5, narrow6); */
    }
 }
 
-find_mode(data_array_n, data_array_w) {
+void find_mode(int data_array_n, int data_array_w) {
       int am_mode, cw_mode, three;
       
        am_mode = (data_array_w >> 6) & 0x01;

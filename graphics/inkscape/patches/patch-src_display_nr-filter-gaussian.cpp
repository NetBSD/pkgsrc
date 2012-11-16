$NetBSD: patch-src_display_nr-filter-gaussian.cpp,v 1.1 2012/11/16 00:54:04 joerg Exp $

--- src/display/nr-filter-gaussian.cpp.orig	2012-11-15 16:38:32.000000000 +0000
+++ src/display/nr-filter-gaussian.cpp
@@ -708,7 +708,7 @@ int FilterGaussian::render(FilterSlot &s
         };
     } else if ( scr_len_x > 0 ) { // !use_IIR_x
         // Filter kernel for x direction
-        FIRValue kernel[scr_len_x+1];
+        FIRValue *kernel = new FIRValue[scr_len_x+1];
         _make_kernel(&kernel[0], deviation_x);
 
         // Filter (x)
@@ -728,6 +728,7 @@ int FilterGaussian::render(FilterSlot &s
         default:
             assert(false);
         };
+        delete[] kernel;
     } else if ( out != ssin ) { // out can be equal to ssin if resampling is used
         nr_blit_pixblock_pixblock(out, ssin);
     }
@@ -770,7 +771,7 @@ int FilterGaussian::render(FilterSlot &s
         };
     } else if ( scr_len_y > 0 ) { // !use_IIR_y
         // Filter kernel for y direction
-        FIRValue kernel[scr_len_y+1];
+        FIRValue *kernel = new FIRValue[scr_len_y+1];
         _make_kernel(&kernel[0], deviation_y);
 
         // Filter (y)
@@ -790,6 +791,7 @@ int FilterGaussian::render(FilterSlot &s
         default:
             assert(false);
         };
+        delete[] kernel;
     }
 
     for(int i=0; i<NTHREADS; i++) {

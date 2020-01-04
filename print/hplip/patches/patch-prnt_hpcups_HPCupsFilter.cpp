$NetBSD: patch-prnt_hpcups_HPCupsFilter.cpp,v 1.1 2020/01/04 04:24:12 khorben Exp $

Avoid using libImageProcessing.so (binary blob)

Patch from "loqs", obtained at:
https://bugs.archlinux.org/task/59548#comment172098

--- prnt/hpcups/HPCupsFilter.cpp.orig	2019-12-10 05:00:33.000000000 +0000
+++ prnt/hpcups/HPCupsFilter.cpp
@@ -31,8 +31,6 @@
 \*****************************************************************************/
 
 #include "HPCupsFilter.h"
-#include "ImageProcessor.h"
-
 #include <signal.h>
 #include <sys/wait.h>
 #include <sys/utsname.h>
@@ -637,16 +635,9 @@ int HPCupsFilter::processRasterData(cups
 
 
     sprintf(hpPreProcessedRasterFile, "%s/hp_%s_cups_SwapedPagesXXXXXX",CUPS_TMP_DIR, m_JA.user_name);
-    image_processor_t* imageProcessor = imageProcessorCreate();
 
     while (cupsRasterReadHeader2(cups_raster, &cups_header))
     {
-
-        IMAGE_PROCESSOR_ERROR result = imageProcessorStartPage(imageProcessor, &cups_header);
-        if (result != IPE_SUCCESS){
-            dbglog("DEBUG: imageProcessorStartPage failed result = %d\n", result);
-        }
-
         current_page_number++;
 
         if (current_page_number == 1) {
@@ -745,12 +736,6 @@ int HPCupsFilter::processRasterData(cups
             color_raster = rgbRaster;
             black_raster = kRaster;
 
-            result = imageProcessorProcessLine(imageProcessor, m_pPrinterBuffer, cups_header.cupsBytesPerLine);
-            if (result != IPE_SUCCESS){
-                dbglog("DEBUG: imageProcessorProcessLine failed result = %d\n", result);
-            }
-
-
             if ((y == 0) && !is_ljmono) {
                 //For ljmono, make sure that first line is not a blankRaster line.Otherwise printer
                 //may not skip blank lines before actual data
@@ -780,12 +765,6 @@ int HPCupsFilter::processRasterData(cups
             }
         }  // for() loop end
 
-        result = imageProcessorEndPage(imageProcessor);
-        if (result != IPE_SUCCESS){
-                dbglog("DEBUG: imageProcessorEndPage failed result = %d\n", result);
-        }
-
-
         m_Job.NewPage();
         if (err != NO_ERROR) {
             break;
@@ -800,8 +779,6 @@ int HPCupsFilter::processRasterData(cups
         rgbRaster = NULL;
     }
 
-    imageProcessorDestroy(imageProcessor);
-
     unlink(hpPreProcessedRasterFile);
     return ret_status;
 }

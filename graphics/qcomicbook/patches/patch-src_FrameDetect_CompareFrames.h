$NetBSD: patch-src_FrameDetect_CompareFrames.h,v 1.1 2013/05/04 12:59:46 joerg Exp $

--- src/FrameDetect/CompareFrames.h.orig	2013-05-04 00:21:49.000000000 +0000
+++ src/FrameDetect/CompareFrames.h
@@ -14,6 +14,7 @@
 #define __COMPARE_FRAMES_H
 
 #include <ComicFrame.h>
+#include <cstdlib>
 
 namespace QComicBook
 {

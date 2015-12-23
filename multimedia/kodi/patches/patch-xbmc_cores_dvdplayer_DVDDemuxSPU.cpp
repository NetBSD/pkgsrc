$NetBSD: patch-xbmc_cores_dvdplayer_DVDDemuxSPU.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/cores/dvdplayer/DVDDemuxSPU.cpp.orig	2015-12-22 17:49:55.000000000 +0000
+++ xbmc/cores/dvdplayer/DVDDemuxSPU.cpp
@@ -21,6 +21,7 @@
 #include "DVDDemuxSPU.h"
 #include "DVDClock.h"
 #include "utils/log.h"
+#include <cstdlib>
 
 #undef ALIGN
 #define ALIGN(value, alignment) (((value)+((alignment)-1))&~((alignment)-1))

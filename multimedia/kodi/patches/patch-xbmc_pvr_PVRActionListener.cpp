$NetBSD: patch-xbmc_pvr_PVRActionListener.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/pvr/PVRActionListener.cpp.orig	2015-12-22 18:44:41.000000000 +0000
+++ xbmc/pvr/PVRActionListener.cpp
@@ -34,6 +34,8 @@
 #include "pvr/PVRManager.h"
 #include "pvr/channels/PVRChannelGroupsContainer.h"
 
+#include <cstdlib>
+
 using namespace PVR;
 
 CPVRActionListener::CPVRActionListener()

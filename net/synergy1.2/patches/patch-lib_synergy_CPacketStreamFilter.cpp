$NetBSD: patch-lib_synergy_CPacketStreamFilter.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/synergy/CPacketStreamFilter.cpp.orig	2011-11-22 19:37:00.000000000 +0000
+++ lib/synergy/CPacketStreamFilter.cpp
@@ -16,6 +16,7 @@
 #include "IEventQueue.h"
 #include "CLock.h"
 #include "TMethodEventJob.h"
+#include <string.h>
 
 //
 // CPacketStreamFilter

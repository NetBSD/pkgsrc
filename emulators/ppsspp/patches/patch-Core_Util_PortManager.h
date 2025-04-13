$NetBSD: patch-Core_Util_PortManager.h,v 1.1 2025/04/13 16:19:29 nia Exp $

Fix the header paths for the pkgsrc version of miniupnpc.

--- Core/Util/PortManager.h.orig	2025-04-13 09:08:16.860758203 +0000
+++ Core/Util/PortManager.h
@@ -22,9 +22,9 @@
 #pragma once
 
 #ifdef USE_SYSTEM_MINIUPNPC
-#include <miniupnpc/include/miniwget.h>
-#include <miniupnpc/include/miniupnpc.h>
-#include <miniupnpc/include/upnpcommands.h>
+#include <miniupnpc/miniwget.h>
+#include <miniupnpc/miniupnpc.h>
+#include <miniupnpc/upnpcommands.h>
 #else
 #ifndef MINIUPNP_STATICLIB
 #define MINIUPNP_STATICLIB

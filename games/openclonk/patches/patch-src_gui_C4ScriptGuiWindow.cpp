$NetBSD: patch-src_gui_C4ScriptGuiWindow.cpp,v 1.1 2024/12/18 10:41:25 wiz Exp $

Fix error: ‘numeric_limits’ is not a member of ‘std’

--- src/gui/C4ScriptGuiWindow.cpp.orig	2024-12-18 10:39:28.330761894 +0000
+++ src/gui/C4ScriptGuiWindow.cpp
@@ -43,6 +43,8 @@
 #include "player/C4Player.h"
 #include "player/C4PlayerList.h"
 
+#include <limits>
+
 // Adds some helpful logs for hunting control & menu based desyncs.
 //#define MenuDebugLogF(...) DebugLogF(__VA_ARGS__)
 #define MenuDebugLogF(...) ((void)0)

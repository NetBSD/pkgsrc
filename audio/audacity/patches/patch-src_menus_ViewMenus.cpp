$NetBSD: patch-src_menus_ViewMenus.cpp,v 1.1 2021/09/11 08:53:19 nia Exp $

[PATCH] Fix crash on track resize

As discussed in #538, there is an issue with the track resize option,
where with audacity >= 2.4.0, compiled using the autotools setup leads
to a hard crash.

The sizeof(wxFrame) in src/menus/ViewMenus.cpp and src/ProjectWindow.cpp
is not aligned, leading to GetVerticalScrollBar in
src/menus/ViewMenus.cpp accessing unallocated memory.

By ordering the include of ProjectWindow.h before the include of
Project.h, this crash is prevented.

https://github.com/dvzrv/audacity/commit/d7e769040b508aaf15ce7b51cc1a565d41cdb079.patch

--- src/menus/ViewMenus.cpp.orig	2020-05-19 09:43:53.000000000 +0000
+++ src/menus/ViewMenus.cpp
@@ -4,10 +4,10 @@
 #include "../CommonCommandFlags.h"
 #include "../Menus.h"
 #include "../Prefs.h"
+#include "../ProjectWindow.h"
 #include "../Project.h"
 #include "../ProjectHistory.h"
 #include "../ProjectSettings.h"
-#include "../ProjectWindow.h"
 #include "../Track.h"
 #include "../TrackInfo.h"
 #include "../TrackPanel.h"

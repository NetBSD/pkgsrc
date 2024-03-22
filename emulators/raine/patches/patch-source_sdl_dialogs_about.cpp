$NetBSD: patch-source_sdl_dialogs_about.cpp,v 1.1 2024/03/22 09:00:43 nia Exp $

Ensure the correct history.h is included.

--- source/sdl/dialogs/about.cpp.orig	2024-01-24 09:14:16.000000000 +0000
+++ source/sdl/dialogs/about.cpp
@@ -6,7 +6,7 @@
 #include "raine.h"
 #include "version.h"
 #include "files.h" // get_shared
-#include "history.h"
+#include "../../history.h"
 #include "dialogs/messagebox.h"
 #include "gui/tfont.h"
 #include "control.h"

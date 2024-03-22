$NetBSD: patch-source_sdl_dialogs_controls.cpp,v 1.1 2024/03/22 09:00:43 nia Exp $

Missing include for unlink(2).

--- source/sdl/dialogs/controls.cpp.orig	2024-03-22 08:24:35.511525479 +0000
+++ source/sdl/dialogs/controls.cpp
@@ -1,3 +1,4 @@
+#include <unistd.h>
 #include "../gui/menu.h"
 #include "compat.h"
 #include "control.h"

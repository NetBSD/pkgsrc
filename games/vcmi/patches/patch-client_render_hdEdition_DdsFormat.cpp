$NetBSD: patch-client_render_hdEdition_DdsFormat.cpp,v 1.1 2026/05/07 17:16:19 adam Exp $

Use correct include for newer libsquish.

--- client/render/hdEdition/DdsFormat.cpp.orig	2026-05-07 05:39:02.376139609 +0000
+++ client/render/hdEdition/DdsFormat.cpp
@@ -12,7 +12,7 @@
 #include "DdsFormat.h"
 
 #include <SDL_surface.h>
-#include <squish.h>
+#include <squish/squish.h>
 
 #include "../../../lib/filesystem/CInputStream.h"
 

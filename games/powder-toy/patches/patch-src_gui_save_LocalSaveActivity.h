$NetBSD: patch-src_gui_save_LocalSaveActivity.h,v 1.1 2025/12/17 17:32:20 nia Exp $

Add missing include for std::unique_ptr.

--- src/gui/save/LocalSaveActivity.h.orig	2025-12-17 17:27:32.841258553 +0000
+++ src/gui/save/LocalSaveActivity.h
@@ -4,6 +4,7 @@
 #include "client/SaveFile.h"
 
 #include <functional>
+#include <memory>
 
 namespace ui
 {

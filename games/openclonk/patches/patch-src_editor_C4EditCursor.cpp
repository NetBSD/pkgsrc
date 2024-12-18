$NetBSD: patch-src_editor_C4EditCursor.cpp,v 1.1 2024/12/18 10:41:25 wiz Exp $

Fix error: ‘numeric_limits’ is not a member of ‘std’

--- src/editor/C4EditCursor.cpp.orig	2024-12-18 10:38:39.920412668 +0000
+++ src/editor/C4EditCursor.cpp
@@ -41,6 +41,7 @@
 #include "res/resource.h"
 #endif
 
+#include <limits>
 
 StdStrBuf C4EditCursorSelection::GetDataString() const
 {

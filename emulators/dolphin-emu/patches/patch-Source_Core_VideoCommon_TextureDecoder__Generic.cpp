$NetBSD: patch-Source_Core_VideoCommon_TextureDecoder__Generic.cpp,v 1.1 2025/12/17 23:16:03 nia Exp $

Add missing <cstring> header needed for memset.

--- Source/Core/VideoCommon/TextureDecoder_Generic.cpp.orig	2025-12-17 23:12:36.583573291 +0000
+++ Source/Core/VideoCommon/TextureDecoder_Generic.cpp
@@ -4,6 +4,7 @@
 
 #include <algorithm>
 #include <cmath>
+#include <cstring>
 
 #include "Common/CommonFuncs.h"
 #include "Common/CommonTypes.h"

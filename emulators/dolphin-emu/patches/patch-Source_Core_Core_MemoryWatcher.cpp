$NetBSD: patch-Source_Core_Core_MemoryWatcher.cpp,v 1.1 2025/06/12 07:37:34 wiz Exp $

Add missing header for memset and strncpy.

--- Source/Core/Core/MemoryWatcher.cpp.orig	2025-06-12 07:34:14.049871599 +0000
+++ Source/Core/Core/MemoryWatcher.cpp
@@ -2,6 +2,7 @@
 // Licensed under GPLv2+
 // Refer to the license.txt file included.
 
+#include <cstring>
 #include <fstream>
 #include <iostream>
 #include <memory>

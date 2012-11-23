$NetBSD: patch-src_common_common.cpp,v 1.1 2012/11/23 20:19:16 marino Exp $

--- src/common/common.cpp.orig	2011-10-09 09:48:12.000000000 +0000
+++ src/common/common.cpp
@@ -14,6 +14,7 @@
 #include "common/common_pch.h"
 
 #include <stdlib.h>
+#include <unistd.h>
 #ifdef SYS_WINDOWS
 # include <windows.h>
 #endif

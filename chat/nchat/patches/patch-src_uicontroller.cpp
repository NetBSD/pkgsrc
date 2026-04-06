$NetBSD: patch-src_uicontroller.cpp,v 1.1 2026/04/06 13:46:38 nia Exp $

SunOS needs <string.h> for FD_ZERO.

--- src/uicontroller.cpp.orig	2026-04-06 12:52:46.523168737 +0000
+++ src/uicontroller.cpp
@@ -7,6 +7,7 @@
 
 #include "uicontroller.h"
 
+#include <cstring>
 #include <cwchar>
 
 #include <unistd.h>

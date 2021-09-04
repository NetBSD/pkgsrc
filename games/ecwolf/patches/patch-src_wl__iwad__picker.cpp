$NetBSD: patch-src_wl__iwad__picker.cpp,v 1.1 2021/09/04 10:36:29 nia Exp $

Missing include for WIFEXITED.

--- src/wl_iwad_picker.cpp.orig	2016-10-01 04:13:53.000000000 +0000
+++ src/wl_iwad_picker.cpp
@@ -1,6 +1,7 @@
 // From ZDoom!
 
 #include <algorithm>
+#include <sys/wait.h>
 
 #include "zdoomsupport.h"
 

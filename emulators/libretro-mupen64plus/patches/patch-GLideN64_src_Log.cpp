$NetBSD: patch-GLideN64_src_Log.cpp,v 1.1 2018/10/03 15:01:10 nia Exp $

stdlib.h is needed for wcstombs(3).

--- GLideN64/src/Log.cpp.orig	2018-07-28 21:11:31.000000000 +0000
+++ GLideN64/src/Log.cpp
@@ -1,5 +1,6 @@
 #include <stdarg.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "Log.h"
 #include "PluginAPI.h"
 #include "wst.h"

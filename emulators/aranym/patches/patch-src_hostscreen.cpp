$NetBSD: patch-src_hostscreen.cpp,v 1.1 2025/12/18 14:06:16 nia Exp $

Include <limits.h> for PATH_MAX.

--- src/hostscreen.cpp.orig	2025-12-17 14:09:05.185109860 +0000
+++ src/hostscreen.cpp
@@ -25,6 +25,7 @@
 
 #include "newcpu.h"
 #include <errno.h>
+#include <limits.h>
 
 #include "SDL_compat.h"
 #include <vector>

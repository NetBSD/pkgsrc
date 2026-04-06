$NetBSD: patch-src_uikeydump.cpp,v 1.1 2026/04/06 13:46:38 nia Exp $

SunOS needs <string.h> for FD_ZERO.

--- src/uikeydump.cpp.orig	2026-04-06 13:41:45.995901727 +0000
+++ src/uikeydump.cpp
@@ -8,6 +8,7 @@
 #include "uikeydump.h"
 
 #include <locale.h>
+#include <string.h>
 #include <unistd.h>
 
 #include <sys/select.h>

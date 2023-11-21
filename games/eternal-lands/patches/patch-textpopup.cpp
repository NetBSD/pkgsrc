$NetBSD: patch-textpopup.cpp,v 1.1 2023/11/21 18:05:59 nia Exp $

Missing header for std::round.

--- textpopup.cpp.orig	2022-03-12 13:48:44.000000000 +0000
+++ textpopup.cpp
@@ -1,3 +1,4 @@
+#include <cmath>
 #include "textpopup.h"
 #include "asc.h"
 #include "gamewin.h"

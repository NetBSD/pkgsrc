$NetBSD: patch-quest__log.cpp,v 1.1 2023/11/21 18:05:59 nia Exp $

Missing header for std::round.

--- quest_log.cpp.orig	2022-03-12 13:48:44.000000000 +0000
+++ quest_log.cpp
@@ -11,6 +11,7 @@
 #include <queue>
 #include <set>
 #include <cctype>
+#include <cmath>
 #include <algorithm>
 #include <iostream>
 #include <fstream>

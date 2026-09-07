$NetBSD: patch-traceroute.cc,v 1.1 2026/09/07 02:56:52 adam Exp $

Fix build with GCC 12 (GCC 14 builds fine).

--- traceroute.cc.orig	2026-09-07 02:53:42.122634335 +0000
+++ traceroute.cc
@@ -119,6 +119,7 @@ individually.
 #include <dnet.h>
 
 #include <algorithm>
+#include <cstddef>
 #include <list>
 #include <map>
 #include <set>

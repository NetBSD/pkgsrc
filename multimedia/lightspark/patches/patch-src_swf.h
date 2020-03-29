$NetBSD: patch-src_swf.h,v 1.1 2020/03/29 01:04:07 joerg Exp $

bimap.hpp needs split_member.hpp with Boost 1.72.

--- src/swf.h.orig	2020-03-28 20:58:17.828100735 +0000
+++ src/swf.h
@@ -26,6 +26,7 @@
 #include <queue>
 #include <map>
 #include <unordered_set>
+#include <boost/serialization/split_member.hpp>
 #include <boost/bimap.hpp>
 #include <string>
 #include "swftypes.h"

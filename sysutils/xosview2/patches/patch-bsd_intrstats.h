$NetBSD: patch-bsd_intrstats.h,v 1.1 2022/12/22 15:13:15 vins Exp $

Define unsigned integer types.

--- bsd/intrstats.h.orig	2022-07-08 17:46:40.000000000 +0000
+++ bsd/intrstats.h
@@ -11,7 +11,7 @@
 #include <map>
 #include <vector>
 #include <iosfwd>
-
+#include <cstdint>	// uint64_t
 
 
 class IntrStats {

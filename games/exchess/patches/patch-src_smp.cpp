$NetBSD: patch-src_smp.cpp,v 1.1 2022/04/25 13:53:15 tnn Exp $

Explicitly use std::sqrt, avoids ambiguous reference on SunOS.

--- src/smp.cpp.orig	2017-02-04 14:23:32.000000000 +0000
+++ src/smp.cpp
@@ -14,6 +14,8 @@
 #include "chess.h"
 #include "search.h"
 
+using std::sqrt;
+
 //-----------------------------------------------
 // Global variables to control SMP search
 //-----------------------------------------------

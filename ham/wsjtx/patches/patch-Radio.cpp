$NetBSD: patch-Radio.cpp,v 1.1 2026/01/19 13:40:54 mef Exp $

From FreeBSD ports 2.5.4

--- wsjtx/Radio.cpp.orig	2021-11-03 19:53:01.000000000 -0400
+++ Radio.cpp	2021-12-31 07:48:03.411318000 -0500
@@ -54,7 +54,8 @@
     value *= std::pow (10., scale);
     if (ok)
       {
-        if (value < 0. || value > std::numeric_limits<Frequency>::max ())
+#define MAXDOUBLEFREQUENCY 18446744073709551616.0
+        if (value < 0. || value > MAXDOUBLEFREQUENCY)
           {
             value = 0.;
             *ok = false;
@@ -92,7 +93,7 @@
     if (ok)
       {
         if (value < -std::numeric_limits<Frequency>::max ()
-            || value > std::numeric_limits<Frequency>::max ())
+            || value > MAXDOUBLEFREQUENCY)
           {
             value = 0.;
             *ok = false;

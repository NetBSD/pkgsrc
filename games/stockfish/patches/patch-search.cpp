$NetBSD: patch-search.cpp,v 1.1 2022/04/25 15:24:31 tnn Exp $

avoid ambiguous math functions

--- search.cpp.orig	2018-01-31 10:41:09.000000000 +0000
+++ search.cpp
@@ -146,7 +146,7 @@ void Search::init() {
       for (int d = 1; d < 64; ++d)
           for (int mc = 1; mc < 64; ++mc)
           {
-              double r = log(d) * log(mc) / 1.95;
+              double r = std::log(d) * std::log(mc) / 1.95;
 
               Reductions[NonPV][imp][d][mc] = int(std::round(r));
               Reductions[PV][imp][d][mc] = std::max(Reductions[NonPV][imp][d][mc] - 1, 0);

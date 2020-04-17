$NetBSD: patch-volk_lib_qa__utils.cc,v 1.1 2020/04/17 13:33:44 joerg Exp $

--- volk/lib/qa_utils.cc.orig	2020-04-17 00:27:57.188604085 +0000
+++ volk/lib/qa_utils.cc
@@ -13,6 +13,7 @@
 #include <ctime>                                    // for clock
 #include <fstream>                                  // for operator<<, basic...
 #include <iostream>                                 // for cout, cerr
+#include <sstream>
 #include <limits>                                   // for numeric_limits
 #include <map>                                      // for map, map<>::mappe...
 #include <vector>                                   // for vector, _Bit_refe...

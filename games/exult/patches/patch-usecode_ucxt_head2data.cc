$NetBSD: patch-usecode_ucxt_head2data.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/ucxt/head2data.cc.orig	2011-11-25 17:51:52.000000000 +0000
+++ usecode/ucxt/head2data.cc
@@ -8,6 +8,7 @@
 #include <iomanip>
 #include <vector>
 #include <fstream>
+#include <cstdlib>
 
 using std::cout;
 using std::cerr;

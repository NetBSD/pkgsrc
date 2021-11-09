$NetBSD: patch-test_testhistorybigram.cpp,v 1.1 2021/11/09 10:15:36 nia Exp $

std:log10() needs <cmath> to be included.
Fixes building on NetBSD 9.99.x.

--- test/testhistorybigram.cpp.orig	2020-05-27 17:33:52.118881000 +0000
+++ test/testhistorybigram.cpp
@@ -8,6 +8,7 @@
 #include <boost/range/irange.hpp>
 #include <fcitx-utils/log.h>
 #include <sstream>
+#include <cmath>
 
 void testBasic() {
     using namespace libime;

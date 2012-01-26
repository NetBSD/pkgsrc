$NetBSD: patch-src_utf8-cpp_utf8_core.h,v 1.1 2012/01/26 15:43:20 ryoon Exp $

http://code.google.com/p/sigil/source/detail?r=ac1642d3df17ee958ab573e1cdb284d60bad6f9a

--- src/utf8-cpp/utf8/core.h.orig	2012-01-21 00:31:22.000000000 +0000
+++ src/utf8-cpp/utf8/core.h
@@ -29,7 +29,7 @@ DEALINGS IN THE SOFTWARE.
 #define UTF8_FOR_CPP_CORE_H_2675DCD0_9480_4c0c_B92A_CC14C027B731
 
 #include <iterator>
-#include "../../BoostParts/boost/cstdint.hpp"
+#include "boost/cstdint.hpp"
 
 namespace utf8
 {

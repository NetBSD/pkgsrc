$NetBSD: patch-src_utf8-cpp_utf8_core.h,v 1.1 2015/11/27 21:45:19 joerg Exp $

--- src/utf8-cpp/utf8/core.h.orig	2015-11-27 17:25:18.000000000 +0000
+++ src/utf8-cpp/utf8/core.h
@@ -29,7 +29,7 @@ DEALINGS IN THE SOFTWARE.
 #define UTF8_FOR_CPP_CORE_H_2675DCD0_9480_4c0c_B92A_CC14C027B731
 
 #include <iterator>
-#include "../../BoostParts/boost/cstdint.hpp"
+#include <boost/cstdint.hpp>
 
 namespace utf8
 {

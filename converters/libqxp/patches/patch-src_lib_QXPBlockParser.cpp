$NetBSD: patch-src_lib_QXPBlockParser.cpp,v 1.2 2018/03/17 09:22:06 tnn Exp $

Fix clang build. (this doesn't fail on gcc; don't ask me why)

--- src/lib/QXPBlockParser.cpp.orig	2017-12-31 15:11:37.000000000 +0000
+++ src/lib/QXPBlockParser.cpp
@@ -16,6 +16,7 @@
 #include <set>
 #include <vector>
 #include <iterator>
+#include <cstdlib>
 
 #include "QXPHeader.h"
 #include "QXPMemoryStream.h"
@@ -108,7 +109,7 @@ std::shared_ptr<RVNGInputStream> QXPBloc
 
       const int32_t nextVal = bigIdx ? readS32(m_input, be) : readS16(m_input, be);
       isBig = nextVal < 0;
-      next = abs(nextVal);
+      next = std::abs(nextVal);
     }
   }
   catch (...)

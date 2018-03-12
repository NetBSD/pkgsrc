$NetBSD: patch-src_lib_QXPBlockParser.cpp,v 1.1 2018/03/12 01:29:44 dholland Exp $

Fix clang build. (this doesn't fail on gcc; don't ask me why)

--- src/lib/QXPBlockParser.cpp~	2017-12-31 15:11:37.000000000 +0000
+++ src/lib/QXPBlockParser.cpp
@@ -108,7 +108,7 @@ std::shared_ptr<RVNGInputStream> QXPBloc
 
       const int32_t nextVal = bigIdx ? readS32(m_input, be) : readS16(m_input, be);
       isBig = nextVal < 0;
-      next = abs(nextVal);
+      next = std::abs(nextVal);
     }
   }
   catch (...)

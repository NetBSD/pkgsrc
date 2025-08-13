$NetBSD: patch-src_testtex_testtex.cpp,v 1.2 2025/08/13 06:51:22 wiz Exp $

https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/testtex/testtex.cpp.orig	2025-08-13 06:26:53.842812970 +0000
+++ src/testtex/testtex.cpp
@@ -1557,7 +1557,7 @@ do_tex_thread_workout(int iterations, in
     }
     // Force the compiler to not optimize away the "other work"
     for (int c = 0; c < nchannels; ++c)
-        OIIO_ASSERT(!isnan(result[c]));
+        OIIO_ASSERT(!std::isnan(result[c]));
 }
 
 

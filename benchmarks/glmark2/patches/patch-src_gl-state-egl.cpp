$NetBSD: patch-src_gl-state-egl.cpp,v 1.1 2023/07/26 13:37:35 abs Exp $

Make failure to find a good EGL FB config non fatal

--- src/gl-state-egl.cpp.orig	2023-01-19 11:02:15.000000000 +0000
+++ src/gl-state-egl.cpp
@@ -635,7 +635,10 @@ GLStateEGL::select_best_config(std::vect
         }
     }
 
-    return best_score > 0 ? best_config : 0;
+    if (best_score <= 0) {
+        Log::error("Unable to find good EGL FB config (best match %d)\n", best_config);
+    }
+    return best_config;
 }
 
 bool

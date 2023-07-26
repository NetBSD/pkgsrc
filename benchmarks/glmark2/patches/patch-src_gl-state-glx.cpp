$NetBSD: patch-src_gl-state-glx.cpp,v 1.1 2023/07/26 13:37:35 abs Exp $

Make failure to find a good GLX FB config non fatal

--- src/gl-state-glx.cpp.orig	2023-01-19 11:02:15.000000000 +0000
+++ src/gl-state-glx.cpp
@@ -342,7 +342,10 @@ GLStateGLX::select_best_config(std::vect
         }
     }
 
-    return best_score > 0 ? best_config : 0;
+    if (best_score <= 0) {
+        Log::error("Unable to find good GLX FB config (best match %d)\n", best_config);
+    }
+    return best_config;
 }
 
 GLADapiproc

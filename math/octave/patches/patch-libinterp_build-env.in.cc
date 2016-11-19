$NetBSD: patch-libinterp_build-env.in.cc,v 1.1 2016/11/19 21:53:12 maya Exp $

--- libinterp/build-env.in.cc.orig	2016-11-13 15:16:10.000000000 +0000
+++ libinterp/build-env.in.cc
@@ -305,7 +305,7 @@ namespace octave
 
     const char *Z_LIBS = %OCTAVE_CONF_Z_LIBS%;
 
-    const char *config_opts = %OCTAVE_CONF_config_opts%;
+    const char *config_opts = "";
   }
 }
 

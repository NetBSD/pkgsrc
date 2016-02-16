$NetBSD: patch-libinterp_oct-conf.in.h,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- libinterp/oct-conf.in.h.orig	2015-05-23 14:21:53.000000000 +0000
+++ libinterp/oct-conf.in.h
@@ -631,7 +631,7 @@ along with Octave; see the file COPYING.
 #endif
 
 #ifndef OCTAVE_CONF_config_opts
-#define OCTAVE_CONF_config_opts %OCTAVE_CONF_config_opts%
+#define OCTAVE_CONF_config_opts ""
 #endif
 
 #endif

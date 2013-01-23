$NetBSD: patch-config_gr__standalone.m4,v 1.1 2013/01/23 18:44:12 wiz Exp $

automake-1.13 compat.

--- config/gr_standalone.m4.orig	2010-06-01 05:04:08.000000000 +0000
+++ config/gr_standalone.m4
@@ -32,7 +32,7 @@ m4_define([GR_STANDALONE],
   AC_PREREQ(2.57)
   AC_CONFIG_SRCDIR([config/gr_standalone.m4])
   AC_CONFIG_AUX_DIR([.])	
-  AM_CONFIG_HEADER(config.h)
+  AC_CONFIG_HEADERS(config.h)
 
   AC_CANONICAL_BUILD
   AC_CANONICAL_HOST

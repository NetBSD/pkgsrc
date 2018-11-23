$NetBSD: patch-src_hb.hh,v 1.1 2018/11/23 09:50:55 abs Exp $

Do not play _POSIX_C_SOURCE games on NetBSD - causes issues with some pkgsrc gcc versions

--- src/hb.hh.orig	2018-11-04 01:41:46.000000000 +0000
+++ src/hb.hh
@@ -35,7 +35,7 @@
 #include "config.h"
 #endif
 
-#ifndef _POSIX_C_SOURCE
+#if !defined(_POSIX_C_SOURCE) && !defined(__NetBSD__)
 #define _POSIX_C_SOURCE 200809L
 #endif
 

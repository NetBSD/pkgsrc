$NetBSD: patch-src_hb.hh,v 1.2 2019/01/29 18:54:03 bsiegert Exp $

Do not play _POSIX_C_SOURCE games on NetBSD - causes issues with some pkgsrc gcc versions

--- src/hb.hh.orig	2018-12-18 03:36:12.000000000 +0000
+++ src/hb.hh
@@ -59,7 +59,7 @@
 # define __EXTENSIONS__ 1
 #endif
 
-#ifndef _POSIX_C_SOURCE
+#if !defined (_POSIX_C_SOURCE) && !defined (__NetBSD__)
 #define _POSIX_C_SOURCE 200809L
 #endif
 

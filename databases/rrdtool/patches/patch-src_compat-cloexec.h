$NetBSD: patch-src_compat-cloexec.h,v 1.1 2024/08/23 17:48:50 adam Exp $

compat-cloexec: fix HAVE_DECL checks
https://github.com/oetiker/rrdtool-1.x/pull/1262

--- src/compat-cloexec.h.orig	2024-08-23 17:40:58.302086420 +0000
+++ src/compat-cloexec.h
@@ -3,11 +3,11 @@
 
 #include <rrd_config.h>
 
-#ifndef HAVE_DECL_O_CLOEXEC
+#if !defined(HAVE_DECL_O_CLOEXEC) || !HAVE_DECL_O_CLOEXEC
 #  define O_CLOEXEC 0
 #endif
 
-#ifndef HAVE_DECL_SOCK_CLOEXEC
+#if !defined(HAVE_DECL_SOCK_CLOEXEC) || !HAVE_DECL_SOCK_CLOEXEC
 #  define SOCK_CLOEXEC 0
 #endif
 

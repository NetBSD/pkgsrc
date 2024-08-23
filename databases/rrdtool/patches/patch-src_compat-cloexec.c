$NetBSD: patch-src_compat-cloexec.c,v 1.1 2024/08/23 17:48:50 adam Exp $

compat-cloexec: fix HAVE_DECL checks
https://github.com/oetiker/rrdtool-1.x/pull/1262

--- src/compat-cloexec.c.orig	2024-08-23 17:39:47.399776198 +0000
+++ src/compat-cloexec.c
@@ -17,7 +17,7 @@
 
 inline static bool have_decl_o_cloexec(void)
 {
-#ifdef HAVE_DECL_O_CLOEXEC
+#if defined(HAVE_DECL_O_CLOEXEC) && HAVE_DECL_O_CLOEXEC
 	return true;
 #else
 	return false;

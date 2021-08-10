$NetBSD: patch-include_error.h,v 1.1 2021/08/10 20:39:51 triaxx Exp $

Fix building of audio/alsa-utils.
To be removed if the following pull request is accepted:
https://github.com/alsa-project/alsa-lib/pull/169

--- include/error.h.orig	2021-06-14 10:28:44.000000000 +0000
+++ include/error.h
@@ -32,6 +32,8 @@
 extern "C" {
 #endif
 
+#include <stdarg.h>
+
 /**
  *  \defgroup Error Error handling
  *  Error handling macros and functions.

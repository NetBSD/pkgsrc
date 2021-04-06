$NetBSD: patch-wsutil_file__util.h,v 1.1 2021/04/06 10:13:32 tnn Exp $

From c8246c99737c7a844f45eb0e777382cc68397d17 Mon Sep 17 00:00:00 2001
From: Michal Ruprich <michalruprich@gmail.com>
Date: Wed, 10 Feb 2021 15:32:18 +0100
Subject: [PATCH] Moving glib.h out of extern C

--- wsutil/file_util.h.orig	2021-03-10 18:21:20.000000000 +0000
+++ wsutil/file_util.h
@@ -11,6 +11,8 @@
 #ifndef __FILE_UTIL_H__
 #define __FILE_UTIL_H__
 
+#include <glib.h>
+
 #include "config.h"
 
 #include "ws_symbol_export.h"
@@ -19,8 +21,6 @@
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 #ifdef _WIN32
 #include <io.h>		/* for _read(), _write(), etc. */
 #include <gmodule.h>

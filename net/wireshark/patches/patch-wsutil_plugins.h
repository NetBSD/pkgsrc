$NetBSD: patch-wsutil_plugins.h,v 1.1 2021/04/06 10:13:32 tnn Exp $

From c8246c99737c7a844f45eb0e777382cc68397d17 Mon Sep 17 00:00:00 2001
From: Michal Ruprich <michalruprich@gmail.com>
Date: Wed, 10 Feb 2021 15:32:18 +0100
Subject: [PATCH] Moving glib.h out of extern C

--- wsutil/plugins.h.orig	2021-03-10 18:21:20.000000000 +0000
+++ wsutil/plugins.h
@@ -11,13 +11,13 @@
 #ifndef __PLUGINS_H__
 #define __PLUGINS_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
 #include <gmodule.h>
-
 #include "ws_symbol_export.h"
 
 typedef void (*plugin_register_func)(void);

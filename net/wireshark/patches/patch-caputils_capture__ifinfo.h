$NetBSD: patch-caputils_capture__ifinfo.h,v 1.2 2021/04/06 10:13:32 tnn Exp $

From c8246c99737c7a844f45eb0e777382cc68397d17 Mon Sep 17 00:00:00 2001
From: Michal Ruprich <michalruprich@gmail.com>
Date: Wed, 10 Feb 2021 15:32:18 +0100
Subject: [PATCH] Moving glib.h out of extern C

--- caputils/capture_ifinfo.h.orig	2021-03-10 18:21:20.000000000 +0000
+++ caputils/capture_ifinfo.h
@@ -11,12 +11,12 @@
 #ifndef __CAPTURE_IFINFO_H__
 #define __CAPTURE_IFINFO_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 /*
  * Explicitly set the interface_type enum values as these values are exposed
  * in the preferences gui.interfaces_hidden_types string.

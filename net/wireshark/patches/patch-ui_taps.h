$NetBSD: patch-ui_taps.h,v 1.1 2021/04/06 10:13:32 tnn Exp $

From c8246c99737c7a844f45eb0e777382cc68397d17 Mon Sep 17 00:00:00 2001
From: Michal Ruprich <michalruprich@gmail.com>
Date: Wed, 10 Feb 2021 15:32:18 +0100
Subject: [PATCH] Moving glib.h out of extern C

--- ui/taps.h.orig	2021-03-10 18:21:20.000000000 +0000
+++ ui/taps.h
@@ -11,12 +11,12 @@
 #ifndef __TAP_REGISTER_H__
 #define __TAP_REGISTER_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 typedef struct _tap_reg {
     const char *cb_name;
     void (*cb_func)(void);

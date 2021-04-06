$NetBSD: patch-ui_rtp__media.h,v 1.1 2021/04/06 10:13:32 tnn Exp $

From c8246c99737c7a844f45eb0e777382cc68397d17 Mon Sep 17 00:00:00 2001
From: Michal Ruprich <michalruprich@gmail.com>
Date: Wed, 10 Feb 2021 15:32:18 +0100
Subject: [PATCH] Moving glib.h out of extern C

--- ui/rtp_media.h.orig	2021-03-10 18:21:20.000000000 +0000
+++ ui/rtp_media.h
@@ -15,6 +15,8 @@
 #ifndef __RTP_MEDIA_H__
 #define __RTP_MEDIA_H__
 
+#include <glib.h>
+
 /** @file
  *  "RTP Player" dialog box common routines.
  *  @ingroup main_ui_group
@@ -24,8 +26,6 @@
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 /****************************************************************************/
 /* INTERFACE */
 /****************************************************************************/

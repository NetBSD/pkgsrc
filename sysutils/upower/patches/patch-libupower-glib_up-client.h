$NetBSD: patch-libupower-glib_up-client.h,v 1.1 2018/07/18 19:18:07 bsiegert Exp $

From 932a6a39e35754be571e1274aec4730fd42dba13 Mon Sep 17 00:00:00 2001
From: Martin Pitt <martin.pitt@ubuntu.com>
Date: Wed, 18 May 2016 09:22:43 +0200
Subject: [PATCH 1/9] lib: Add proper error and cancellable handling to
 UpClient constructor

A GObject's _init() should never fail or block, but this is currently the case
as up_client_init() connects to upowerd on D-Bus. Convert this to the GInitable
interface and provide a new constructor up_client_new_full() which accepts a
GCancellable and GError, so that clients can do proper error handling
and reporting.

This changes up_client_new() to return NULL when connecting to upowerd fails.
This provides a more well-defined behaviour in this case as clients can check
for this and our methods stop segfaulting as they have checks like

   g_return_val_if_fail (UP_IS_CLIENT (client), ...)

Previously we returned a valid object, but trying to call any method on it
segfaulted due to the NULL D-Bus proxy, so client code had no chance to check
whether the UpClient object was really valid.

https://bugs.freedesktop.org/show_bug.cgi?id=95350

--- libupower-glib/up-client.h
+++ libupower-glib/up-client.h
@@ -72,6 +72,7 @@ typedef struct
 /* general */
 GType		 up_client_get_type			(void);
 UpClient	*up_client_new				(void);
+UpClient	*up_client_new_full			(GCancellable *cancellable, GError **error);
 
 /* sync versions */
 UpDevice *	 up_client_get_display_device		(UpClient *client);
-- 
2.8.1


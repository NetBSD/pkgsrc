$NetBSD: patch-xl_main.py,v 1.1 2026/11/13 14:37:34 nia Exp $

From b503b4a5b500a8af20a3844ab308b7a49e681b75 Mon Sep 17 00:00:00 2001
From: Johannes Sasongko <johannes@sasongko.org>
Date: Tue, 25 Mar 2025 14:50:14 +1100
Subject: [PATCH] plugins: Support GIRepository-3.0

GLib 2.84 integrates GIRepository (as `-3.0`). Rather than checking the
GLib version for the right GIRepository version to `require_version`, this
commit simply uses a try-except.

This also moves the `require_version` call from main.py to plugins.py,
where the GIRepository import actually is.

Fixes: https://github.com/exaile/exaile/issues/962

--- xl/main.py.orig	2023-08-02 09:23:35.000000000 +0000
+++ xl/main.py
@@ -54,7 +54,6 @@ def _do_heavy_imports():
     gi.require_version('Gdk', '3.0')
     gi.require_version('Gtk', '3.0')
     gi.require_version('Gst', '1.0')
-    gi.require_version('GIRepository', '2.0')
     gi.require_version('GstPbutils', '1.0')
 
     from gi.repository import GLib, Gio, Gtk

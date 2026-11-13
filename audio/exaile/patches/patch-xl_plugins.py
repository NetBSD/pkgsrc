$NetBSD: patch-xl_plugins.py,v 1.1 2026/11/13 14:37:34 nia Exp $

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

--- xl/plugins.py.orig	2023-08-02 09:23:35.000000000 +0000
+++ xl/plugins.py
@@ -259,6 +259,13 @@ class PluginsManager:
         :param info: The data returned from get_plugin_info()
         """
         import pkgutil
+        import gi
+
+        # https://github.com/exaile/exaile/issues/962
+        try:
+            gi.require_version('GIRepository', '3.0')
+        except ValueError:
+            gi.require_version('GIRepository', '2.0')
         from gi.repository import GIRepository
 
         gir = GIRepository.Repository.get_default()

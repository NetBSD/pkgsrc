$NetBSD: patch-core_plugin_current__world_error.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1231

--- core/plugin/current_world/error.rb.orig	2018-07-08 05:27:15.379532058 +0000
+++ core/plugin/current_world/error.rb
@@ -0,0 +1,6 @@
+# -*- coding: utf-8 -*-
+
+module Plugin::CurrentWorld
+  Error = Class.new(RuntimeError)
+  WorldNotfoundError = Class.new(Error)
+end

$NetBSD: patch-mikutter.rb,v 1.13 2026/04/07 14:32:54 tsutsui Exp $

- pkgsrc can handle location of ruby binary
  https://dev.mikutter.hachune.net/issues/889
- fix crash on startup when YJIT is not enabled in Ruby
  https://dev.mikutter.hachune.net/issues/1606

--- mikutter.rb.orig	2025-02-08 12:21:47.000000000 +0000
+++ mikutter.rb
@@ -1,7 +1,5 @@
-#!/bin/sh
+#! /usr/bin/ruby
 # -*- coding: utf-8; mode: ruby -*-
-exec ruby -x "$0" "$@"
-#!ruby
 =begin rdoc
 = mikutter - simple, powerful and moeful Mastodon client
 Copyright (C) 2009-2024 Toshiaki Asai
@@ -61,7 +59,7 @@ Plugin.call(:boot, nil)
 # _profile_ がtrueなら、プロファイリングした結果を一時ディレクトリに保存する
 def boot!(profile)
   begin
-    RubyVM::YJIT.enable if RUBY_VERSION.split('.') >= %w[3 3]
+    RubyVM::YJIT.enable if RUBY_VERSION.split('.') >= %w[3 3] && defined?(RubyVM::YJIT)
     if profile
       require 'ruby-prof'
       begin

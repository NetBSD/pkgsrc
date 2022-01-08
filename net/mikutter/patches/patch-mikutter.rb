$NetBSD: patch-mikutter.rb,v 1.10 2022/01/08 15:17:54 tsutsui Exp $

- pkgsrc can handle location of ruby binary
  https://dev.mikutter.hachune.net/issues/889

--- mikutter.rb.orig	2021-12-31 15:11:57.000000000 +0000
+++ mikutter.rb
@@ -1,7 +1,5 @@
-#!/bin/sh
+#! /usr/bin/ruby
 # -*- coding: utf-8 -*-
-exec ruby -x "$0" "$@"
-#!ruby
 =begin rdoc
 = mikutter - simple, powerful and moeful Mastodon client
 Copyright (C) 2009-2022 Toshiaki Asai

$NetBSD: patch-mikutter.rb,v 1.5 2017/12/30 05:05:14 tsutsui Exp $

- pkgsrc can handle location of ruby binary
  https://dev.mikutter.hachune.net/issues/889

--- mikutter.rb.orig	2017-06-10 01:11:51.000000000 +0000
+++ mikutter.rb
@@ -1,7 +1,5 @@
-#!/bin/sh
+#! /usr/bin/ruby
 # -*- coding: utf-8 -*-
-exec ruby -x "$0" "$@"
-#!ruby
 =begin rdoc
 = mikutter - the moest twitter client
 Copyright (C) 2009-2017 Toshiaki Asai

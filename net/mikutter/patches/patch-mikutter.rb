$NetBSD: patch-mikutter.rb,v 1.6 2018/01/14 05:15:05 tsutsui Exp $

- pkgsrc can handle location of ruby binary
  https://dev.mikutter.hachune.net/issues/889

--- mikutter.rb.orig	2018-01-13 17:07:11.000000000 +0000
+++ mikutter.rb
@@ -1,7 +1,5 @@
-#!/bin/sh
+#! /usr/bin/ruby
 # -*- coding: utf-8 -*-
-exec ruby -x "$0" "$@"
-#!ruby
 =begin rdoc
 = mikutter - the moest twitter client
 Copyright (C) 2009-2018 Toshiaki Asai

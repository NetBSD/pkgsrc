$NetBSD: patch-core_userconfig.rb,v 1.1 2017/08/26 11:57:49 tsutsui Exp $

- workaround for upstream Redmine ticket #1064

--- core/userconfig.rb.orig	2017-08-26 08:59:57.000000000 +0000
+++ core/userconfig.rb
@@ -1,6 +1,6 @@
 # -*- coding: utf-8 -*-
 
-miquire :core, 'configloader'
+miquire :core, 'configloader', 'plugin'
 
 require 'singleton'
 require 'fileutils'

$NetBSD: patch-mikutter.rb,v 1.4 2017/06/10 09:45:33 tsutsui Exp $

- pkgsrc can handle location of ruby binary
  https://dev.mikutter.hachune.net/issues/889
- pull fix to use delayer-deferred 2.x for upstream ticket #995
  https://dev.mikutter.hachune.net/issues/995

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
@@ -68,12 +66,12 @@ def boot!(profile)
   rescue => exception
     into_debug_mode(exception)
     notice "catch exception `#{exception.class}'"
-    raise exception
+    raise
   rescue Exception => exception
     notice "catch exception `#{exception.class}'"
     exception = Mainloop.exception_filter(exception)
     notice "=> `#{exception.class}'"
-    raise exception end
+    raise end
   exception = Mainloop.exception_filter(nil)
   if exception
     notice "raise mainloop exception `#{exception.class}'"
@@ -82,6 +80,13 @@ def boot!(profile)
 
 def error_handling!(exception)
   notice "catch #{exception.class}"
+  if Mopt.debug && exception.respond_to?(:deferred) && exception.deferred
+    if command_exist?('dot')
+      notice "[[#{exception.deferred.graph_draw}]]"
+    else
+      notice exception.deferred.graph
+    end
+  end
   File.open(File.expand_path(File.join(Environment::TMPDIR, 'crashed_exception')), 'w'){ |io| Marshal.dump(exception, io) }
   raise exception end
 

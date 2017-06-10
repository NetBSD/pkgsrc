$NetBSD: patch-core_boot_delayer.rb,v 1.1 2017/06/10 09:45:33 tsutsui Exp $

- pull fix to use delayer-deferred 2.x for upstream ticket #995
  https://dev.mikutter.hachune.net/issues/995

--- core/boot/delayer.rb.orig	2017-06-10 01:11:51.000000000 +0000
+++ core/boot/delayer.rb
@@ -13,7 +13,7 @@ Delayer.default = Delayer.generate_class
 
 Deferred = Delayer::Deferred::Deferred
 
-module Delayer::Deferred::Deferredable
+module Delayer::Deferred::Deferredable::Chainable
   # エラーをキャッチして、うまい具合にmikutterに表示する。
   # このあとにdeferredをくっつけることもできるが、基本的にはdeferredチェインの終了の時に使う。
   # なお、terminateは受け取ったエラーを再度発生させるので、terminateでエラーを処理した後に特別なエラー処理を挟むこともできる
@@ -23,7 +23,7 @@ module Delayer::Deferred::Deferredable
   # ==== Return
   # Deferred
   def terminate(message = nil, &message_generator)
-    self.trap{|exception|
+    defer = self.trap{|exception|
       message = message_generator.call(exception) if message_generator
       case exception
       when MikuTwitter::RateLimitError
@@ -35,6 +35,13 @@ module Delayer::Deferred::Deferredable
       else
         begin
           notice exception
+          if Mopt.debug
+            if command_exist?('dot')
+              notice "[[#{defer.graph_draw}]]"
+            else
+              notice defer.graph
+            end
+          end
           if(message)
             if(exception.is_a?(Net::HTTPResponse))
               Plugin.activity :error, "#{message} (#{exception.code} #{exception.body})"

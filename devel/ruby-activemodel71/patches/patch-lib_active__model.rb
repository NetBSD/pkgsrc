$NetBSD: patch-lib_active__model.rb,v 1.1 2023/11/30 15:15:26 taca Exp $

* Fix rdoc error.

--- lib/active_model.rb.orig	2023-10-08 14:53:04.111012113 +0000
+++ lib/active_model.rb
@@ -28,7 +28,7 @@ require "active_support/rails"
 require "active_model/version"
 require "active_model/deprecator"
 
-# :include: activemodel/README.rdoc
+# :include: ../README.rdoc
 module ActiveModel
   extend ActiveSupport::Autoload
 

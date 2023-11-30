$NetBSD: patch-lib_active__record.rb,v 1.1 2023/11/30 15:24:18 taca Exp $

* Fix rdoc error.

--- lib/active_record.rb.orig	2023-10-08 15:05:42.717559773 +0000
+++ lib/active_record.rb
@@ -34,7 +34,7 @@ require "active_record/deprecator"
 require "active_model/attribute_set"
 require "active_record/errors"
 
-# :include: activerecord/README.rdoc
+# :include: ../README.rdoc
 module ActiveRecord
   extend ActiveSupport::Autoload
 

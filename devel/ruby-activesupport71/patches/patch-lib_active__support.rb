$NetBSD: patch-lib_active__support.rb,v 1.1 2023/11/30 15:12:17 taca Exp $

* Fix rdoc error.

--- lib/active_support.rb.orig	2023-10-08 14:51:23.056993896 +0000
+++ lib/active_support.rb
@@ -32,7 +32,7 @@ require "active_support/broadcast_logger
 require "active_support/lazy_load_hooks"
 require "active_support/core_ext/date_and_time/compatibility"
 
-# :include: activesupport/README.rdoc
+# :include: ../README.rdoc
 module ActiveSupport
   extend ActiveSupport::Autoload
 

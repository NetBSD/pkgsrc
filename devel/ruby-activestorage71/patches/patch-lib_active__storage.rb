$NetBSD: patch-lib_active__storage.rb,v 1.1 2023/11/30 15:26:21 taca Exp $

* Fix rdoc error.

--- lib/active_storage.rb.orig	2023-10-08 15:08:19.900971706 +0000
+++ lib/active_storage.rb
@@ -35,7 +35,7 @@ require "active_storage/errors"
 require "marcel"
 
 # :markup: markdown
-# :include: activestorage/README.md
+# :include: ../README.md
 module ActiveStorage
   extend ActiveSupport::Autoload
 

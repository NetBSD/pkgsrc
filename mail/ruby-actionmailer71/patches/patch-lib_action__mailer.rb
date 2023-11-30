$NetBSD: patch-lib_action__mailer.rb,v 1.1 2023/11/30 15:28:19 taca Exp $

* Fix rdoc error.

--- lib/action_mailer.rb.orig	2023-10-08 15:10:14.403018678 +0000
+++ lib/action_mailer.rb
@@ -35,7 +35,7 @@ require "active_support/core_ext/module/
 require "active_support/core_ext/string/inflections"
 require "active_support/lazy_load_hooks"
 
-# :include: actionmailer/README.rdoc
+# :include: ../README.rdoc
 module ActionMailer
   extend ::ActiveSupport::Autoload
 

$NetBSD: patch-lib_action__mailbox.rb,v 1.1 2023/11/30 15:30:51 taca Exp $

* Fix rdoc error.

--- lib/action_mailbox.rb.orig	2023-10-08 15:14:49.568204787 +0000
+++ lib/action_mailbox.rb
@@ -9,7 +9,7 @@ require "action_mailbox/deprecator"
 require "action_mailbox/mail_ext"
 
 # :markup: markdown
-# :include: actionmailbox/README.md
+# :include: ../README.md
 module ActionMailbox
   extend ActiveSupport::Autoload
 

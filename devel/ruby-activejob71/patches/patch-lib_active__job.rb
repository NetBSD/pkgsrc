$NetBSD: patch-lib_active__job.rb,v 1.1 2023/11/30 15:17:21 taca Exp $

* Fix rdoc error.

--- lib/active_job.rb.orig	2023-10-08 14:55:54.336244357 +0000
+++ lib/active_job.rb
@@ -30,7 +30,7 @@ require "active_job/deprecator"
 require "global_id"
 
 # :markup: markdown
-# :include: activejob/README.md
+# :include: ../README.md
 module ActiveJob
   extend ActiveSupport::Autoload
 

$NetBSD: patch-lib_rails.rb,v 1.1 2023/11/30 15:34:32 taca Exp $

* Fix rdoc error.

--- lib/rails.rb.orig	2023-10-08 15:20:22.096724599 +0000
+++ lib/rails.rb
@@ -24,7 +24,7 @@ silence_warnings do
   Encoding.default_internal = Encoding::UTF_8
 end
 
-# :include: railties/README.rdoc
+# :include: ../README.rdoc
 module Rails
   extend ActiveSupport::Autoload
   extend ActiveSupport::Benchmarkable

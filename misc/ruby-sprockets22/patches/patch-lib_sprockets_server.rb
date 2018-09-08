$NetBSD: patch-lib_sprockets_server.rb,v 1.1 2018/09/08 16:59:45 taca Exp $

Try to avoid CVE-2018-3760.

--- lib/sprockets/server.rb.orig	2018-06-20 01:37:23.885194827 +0000
+++ lib/sprockets/server.rb
@@ -90,7 +90,7 @@ module Sprockets
         #
         #     http://example.org/assets/../../../etc/passwd
         #
-        path.include?("..") || Pathname.new(path).absolute?
+        path.include?("..") || Pathname.new(path).absolute? || path.include?("://")
       end
 
       # Returns a 403 Forbidden response tuple

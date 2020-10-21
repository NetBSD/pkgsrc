$NetBSD: patch-lib_webrick_httprequest.rb,v 1.1.2.2 2020/10/21 20:02:44 spz Exp $

Add fix for CVE-2020-25613.

--- lib/webrick/httprequest.rb.orig	2020-03-31 12:15:56.000000000 +0000
+++ lib/webrick/httprequest.rb
@@ -226,9 +226,9 @@ module WEBrick
         raise HTTPStatus::BadRequest, "bad URI `#{@unparsed_uri}'."
       end
 
-      if /close/io =~ self["connection"]
+      if /\Aclose\z/io =~ self["connection"]
         @keep_alive = false
-      elsif /keep-alive/io =~ self["connection"]
+      elsif /\Akeep-alive\z/io =~ self["connection"]
         @keep_alive = true
       elsif @http_version < "1.1"
         @keep_alive = false
@@ -475,7 +475,7 @@ module WEBrick
       return unless socket
       if tc = self['transfer-encoding']
         case tc
-        when /chunked/io then read_chunked(socket, block)
+        when /\Achunked\z/io then read_chunked(socket, block)
         else raise HTTPStatus::NotImplemented, "Transfer-Encoding: #{tc}."
         end
       elsif self['content-length'] || @remaining_size

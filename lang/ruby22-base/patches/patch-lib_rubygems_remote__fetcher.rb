$NetBSD: patch-lib_rubygems_remote__fetcher.rb,v 1.1 2015/06/23 14:04:40 taca Exp $

Fix for CVE-2015-3900.

--- lib/rubygems/remote_fetcher.rb.orig	2014-11-17 03:55:02.000000000 +0000
+++ lib/rubygems/remote_fetcher.rb
@@ -94,7 +94,13 @@ class Gem::RemoteFetcher
     rescue Resolv::ResolvError
       uri
     else
-      URI.parse "#{uri.scheme}://#{res.target}#{uri.path}"
+      target = res.target.to_s.strip
+
+      if /\.#{Regexp.quote(host)}\z/ =~ target
+        return URI.parse "#{uri.scheme}://#{target}#{uri.path}"
+      end
+
+      uri
     end
   end
 

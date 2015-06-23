$NetBSD: patch-lib_rubygems_remote__fetcher.rb,v 1.1 2015/06/23 14:03:02 taca Exp $

Fix for CVE-2015-3900.

--- lib/rubygems/remote_fetcher.rb.orig	2013-10-24 14:31:17.000000000 +0000
+++ lib/rubygems/remote_fetcher.rb
@@ -103,7 +103,13 @@ class Gem::RemoteFetcher
     rescue Resolv::ResolvError
       uri
     else
-      URI.parse "#{res.target}#{uri.path}"
+      target = res.target.to_s.strip
+
+      if /\.#{Regexp.quote(host)}\z/ =~ target
+        return URI.parse "#{uri.scheme}://#{target}#{uri.path}"
+      end
+
+      uri
     end
   end
 

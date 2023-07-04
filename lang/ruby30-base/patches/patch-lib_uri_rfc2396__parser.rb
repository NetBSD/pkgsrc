$NetBSD: patch-lib_uri_rfc2396__parser.rb,v 1.1.2.2 2023/07/04 15:44:43 bsiegert Exp $

Fix for CVE-2023-36617 updating uri to 0.10.3.

--- lib/uri/rfc2396_parser.rb.orig	2023-03-30 12:41:03.000000000 +0000
+++ lib/uri/rfc2396_parser.rb
@@ -491,8 +491,8 @@ module URI
       ret = {}
 
       # for URI::split
-      ret[:ABS_URI] = Regexp.new('\A\s*' + pattern[:X_ABS_URI] + '\s*\z', Regexp::EXTENDED)
-      ret[:REL_URI] = Regexp.new('\A\s*' + pattern[:X_REL_URI] + '\s*\z', Regexp::EXTENDED)
+      ret[:ABS_URI] = Regexp.new('\A\s*+' + pattern[:X_ABS_URI] + '\s*\z', Regexp::EXTENDED)
+      ret[:REL_URI] = Regexp.new('\A\s*+' + pattern[:X_REL_URI] + '\s*\z', Regexp::EXTENDED)
 
       # for URI::extract
       ret[:URI_REF]     = Regexp.new(pattern[:URI_REF])

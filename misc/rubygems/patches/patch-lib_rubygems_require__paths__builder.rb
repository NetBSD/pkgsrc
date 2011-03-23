$NetBSD: patch-lib_rubygems_require__paths__builder.rb,v 1.1 2011/03/23 14:35:05 taca Exp $

--- lib/rubygems/require_paths_builder.rb.orig	2011-03-04 00:01:24.000000000 +0000
+++ lib/rubygems/require_paths_builder.rb
@@ -14,5 +14,5 @@ module Gem::RequirePathsBuilder
       file.puts spec.bindir if spec.bindir
     end
   end
-end if Gem::QUICKLOADER_SUCKAGE
-
+end # if Gem::QUICKLOADER_SUCKAGE
+    # it could be enabled after 1.9.2's rubygem updated.

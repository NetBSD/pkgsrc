$NetBSD: patch-lib_rubygems_require__paths__builder.rb,v 1.2 2011/08/12 15:50:44 taca Exp $

Compatibility with ruby19-base's gem.

--- lib/rubygems/require_paths_builder.rb.orig	2011-05-18 22:23:53.000000000 +0000
+++ lib/rubygems/require_paths_builder.rb
@@ -14,5 +14,5 @@ module Gem::RequirePathsBuilder
       file.puts spec.bindir if spec.bindir
     end
   end
-end if Gem::QUICKLOADER_SUCKAGE
-
+end # if Gem::QUICKLOADER_SUCKAGE
+    # it could be enabled after 1.9.x's rubygem updated.

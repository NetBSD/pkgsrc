$NetBSD: patch-lib_rubygems_require__paths__builder.rb,v 1.1 2011/11/08 15:22:45 taca Exp $

* Avoid to use Gem::RequirePathsBuilder.

--- lib/rubygems/require_paths_builder.rb.orig	2010-06-27 01:41:40.000000000 +0000
+++ lib/rubygems/require_paths_builder.rb
@@ -9,5 +9,4 @@ module Gem::RequirePathsBuilder
       file.puts require_paths
     end
   end
-end
-
+end if false

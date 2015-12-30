$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2015/12/30 14:59:42 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2015-12-16 05:07:31.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -30,7 +30,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION then
              [
-               File.dirname(RbConfig::CONFIG['sitedir']),
+               File.dirname(RbConfig::CONFIG['vendordir']),
                'Gems',
                RbConfig::CONFIG['ruby_version']
              ]

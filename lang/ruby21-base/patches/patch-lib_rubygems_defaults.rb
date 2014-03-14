$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2014-02-06 02:59:36.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -29,7 +29,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION then
              [
-               File.dirname(RbConfig::CONFIG['sitedir']),
+               File.dirname(RbConfig::CONFIG['vendordir']),
                'Gems',
                RbConfig::CONFIG['ruby_version']
              ]

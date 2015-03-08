$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2015/03/08 16:24:55 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2014-09-14 03:30:02.000000000 +0000
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

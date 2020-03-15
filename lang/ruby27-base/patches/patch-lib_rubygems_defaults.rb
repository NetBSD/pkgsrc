$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2020/03/15 15:26:22 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2018-11-21 10:20:47.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -30,7 +30,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION
              [
-               File.dirname(RbConfig::CONFIG['sitedir']),
+               File.dirname(RbConfig::CONFIG['vendordir']),
                'Gems',
                RbConfig::CONFIG['ruby_version']
              ]

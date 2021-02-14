$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2021/02/14 14:32:41 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2020-12-08 09:02:31.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -36,7 +36,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION
              [
-               File.dirname(RbConfig::CONFIG['sitedir']),
+               File.dirname(RbConfig::CONFIG['vendordir']),
                'Gems',
                RbConfig::CONFIG['ruby_version'],
              ]

$NetBSD: patch-lib_rubygems_defaults.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2013-06-21 16:16:31.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -21,7 +21,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION then
              [
-               File.dirname(ConfigMap[:sitedir]),
+               File.dirname(ConfigMap[:vendordir]),
                'Gems',
                ConfigMap[:ruby_version]
              ]

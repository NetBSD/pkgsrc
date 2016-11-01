$NetBSD: patch-squib.gemspec,v 1.1 2016/11/01 21:48:36 wiz Exp $

Match pkgsrc version of roo.

--- squib.gemspec.orig	2016-11-01 21:43:10.265599960 +0000
+++ squib.gemspec
@@ -30,7 +30,7 @@ Gem::Specification.new do |spec|
   spec.add_runtime_dependency 'cairo', '~> 1.15.2'
   spec.add_runtime_dependency 'pango', '~> 3.0.9'
   spec.add_runtime_dependency 'nokogiri', '~> 1.6.7'
-  spec.add_runtime_dependency 'roo', '~> 2.4.0'
+  spec.add_runtime_dependency 'roo', '~> 2.5.1'
   spec.add_runtime_dependency 'rsvg2', '~> 3.0.9'
   spec.add_runtime_dependency 'mercenary', '~> 0.3.4'
   spec.add_runtime_dependency 'ruby-progressbar', '~> 1.8'

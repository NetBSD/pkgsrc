$NetBSD: patch-rake_extensiontask.rb,v 1.2 2017/04/14 21:35:34 minskim Exp $

* Add proper compiler flags.

--- rake/extensiontask.rb.orig	2007-03-23 11:05:12.000000000 +0000
+++ rake/extensiontask.rb
@@ -98,15 +98,15 @@ module Rake
     def define_rules
       for ext in env[:c_exts]
         Rake::Task.create_rule '.'+env[:objext] => '.'+ext do |r|
-          sh_cmd :cc, :cflags, :cppflags, {'-D' => :defines}, {'-I' => :includedirs}, {'-I' => :topdir},
-                '-c', '-o', r.name, r.sources
+          sh_cmd :cc, :cflags, :ccdlflags, :cppflags, {'-D' => :defines}, {'-I' => :includedirs}, {'-I' => :topdir},
+                '-c', '-o', r.name, r.sources.join(' ')
         end
       end
 
       for ext in env[:cpp_exts]
         Rake::Task.create_rule '.'+env[:objext] => '.'+ext do |r|
           sh_cmd :cxx, :cxxflags, :cppflags, {'-D' => :defines}, {'-I' => :includedirs}, {'-I' => :topdir},
-                '-o', r.name, '-c', r.sources
+                '-o', r.name, '-c', r.sources.join(' ')
         end
       end
     end
@@ -121,7 +121,7 @@ module Rake
         @@DefaultEnv = e
       end
 
-      Config::CONFIG.merge(ENV).each { |k, v| @@DefaultEnv[k.downcase.to_sym] = v }
+      RbConfig::CONFIG.merge(ENV).each { |k, v| @@DefaultEnv[k.downcase.to_sym] = v }
       @@DefaultEnv = {
         :cxx => 'c++',
         :cxxflags => '',

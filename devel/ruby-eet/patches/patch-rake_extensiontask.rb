$NetBSD: patch-rake_extensiontask.rb,v 1.1 2011/08/12 16:29:04 taca Exp $

* Add proper compiler flags.

--- rake/extensiontask.rb.orig	2007-03-23 11:05:12.000000000 +0000
+++ rake/extensiontask.rb
@@ -98,7 +98,7 @@ module Rake
     def define_rules
       for ext in env[:c_exts]
         Rake::Task.create_rule '.'+env[:objext] => '.'+ext do |r|
-          sh_cmd :cc, :cflags, :cppflags, {'-D' => :defines}, {'-I' => :includedirs}, {'-I' => :topdir},
+          sh_cmd :cc, :cflags, :ccdlflags, :cppflags, {'-D' => :defines}, {'-I' => :includedirs}, {'-I' => :topdir},
                 '-c', '-o', r.name, r.sources
         end
       end

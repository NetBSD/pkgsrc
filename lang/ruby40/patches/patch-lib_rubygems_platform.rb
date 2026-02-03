$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2026/02/03 16:00:34 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2025-12-25 03:20:40.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -79,11 +79,7 @@ class Gem::Platform
     when String then
       cpu, os = arch.sub(/-+$/, "").split("-", 2)
 
-      @cpu = if cpu&.match?(/i\d86/)
-        "x86"
-      else
-        cpu
-      end
+      @cpu = cpu
 
       if os.nil?
         @cpu = nil
@@ -111,6 +107,7 @@ class Gem::Platform
                         @cpu = "x86" if @cpu.nil? && os.end_with?("32")
                         [os, version]
                       when /netbsdelf/ then                  ["netbsdelf", nil]
+                      when /netbsd/ then                     ["netbsd", nil]
                       when /openbsd-?(\d+\.\d+)?/ then       ["openbsd",   $1]
                       when /solaris-?(\d+\.\d+)?/ then       ["solaris",   $1]
                       when /wasi/ then                       ["wasi",      nil]

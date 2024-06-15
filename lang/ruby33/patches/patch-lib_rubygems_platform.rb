$NetBSD: patch-lib_rubygems_platform.rb,v 1.2 2024/06/15 15:43:52 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2024-06-11 23:54:24.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -94,12 +94,7 @@ class Gem::Platform
         arch.last << "-#{extra}"
       end
 
-      cpu = arch.shift
-
-      @cpu = case cpu
-             when /i\d86/ then "x86"
-             else cpu
-      end
+      @cpu = arch.shift
 
       if arch.length == 2 && arch.last.match?(/^\d+(\.\d+)?$/) # for command-line
         @os, @version = arch
@@ -132,6 +127,7 @@ class Gem::Platform
                         @cpu = "x86" if @cpu.nil? && os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             ["netbsdelf", nil]
+                      when /netbsd/ then                ["netbsd", nil]
                       when /openbsd(\d+\.\d+)?/ then    ["openbsd",   $1]
                       when /solaris(\d+\.\d+)?/ then    ["solaris",   $1]
                       when /wasi/ then                  ["wasi",      nil]

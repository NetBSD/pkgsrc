$NetBSD: patch-lib_rubygems_platform.rb,v 1.3 2022/11/26 13:02:49 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2022-11-24 10:20:31.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -76,12 +76,7 @@ class Gem::Platform
         arch.last << "-#{extra}"
       end
 
-      cpu = arch.shift
-
-      @cpu = case cpu
-      when /i\d86/ then "x86"
-      else cpu
-      end
+      @cpu = arch.shift
 
       if arch.length == 2 && arch.last =~ /^\d+(\.\d+)?$/ # for command-line
         @os, @version = arch
@@ -111,6 +106,7 @@ class Gem::Platform
         @cpu = "x86" if @cpu.nil? && os =~ /32$/
         [os, version]
       when /netbsdelf/ then             [ "netbsdelf", nil ]
+      when /netbsd/ then                [ "netbsd",    nil ]
       when /openbsd(\d+\.\d+)?/ then    [ "openbsd",   $1  ]
       when /bitrig(\d+\.\d+)?/ then     [ "bitrig",    $1  ]
       when /solaris(\d+\.\d+)?/ then    [ "solaris",   $1  ]

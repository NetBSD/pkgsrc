$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2020/03/15 15:26:22 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2018-11-21 10:20:47.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -61,12 +61,7 @@ class Gem::Platform
         arch.last << "-#{extra}"
       end
 
-      cpu = arch.shift
-
-      @cpu = case cpu
-             when /i\d86/ then 'x86'
-             else cpu
-             end
+      @cpu = arch.shift
 
       if arch.length == 2 and arch.last =~ /^\d+(\.\d+)?$/  # for command-line
         @os, @version = arch
@@ -95,6 +90,7 @@ class Gem::Platform
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsd',    nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /bitrig(\d+\.\d+)?/ then     [ 'bitrig',    $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]

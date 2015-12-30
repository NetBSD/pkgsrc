$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2015/12/30 14:59:42 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2015-12-16 05:07:31.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -63,10 +63,7 @@ class Gem::Platform
 
       cpu = arch.shift
 
-      @cpu = case cpu
-             when /i\d86/ then 'x86'
-             else cpu
-             end
+      @cpu = cpu
 
       if arch.length == 2 and arch.last =~ /^\d+(\.\d+)?$/ then # for command-line
         @os, @version = arch
@@ -94,7 +91,7 @@ class Gem::Platform
                         os, version = $1, $3
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
-                      when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsdelf', nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /bitrig(\d+\.\d+)?/ then     [ 'bitrig',    $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]

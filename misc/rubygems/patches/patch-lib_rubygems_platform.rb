$NetBSD: patch-lib_rubygems_platform.rb,v 1.3 2015/03/08 14:44:16 taca Exp $

* Tweak os for NetBSD.
* Better Solaris support.

--- lib/rubygems/platform.rb.orig	2015-02-03 22:17:54.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -62,10 +62,7 @@ class Gem::Platform
 
       cpu = arch.shift
 
-      @cpu = case cpu
-             when /i\d86/ then 'x86'
-             else cpu
-             end
+      @cpu = cpu
 
       if arch.length == 2 and arch.last =~ /^\d+(\.\d+)?$/ then # for command-line
         @os, @version = arch
@@ -93,7 +90,7 @@ class Gem::Platform
                         os, version = $1, $3
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
-                      when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsd',    nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]
                       # test

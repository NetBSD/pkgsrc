$NetBSD: patch-lib_rubygems_platform.rb,v 1.2 2015/03/08 14:53:39 taca Exp $

Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -51,10 +51,7 @@ class Gem::Platform
 
       cpu = arch.shift
 
-      @cpu = case cpu
-             when /i\d86/ then 'x86'
-             else cpu
-             end
+      @cpu = cpu
 
       if arch.length == 2 and arch.last =~ /^\d+(\.\d+)?$/ then # for command-line
         @os, @version = arch
@@ -81,7 +78,7 @@ class Gem::Platform
                         os, version = $1, $3
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
-                      when /netbsdelf/ then            [ 'netbsdelf', nil ]
+                      when /netbsd/ then               [ 'netbsd',    nil ]
                       when /openbsd(\d+\.\d+)/ then    [ 'openbsd',   $1  ]
                       when /solaris(\d+\.\d+)/ then    [ 'solaris',   $1  ]
                       # test

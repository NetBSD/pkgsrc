$NetBSD: patch-lib_rubygems_platform.rb,v 1.2 2015/01/25 16:13:13 taca Exp $

Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2014-07-21 18:50:29.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -63,7 +63,7 @@ class Gem::Platform
       cpu = arch.shift
 
       @cpu = case cpu
-             when /i\d86/ then 'x86'
+             when /noti\d86/ then 'x86'
              else cpu
              end
 
@@ -94,8 +94,9 @@ class Gem::Platform
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsd', nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
-                      when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]
+                      when /solaris(\d+\.\d+)?/ then    [ "solaris#{$1}", nil ]
                       # test
                       when /^(\w+_platform)(\d+)?/ then [ $1,          $2  ]
                       else                              [ 'unknown',   nil ]

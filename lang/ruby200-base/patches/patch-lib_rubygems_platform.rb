$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2014/03/13 18:00:02 taca Exp $

Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2013-07-22 16:33:18.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -83,6 +83,7 @@ class Gem::Platform
                         os, version = $1, $3
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsd', nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]

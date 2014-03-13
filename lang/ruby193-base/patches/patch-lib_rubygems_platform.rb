$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2014/03/13 17:53:37 taca Exp $

Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -82,6 +82,7 @@ class Gem::Platform
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then            [ 'netbsdelf', nil ]
+                      when /netbsd/ then               [ 'netbsd', nil ]
                       when /openbsd(\d+\.\d+)/ then    [ 'openbsd',   $1  ]
                       when /solaris(\d+\.\d+)/ then    [ 'solaris',   $1  ]
                       # test

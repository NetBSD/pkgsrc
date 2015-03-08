$NetBSD: patch-lib_rubygems_platform.rb,v 1.3 2015/03/08 15:08:33 taca Exp $

* Don't replace "i486" to "x86".
* Make various NetBSD to simple "netbsd".

--- lib/rubygems/platform.rb.orig	2014-02-06 02:59:36.000000000 +0000
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
@@ -93,7 +90,8 @@ class Gem::Platform
                         os, version = $1, $3
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
-                      when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd(elf)?([\d\.]*)-*.*/ then
+                        ['netbsd', ($2.empty?)? nil: $2]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]
                       # test

$NetBSD: patch-lib_quickml_utils.rb,v 1.1 2012/08/11 13:51:20 obache Exp $

* specify character coding system with ruby-1.9 way
* use fileutils instead of deprecated ftools

--- lib/quickml/utils.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/utils.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/utils - a part of quickml server
 #
@@ -8,10 +9,9 @@
 # You can redistribute it and/or modify it under the terms of 
 # the GNU General Public License version 2.
 #
-$KCODE = 'e'
 require 'kconv'
 require 'net/smtp'
-require 'ftools'
+require 'fileutils'
 
 class TooLongLine < Exception; end
 class IO

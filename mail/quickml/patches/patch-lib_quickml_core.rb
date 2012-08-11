$NetBSD: patch-lib_quickml_core.rb,v 1.1 2012/08/11 13:51:20 obache Exp $

* specify character coding system with ruby-1.9 way

--- lib/quickml/core.rb.orig	2004-06-08 20:15:11.000000000 +0000
+++ lib/quickml/core.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/core - a part of quickml server
 #
@@ -8,7 +9,6 @@
 # You can redistribute it and/or modify it under the terms of 
 # the GNU General Public License version 2.
 #
-$KCODE='e'
 require 'quickml/utils'
 require 'quickml/gettext'
 

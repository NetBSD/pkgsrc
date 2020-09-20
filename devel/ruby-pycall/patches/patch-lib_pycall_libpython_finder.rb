$NetBSD: patch-lib_pycall_libpython_finder.rb,v 1.1 2020/09/20 08:34:37 ryoon Exp $

* Detect Python command from pkgsrc.

--- lib/pycall/libpython/finder.rb.orig	2020-09-18 09:47:08.145777201 +0000
+++ lib/pycall/libpython/finder.rb
@@ -20,6 +20,7 @@ module PyCall
 
       class << self
         DEFAULT_PYTHON = [
+          -'@PYTHONBIN@',
           -'python3',
           -'python',
         ].freeze

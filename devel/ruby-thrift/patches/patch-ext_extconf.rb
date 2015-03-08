$NetBSD: patch-ext_extconf.rb,v 1.1 2015/03/08 16:07:28 taca Exp $

* Don't treat warning as error.

--- ext/extconf.rb.orig	2015-01-18 12:03:28.000000000 +0000
+++ ext/extconf.rb
@@ -22,7 +22,7 @@ if defined?(RUBY_ENGINE) && RUBY_ENGINE 
 else
   require 'mkmf'
 
-  $CFLAGS = "-g -O2 -Wall -Werror"
+  $CFLAGS = "-g -O2 -Wall"
 
   have_func("strlcpy", "string.h")
 

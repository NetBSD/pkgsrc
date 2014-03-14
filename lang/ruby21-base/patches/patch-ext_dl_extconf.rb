$NetBSD: patch-ext_dl_extconf.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

--- ext/dl/extconf.rb.orig	2012-02-25 05:47:16.000000000 +0000
+++ ext/dl/extconf.rb
@@ -1,7 +1,6 @@
 require 'mkmf'
 
 if RbConfig::CONFIG['GCC'] == 'yes'
-  (have_macro("__clang__") ? $LDFLAGS : $CFLAGS) << " -fno-defer-pop"
   $CFLAGS << " -fno-omit-frame-pointer"
 end
 

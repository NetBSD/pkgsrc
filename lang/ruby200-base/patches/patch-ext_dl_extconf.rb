$NetBSD: patch-ext_dl_extconf.rb,v 1.1 2013/10/25 21:47:20 joerg Exp $

--- ext/dl/extconf.rb.orig	2012-02-25 05:47:16.000000000 +0000
+++ ext/dl/extconf.rb
@@ -1,7 +1,6 @@
 require 'mkmf'
 
 if RbConfig::CONFIG['GCC'] == 'yes'
-  (have_macro("__clang__") ? $LDFLAGS : $CFLAGS) << " -fno-defer-pop"
   $CFLAGS << " -fno-omit-frame-pointer"
 end
 

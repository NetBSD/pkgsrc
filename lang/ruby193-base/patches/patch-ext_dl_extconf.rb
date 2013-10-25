$NetBSD: patch-ext_dl_extconf.rb,v 1.1 2013/10/25 21:47:20 joerg Exp $

--- ext/dl/extconf.rb.orig	2013-10-15 20:48:38.000000000 +0000
+++ ext/dl/extconf.rb
@@ -1,7 +1,7 @@
 require 'mkmf'
 
 if RbConfig::CONFIG['GCC'] == 'yes'
-  $CFLAGS << " -fno-defer-pop -fno-omit-frame-pointer"
+  $CFLAGS << " -fno-omit-frame-pointer"
 end
 
 $INSTALLFILES = [

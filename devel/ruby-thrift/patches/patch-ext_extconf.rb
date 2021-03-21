$NetBSD: patch-ext_extconf.rb,v 1.3 2021/03/21 12:44:03 taca Exp $

Don't treat warnings as errors.

--- ext/extconf.rb.orig	2019-09-17 13:49:26.000000000 +0000
+++ ext/extconf.rb
@@ -26,7 +26,7 @@ else
   $ARCH_FLAGS = RbConfig::CONFIG['CFLAGS'].scan( /(-arch )(\S+)/ ).map{|x,y| x + y + ' ' }.join('')
 
 
-  $CFLAGS = "-fsigned-char -g -O2 -Wall -Werror " + $ARCH_FLAGS
+  $CFLAGS = "-fsigned-char -g -O2 -Wall " + $ARCH_FLAGS
 
   have_func("strlcpy", "string.h")
 

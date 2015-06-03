$NetBSD: patch-extconf.rb,v 1.1 2015/06/03 14:47:11 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- extconf.rb.orig	2005-01-05 02:25:14.000000000 +0000
+++ extconf.rb
@@ -39,7 +39,7 @@ end
 $CFLAGS = $CFLAGS + ' -std=c99 -g -pipe'
 
 $LDFLAGS = CONFIG['LDFLAGS']
-$LIBPATH.push(Config::CONFIG['libdir'])
+$LIBPATH.push(RbConfig::CONFIG['libdir'])
 
 def crash(str)
   printf(" extconf failure: %s\n", str)

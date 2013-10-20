$NetBSD: patch-rubynative_src_extconf.rb,v 1.1 2013/10/20 17:49:58 joerg Exp $

--- rubynative/src/extconf.rb.orig	2013-10-18 22:14:45.000000000 +0000
+++ rubynative/src/extconf.rb
@@ -6,7 +6,7 @@ ENV["PATH"] = ENV["PATH"] + ":/usr/local
 estcflags = `estconfig --cflags`.chomp
 estldflags = `estconfig --ldflags`.chomp
 estlibs = `estconfig --libs`.chomp
-$CFLAGS = "-I. -I.. -I../.. #{estcflags} -Wall #{$CFLAGS} -O3 -fomit-frame-pointer -fforce-addr"
+$CFLAGS = "-I. -I.. -I../.. #{estcflags} -Wall #{$CFLAGS} -O3 -fomit-frame-pointer"
 $LDFLAGS = "#{$LDFLAGS} -L. -L.. -L../.. #{estldflags}"
 $libs = "#{$libs} #{estlibs}"
 

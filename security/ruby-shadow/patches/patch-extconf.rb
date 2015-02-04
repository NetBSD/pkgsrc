$NetBSD: patch-extconf.rb,v 1.2 2015/02/04 16:14:57 taca Exp $

* Relax condition to make more operating system support.
* Do not override LDFLAGS.

--- extconf.rb.orig	2015-01-26 14:06:33.000000000 +0000
+++ extconf.rb
@@ -18,8 +18,7 @@ implementation = case CONFIG['host_os']
                  when /sunos|solaris/i; 'shadow'
                  when /freebsd|mirbsd|netbsd|openbsd/i; 'pwd'
                  when /darwin/i; 'pwd'
-                 else; nil
-                   "This library works on OS X, FreeBSD, MirBSD, NetBSD, OpenBSD, Solaris and Linux."
+                 else; 'pwd'
                  end
 
 ok = true
@@ -29,7 +28,6 @@ when 'shadow'
   #$LDFLAGS = "-lshadow"
 
   if( ! (ok &= have_library("shadow","getspent")) )
-    $LDFLAGS = ""
     ok = have_func("getspent")
   end
 

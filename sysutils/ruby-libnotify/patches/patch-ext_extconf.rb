$NetBSD: patch-ext_extconf.rb,v 1.1 2013/09/18 08:33:32 obache Exp $

* not using gems in pkgsrc.

--- ext/extconf.rb.orig	2012-11-24 17:54:50.000000000 +0000
+++ ext/extconf.rb
@@ -5,8 +5,6 @@ type=0, DEBUG
 type=1, RELEASE
 =end
 
-require 'rubygems'
-
 begin
   require 'mkmf-gnome2'
   require 'gtk2'

$NetBSD: patch-gconf_gconfmm_callback.h,v 1.1 2021/03/22 14:41:41 ryoon Exp $

* Fix error with devlel/glib2-2.68.0
../gconfmm/callback.h:25:1: note: 'extern "C"' linkage started here
(snip)
/usr/include/g++/type_traits:2741:3: error: template with C linkage

--- gconf/gconfmm/callback.h.orig	2011-10-18 15:33:49.000000000 +0000
+++ gconf/gconfmm/callback.h
@@ -22,10 +22,7 @@
 #ifndef GCONFMM_CALLBACK_H
 #define GCONFMM_CALLBACK_H
 
-extern "C"
-{
 #include <gconf/gconf-client.h>
-}
 
 #include <glibmm/object.h>
 #include <gconfmm/entry.h>

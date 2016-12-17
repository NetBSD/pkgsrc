$NetBSD: patch-igs_connect.hh,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/connect.hh.orig	2015-11-20 13:38:53.000000000 +0000
+++ igs/connect.hh
@@ -9,7 +9,6 @@
 
 #ifndef IGS_CONNECT_HH
 #define IGS_CONNECT_HH
-#include <sigc++/object.h>
 #include <sigc++/signal.h>
 #include <glibmm/refptr.h>
 #include <glibmm/object.h>

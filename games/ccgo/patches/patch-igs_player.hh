$NetBSD: patch-igs_player.hh,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/player.hh.orig	2015-11-20 13:39:18.000000000 +0000
+++ igs/player.hh
@@ -12,7 +12,6 @@
 #include "custom_text.hh"
 #include "datetime.hh"
 #include <string>
-#include <sigc++/object.h>
 #include <ctime>
 
 namespace igs

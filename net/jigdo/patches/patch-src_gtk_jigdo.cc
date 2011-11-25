$NetBSD: patch-src_gtk_jigdo.cc,v 1.1 2011/11/25 22:11:44 joerg Exp $

--- src/gtk/jigdo.cc.orig	2011-11-25 18:44:14.000000000 +0000
+++ src/gtk/jigdo.cc
@@ -12,10 +12,10 @@
 #include <config.h>
 
 #if DEBUG
-#  include <string.h>
 #  include <unistd-jigdo.h>
 #endif
 
+#include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>

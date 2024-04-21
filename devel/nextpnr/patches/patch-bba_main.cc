$NetBSD: patch-bba_main.cc,v 1.1 2024/04/21 16:28:25 adam Exp $

Fix build with newer boost.

--- bba/main.cc.orig	2024-04-21 16:11:14.140919358 +0000
+++ bba/main.cc
@@ -19,7 +19,7 @@
  */
 
 #include <assert.h>
-#include <boost/filesystem/convenience.hpp>
+#include <boost/filesystem/path.hpp>
 #include <boost/program_options.hpp>
 #include <iostream>
 #include <map>

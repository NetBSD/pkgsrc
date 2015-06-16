$NetBSD: patch-libgrive_test_drive_ResourceTreeTest.cc,v 1.1.1.1 2015/06/16 16:15:37 abs Exp $

Fix include

--- libgrive/test/drive/ResourceTreeTest.cc.orig	2015-05-31 19:35:15.000000000 +0000
+++ libgrive/test/drive/ResourceTreeTest.cc
@@ -21,8 +21,8 @@
 
 #include "Assert.hh"
 
-#include "drive/ResourceTree.hh"
-#include "drive/Resource.hh"
+#include "base/ResourceTree.hh"
+#include "base/Resource.hh"
 
 #include <iostream>
 

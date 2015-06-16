$NetBSD: patch-libgrive_test_drive_ResourceTest.cc,v 1.1.1.1 2015/06/16 16:15:37 abs Exp $

Fix include

--- libgrive/test/drive/ResourceTest.cc.orig	2015-05-31 19:35:15.000000000 +0000
+++ libgrive/test/drive/ResourceTest.cc
@@ -21,9 +21,9 @@
 
 #include "Assert.hh"
 
-#include "drive/Resource.hh"
+#include "base/Resource.hh"
 
-#include "drive/Entry.hh"
+#include "base/Entry.hh"
 #include "xml/Node.hh"
 
 #include <iostream>

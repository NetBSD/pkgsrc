$NetBSD: patch-libgrive_test_drive_EntryTest.cc,v 1.1.1.1 2015/06/16 16:15:37 abs Exp $

Fix include

--- libgrive/test/drive/EntryTest.cc.orig	2015-05-31 19:35:15.000000000 +0000
+++ libgrive/test/drive/EntryTest.cc
@@ -21,7 +21,7 @@
 
 #include "Assert.hh"
 
-#include "drive/Entry.hh"
+#include "base/Entry.hh"
 #include "xml/Node.hh"
 #include "xml/NodeSet.hh"
 #include "xml/TreeBuilder.hh"

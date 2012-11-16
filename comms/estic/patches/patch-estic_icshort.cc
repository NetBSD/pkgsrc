$NetBSD: patch-estic_icshort.cc,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- estic/icshort.cc.orig	2012-11-15 10:44:05.000000000 +0000
+++ estic/icshort.cc
@@ -578,17 +578,17 @@ void ShortNumberListBox::Print (int Inde
 
 
 // Item numbers for the short number edit menu
-const miNumber      =  10;
-const miUsage       =  20;
-const miSignaling   =  30;
-const miDevice1     = 110;
-const miDevice2     = 120;
-const miDevice3     = 130;
-const miDevice4     = 140;
-const miDevice5     = 150;
-const miDevice6     = 160;
-const miDevice7     = 170;
-const miDevice8     = 180;
+const int miNumber      =  10;
+const int miUsage       =  20;
+const int miSignaling   =  30;
+const int miDevice1     = 110;
+const int miDevice2     = 120;
+const int miDevice3     = 130;
+const int miDevice4     = 140;
+const int miDevice5     = 150;
+const int miDevice6     = 160;
+const int miDevice7     = 170;
+const int miDevice8     = 180;
 
 
 

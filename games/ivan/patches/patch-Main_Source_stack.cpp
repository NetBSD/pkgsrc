$NetBSD: patch-Main_Source_stack.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/stack.cpp.orig	2004-12-10 15:51:48.000000000 +0000
+++ Main/Source/stack.cpp
@@ -1170,7 +1170,7 @@ void stack::SpillFluid(character* Spille
   if(!Items)
     return;
 
-  double ChanceMultiplier = 1. / (300 + sqrt(Volume));
+  double ChanceMultiplier = 1. / (300 + sqrt((double)Volume));
   itemvector ItemVector;
   FillItemVector(ItemVector);
 
@@ -1178,7 +1178,7 @@ void stack::SpillFluid(character* Spille
     if(ItemVector[c]->Exists() && ItemVector[c]->AllowFluids())
     {
       long ItemVolume = ItemVector[c]->GetVolume();
-      double Root = sqrt(ItemVolume);
+      double Root = sqrt((double)ItemVolume);
 
       if(Root > RAND() % 200 || Root > RAND() % 200)
       {

$NetBSD: patch-Main_Source_human.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous sqrt on SunOS
--- Main/Source/human.cpp.orig	2004-12-10 21:10:04.000000000 +0000
+++ Main/Source/human.cpp
@@ -2701,7 +2701,7 @@ void smith::BeTalkedTo()
 
 void humanoid::CalculateDodgeValue()
 {
-  DodgeValue = 0.05 * GetMoveEase() * GetAttribute(AGILITY) / sqrt(GetSize());
+  DodgeValue = 0.05 * GetMoveEase() * GetAttribute(AGILITY) / sqrt((double)GetSize());
 
   if(IsFlying())
     DodgeValue *= 2;

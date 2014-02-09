$NetBSD: patch-Main_Source_char.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/char.cpp.orig	2004-12-10 21:10:02.000000000 +0000
+++ Main/Source/char.cpp
@@ -2169,7 +2169,7 @@ void character::Vomit(v2 Pos, int Amount
   }
 
   if(!game::IsInWilderness())
-    GetNearLSquare(Pos)->ReceiveVomit(this, liquid::Spawn(GetVomitMaterial(), long(sqrt(GetBodyVolume()) * Amount / 1000)));
+    GetNearLSquare(Pos)->ReceiveVomit(this, liquid::Spawn(GetVomitMaterial(), long(sqrt((double)GetBodyVolume()) * Amount / 1000)));
 }
 
 truth character::Polymorph(character* NewForm, int Counter)
@@ -4261,7 +4261,7 @@ void character::DrawPanel(truth Animatio
 
 void character::CalculateDodgeValue()
 {
-  DodgeValue = 0.05 * GetMoveEase() * GetAttribute(AGILITY) / sqrt(GetSize());
+  DodgeValue = 0.05 * GetMoveEase() * GetAttribute(AGILITY) / sqrt((double)GetSize());
 
   if(IsFlying())
     DodgeValue *= 2;
@@ -7396,7 +7396,7 @@ void character::SpillFluid(character* Sp
   for(c = 0; c < BodyParts; ++c)
     if(GetBodyPart(c))
     {
-      Modifier[c] = long(sqrt(GetBodyPart(c)->GetVolume()));
+      Modifier[c] = long(sqrt((double)GetBodyPart(c)->GetVolume()));
 
       if(Modifier[c])
 	Modifier[c] *= 1 + (RAND() & 3);
@@ -7706,7 +7706,7 @@ void characterdatabase::PostProcess()
 
 void character::EditDealExperience(long Price)
 {
-  EditExperience(CHARISMA, sqrt(Price) / 5, 1 << 9);
+  EditExperience(CHARISMA, sqrt((double)Price) / 5, 1 << 9);
 }
 
 void character::PrintBeginLeprosyMessage() const
@@ -7951,7 +7951,7 @@ void character::RegenerateStamina()
 
     if(Sweats() && TorsoIsAlive() && !RAND_N(30) && !game::IsInWilderness())
     {
-      long Volume = long(.05 * sqrt(GetBodyVolume()));
+      long Volume = long(.05 * sqrt((double)GetBodyVolume()));
 
       if(GetTirednessState() == FAINTING)
 	Volume <<= 1;

$NetBSD: patch-Main_Source_bodypart.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/bodypart.cpp.orig	2004-12-10 15:51:44.000000000 +0000
+++ Main/Source/bodypart.cpp
@@ -585,7 +585,7 @@ int corpse::GetOfferValue(int Receiver)
 
 double corpse::GetWeaponStrength() const
 {
-  return GetFormModifier() * GetDeceased()->GetTorso()->GetMainMaterial()->GetStrengthValue() * sqrt(GetDeceased()->GetTorso()->GetMainMaterial()->GetWeight());
+  return GetFormModifier() * GetDeceased()->GetTorso()->GetMainMaterial()->GetStrengthValue() * sqrt((double)GetDeceased()->GetTorso()->GetMainMaterial()->GetWeight());
 }
 
 truth corpse::CanBeEatenByAI(const character* Eater) const
@@ -1742,7 +1742,7 @@ void bodypart::Be()
 void bodypart::SpillBlood(int HowMuch, v2 Pos)
 {
   if(HowMuch && (!Master || Master->SpillsBlood()) && (IsAlive() || MainMaterial->IsLiquid()) && !game::IsInWilderness())
-    GetNearLSquare(Pos)->SpillFluid(0, CreateBlood(long(HowMuch * sqrt(BodyPartVolume) / 2)), false, false);
+    GetNearLSquare(Pos)->SpillFluid(0, CreateBlood(long(HowMuch * sqrt((double)BodyPartVolume) / 2)), false, false);
 }
 
 void bodypart::SpillBlood(int HowMuch)
@@ -1750,7 +1750,7 @@ void bodypart::SpillBlood(int HowMuch)
   if(HowMuch && (!Master || Master->SpillsBlood()) && (IsAlive() || MainMaterial->IsLiquid()) && !game::IsInWilderness())
     for(int c = 0; c < GetSquaresUnder(); ++c)
       if(GetLSquareUnder(c))
-	GetLSquareUnder(c)->SpillFluid(0, CreateBlood(long(HowMuch * sqrt(BodyPartVolume) / 2)), false, false);
+	GetLSquareUnder(c)->SpillFluid(0, CreateBlood(long(HowMuch * sqrt((double)BodyPartVolume) / 2)), false, false);
 }
 
 void bodypart::SignalEnchantmentChange()

$NetBSD: patch-Main_Source_item.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/item.cpp.orig	2004-12-10 15:51:46.000000000 +0000
+++ Main/Source/item.cpp
@@ -88,7 +88,7 @@ item::~item()
 
 void item::Fly(character* Thrower, int Direction, int Force)
 {
-  int Range = Force * 25 / Max(long(sqrt(GetWeight())), 1L);
+  int Range = Force * 25 / Max(long(sqrt((double)GetWeight())), 1L);
 
   lsquare* LSquareUnder = GetLSquareUnder();
   RemoveFromSlot();
@@ -137,7 +137,7 @@ void item::Fly(character* Thrower, int D
     if(!JustHit->IsFlyable())
     {
       Breaks = true;
-      JustHit->GetOLTerrain()->HasBeenHitByItem(Thrower, this, int(BaseDamage * sqrt(RangeLeft)));
+      JustHit->GetOLTerrain()->HasBeenHitByItem(Thrower, this, int(BaseDamage * sqrt((double)RangeLeft)));
       break;
     }
     else
@@ -153,7 +153,7 @@ void item::Fly(character* Thrower, int D
 
       if(JustHit->GetCharacter())
       {
-	int Damage = int(BaseDamage * sqrt(RangeLeft));
+	int Damage = int(BaseDamage * sqrt((double)RangeLeft));
 	double ToHitValue = BaseToHitValue * RangeLeft;
 	int Returned = HitCharacter(Thrower, JustHit->GetCharacter(), Damage, ToHitValue, Direction);
 
@@ -170,7 +170,7 @@ void item::Fly(character* Thrower, int D
   }
 
   if(Breaks)
-    ReceiveDamage(Thrower, int(sqrt(GetWeight() * RangeLeft) / 10), THROW|PHYSICAL_DAMAGE, Direction);
+    ReceiveDamage(Thrower, int(sqrt((double) (GetWeight() * RangeLeft)) / 10), THROW|PHYSICAL_DAMAGE, Direction);
 
   if(Exists() && GetLSquareUnder()->GetRoom())
     GetLSquareUnder()->GetRoom()->AddItemEffect(this);
@@ -200,7 +200,7 @@ int item::HitCharacter(character* Throwe
 
 double item::GetWeaponStrength() const
 {
-  return GetFormModifier() * GetMainMaterial()->GetStrengthValue() * sqrt(GetMainMaterial()->GetWeight());
+  return GetFormModifier() * GetMainMaterial()->GetStrengthValue() * sqrt((double)GetMainMaterial()->GetWeight());
 }
 
 int item::GetStrengthRequirement() const
@@ -786,7 +786,7 @@ int item::GetOfferValue(int Receiver) co
 {
   /* Temporary */
 
-  int OfferValue = int(sqrt(GetTruePrice()));
+  int OfferValue = int(sqrt((double)GetTruePrice()));
 
   if(Receiver == GetAttachedGod())
     OfferValue <<= 1;
@@ -1489,7 +1489,7 @@ long item::GetFixPrice() const
   Clone->RemoveRust();
   long FixPrice = Clone->GetTruePrice();
   Clone->SendToHell();
-  return Max(long(3.5 * sqrt(FixPrice)), 10L);
+  return Max(long(3.5 * sqrt((double)FixPrice)), 10L);
 }
 
 void item::AddTrapName(festring& String, int Amount) const

$NetBSD: patch-Main_Source_gear.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/gear.cpp.orig	2004-12-10 15:51:45.000000000 +0000
+++ Main/Source/gear.cpp
@@ -159,7 +159,7 @@ long meleeweapon::GetPrice() const
   WeaponStrengthModifier *= WeaponStrengthModifier;
   WeaponStrengthModifier *= GetMainMaterial()->GetWeight();
   WeaponStrengthModifier *= Max((10 + Enchantment) * 0.1, 0.1);
-  return long(WeaponStrengthModifier / (20000000.0 * sqrt(GetWeight())))
+  return long(WeaponStrengthModifier / (20000000.0 * sqrt((double)GetWeight())))
     + GetEnchantedPrice(Enchantment);
 }
 
@@ -492,7 +492,7 @@ truth thunderhammer::ReceiveDamage(chara
 long armor::GetPrice() const
 {
   double StrengthValue = GetStrengthValue();
-  return long(StrengthValue * StrengthValue * StrengthValue * 20 / sqrt(GetWeight()));
+  return long(StrengthValue * StrengthValue * StrengthValue * 20 / sqrt((double)GetWeight()));
 }
 
 int belt::GetFormModifier() const
@@ -543,7 +543,7 @@ truth armor::CanBePiledWith(const item*
 long shield::GetPrice() const /* temporary... */
 {
   double StrengthValue = GetStrengthValue();
-  return long(sqrt(GetBaseBlockValue()) * StrengthValue * StrengthValue) + item::GetPrice();
+  return long(sqrt((double)GetBaseBlockValue()) * StrengthValue * StrengthValue) + item::GetPrice();
 }
 
 void armor::Save(outputfile& SaveFile) const

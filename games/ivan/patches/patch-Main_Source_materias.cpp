$NetBSD: patch-Main_Source_materias.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/materias.cpp.orig	2004-10-26 19:37:03.000000000 +0000
+++ Main/Source/materias.cpp
@@ -117,7 +117,7 @@ material* organic::EatEffect(character*
 
   if(GetSpoilLevel() > 0)
   {
-    Eater->BeginTemporaryState(CONFUSED, int(Amount * GetSpoilLevel() * sqrt(GetNutritionValue()) / 1000));
+    Eater->BeginTemporaryState(CONFUSED, int(Amount * GetSpoilLevel() * sqrt((double)GetNutritionValue()) / 1000));
 
     if(GetBodyFlags() & CAN_HAVE_PARASITE
        && !(RAND() % (250 / GetSpoilLevel())))
@@ -125,7 +125,7 @@ material* organic::EatEffect(character*
   }
 
   if(GetSpoilLevel() > 4)
-    Eater->BeginTemporaryState(POISONED, int(Amount * (GetSpoilLevel() - 4) * sqrt(GetNutritionValue()) / 1000));
+    Eater->BeginTemporaryState(POISONED, int(Amount * (GetSpoilLevel() - 4) * sqrt((double)GetNutritionValue()) / 1000));
 
   if(Volume != Amount)
   {
@@ -281,7 +281,7 @@ truth ironalloy::TryToRust(long Modifier
     if(!Volume)
       Volume = GetVolume();
 
-    long Chance = long(30000000. * sqrt(Volume) / (Modifier * GetRustModifier()));
+    long Chance = long(30000000. * sqrt((double)Volume) / (Modifier * GetRustModifier()));
 
     if(Chance <= 1 || !(RAND() % Chance))
       return true;

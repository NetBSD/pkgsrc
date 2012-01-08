$NetBSD: patch-src_item.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Fix build on 64-bit with gcc-4.5.

--- src/item.cpp.orig	2005-10-03 05:57:31.000000000 +0000
+++ src/item.cpp
@@ -135,13 +135,13 @@ static const ItemLocation items[] = {
 #define N_ITEMS (sizeof(items) / sizeof(items[0]))
 
 bool isRuneInInventory(void *virt) {
-    return c->saveGame->runes & (int)virt;
+    return c->saveGame->runes & (int64_t)virt;
 }
 
 void putRuneInInventory(void *virt) {
     c->party->member(0)->awardXp(100);    
     c->party->adjustKarma(KA_FOUND_ITEM);
-    c->saveGame->runes |= (int)virt;
+    c->saveGame->runes |= (int64_t)virt;
     c->saveGame->lastreagent = c->saveGame->moves & 0xF0;
 }
 
@@ -150,18 +150,18 @@ bool isStoneInInventory(void *virt) {
     if (virt == NULL) 
         return (c->saveGame->stones > 0);
     /* specific test: does the party have a specific stone? */
-    else return c->saveGame->stones & (int)virt;
+    else return c->saveGame->stones & (int64_t)virt;
 }
 
 void putStoneInInventory(void *virt) {
     c->party->member(0)->awardXp(200);
     c->party->adjustKarma(KA_FOUND_ITEM);
-    c->saveGame->stones |= (int)virt;
+    c->saveGame->stones |= (int64_t)virt;
     c->saveGame->lastreagent = c->saveGame->moves & 0xF0;
 }
 
 bool isItemInInventory(void *item) {
-    return c->saveGame->items & (int)item;
+    return c->saveGame->items & (int64_t)item;
 }
 
 bool isSkullInInventory(void *) {
@@ -171,7 +171,7 @@ bool isSkullInInventory(void *) {
 void putItemInInventory(void *item) {
     c->party->member(0)->awardXp(400);
     c->party->adjustKarma(KA_FOUND_ITEM);
-    c->saveGame->items |= (int)item;
+    c->saveGame->items |= (int64_t)item;
     c->saveGame->lastreagent = c->saveGame->moves & 0xF0;
 }
 
@@ -183,17 +183,17 @@ void useBBC(void *item) {
     /* on top of the Abyss entrance */
     if (c->location->coords == abyssEntrance) {
         /* must use bell first */
-        if ((int)item == ITEM_BELL) {
+        if ((int64_t)item == ITEM_BELL) {
             screenMessage("\nThe Bell rings on and on!\n");
             c->saveGame->items |= ITEM_BELL_USED;
         }
         /* then the book */
-        else if (((int)item == ITEM_BOOK) && (c->saveGame->items & ITEM_BELL_USED)) {
+        else if (((int64_t)item == ITEM_BOOK) && (c->saveGame->items & ITEM_BELL_USED)) {
             screenMessage("\nThe words resonate with the ringing!\n");
             c->saveGame->items |= ITEM_BOOK_USED;
         }
         /* then the candle */
-        else if (((int)item == ITEM_CANDLE) && (c->saveGame->items & ITEM_BOOK_USED)) {
+        else if (((int64_t)item == ITEM_CANDLE) && (c->saveGame->items & ITEM_BOOK_USED)) {
             screenMessage("\nAs you light the Candle the Earth Trembles!\n");    
             c->saveGame->items |= ITEM_CANDLE_USED;
         }
@@ -255,7 +255,7 @@ void useSkull(void *item) {
  */
 void useStone(void *item) {
     MapCoords coords;
-    unsigned char stone = (unsigned char)((int)item);
+    unsigned char stone = (unsigned char)((int64_t)item);
     
     unsigned char truth   = STONE_WHITE | STONE_PURPLE | STONE_GREEN  | STONE_BLUE;
     unsigned char love    = STONE_WHITE | STONE_YELLOW | STONE_GREEN  | STONE_ORANGE;
@@ -393,9 +393,9 @@ bool isMysticInInventory(void *mystic) {
        This would be a good candidate for an xu4 "extended" savegame
        format.
     */
-    if (((int)mystic) == WEAP_MYSTICSWORD)
+    if (((int64_t)mystic) == WEAP_MYSTICSWORD)
         return c->saveGame->weapons[WEAP_MYSTICSWORD] > 0;
-    else if (((int)mystic) == ARMR_MYSTICROBES)
+    else if (((int64_t)mystic) == ARMR_MYSTICROBES)
         return c->saveGame->armor[ARMR_MYSTICROBES] > 0;
     else
         ASSERT(0, "Invalid mystic item was tested in isMysticInInventory()");    
@@ -405,9 +405,9 @@ bool isMysticInInventory(void *mystic) {
 void putMysticInInventory(void *mystic) {
     c->party->member(0)->awardXp(400);
     c->party->adjustKarma(KA_FOUND_ITEM);
-    if (((int)mystic) == WEAP_MYSTICSWORD)
+    if (((int64_t)mystic) == WEAP_MYSTICSWORD)
         c->saveGame->weapons[WEAP_MYSTICSWORD] += 8;
-    else if (((int)mystic) == ARMR_MYSTICROBES)
+    else if (((int64_t)mystic) == ARMR_MYSTICROBES)
         c->saveGame->armor[ARMR_MYSTICROBES] += 8;
     else
         ASSERT(0, "Invalid mystic item was added in putMysticInInventory()");        
@@ -415,12 +415,12 @@ void putMysticInInventory(void *mystic) 
 }
 
 bool isWeaponInInventory(void *weapon) {
-    if (c->saveGame->weapons[(int)weapon])
+    if (c->saveGame->weapons[(int64_t)weapon])
         return true;
     else {
         int i;
         for (i = 0; i < c->party->size(); i++) {
-            if (c->party->member(i)->getWeapon() == (int)weapon)
+            if (c->party->member(i)->getWeapon() == (int64_t)weapon)
                 return true;
         }
     }
@@ -428,7 +428,7 @@ bool isWeaponInInventory(void *weapon) {
 }
 
 void putWeaponInInventory(void *weapon) {
-    c->saveGame->weapons[(int)weapon]++;
+    c->saveGame->weapons[(int64_t)weapon]++;
 }
 
 void useTelescope(void *notused) {
@@ -447,11 +447,11 @@ bool isReagentInInventory(void *reag) {
 
 void putReagentInInventory(void *reag) {
     c->party->adjustKarma(KA_FOUND_ITEM);
-    c->saveGame->reagents[(int)reag] += xu4_random(8) + 2;
+    c->saveGame->reagents[(int64_t)reag] += xu4_random(8) + 2;
     c->saveGame->lastreagent = c->saveGame->moves & 0xF0;
 
-    if (c->saveGame->reagents[(int)reag] > 99) {
-        c->saveGame->reagents[(int)reag] = 99;
+    if (c->saveGame->reagents[(int64_t)reag] > 99) {
+        c->saveGame->reagents[(int64_t)reag] = 99;
         screenMessage("Dropped some!\n");
     }
 }

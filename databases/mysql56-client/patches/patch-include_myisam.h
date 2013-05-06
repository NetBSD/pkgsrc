$NetBSD: patch-include_myisam.h,v 1.2 2013/05/06 14:41:08 joerg Exp $

Adjust MI_MAX_KEY_LENGTH x4.

--- include/myisam.h.orig	2013-05-05 21:55:07.000000000 +0000
+++ include/myisam.h
@@ -80,8 +80,8 @@ extern "C" {
 
 #define mi_is_key_active(_keymap_,_keyno_) \
                             (((_keyno_) < MI_KEYMAP_BITS) ? \
-                             test((_keymap_) & (ULL(1) << (_keyno_))) : \
-                             test((_keymap_) & MI_KEYMAP_HIGH_MASK))
+                             my_test((_keymap_) & (ULL(1) << (_keyno_))) : \
+                             my_test((_keymap_) & MI_KEYMAP_HIGH_MASK))
 #define mi_set_key_active(_keymap_,_keyno_) \
                             (_keymap_)|= (((_keyno_) < MI_KEYMAP_BITS) ? \
                                           (ULL(1) << (_keyno_)) : \
@@ -94,7 +94,7 @@ extern "C" {
 #else
 
 #define mi_is_key_active(_keymap_,_keyno_) \
-                            test((_keymap_) & (ULL(1) << (_keyno_)))
+                            my_test((_keymap_) & (ULL(1) << (_keyno_)))
 #define mi_set_key_active(_keymap_,_keyno_) \
                             (_keymap_)|= (ULL(1) << (_keyno_))
 #define mi_clear_key_active(_keymap_,_keyno_) \
@@ -103,7 +103,7 @@ extern "C" {
 #endif
 
 #define mi_is_any_key_active(_keymap_) \
-                            test((_keymap_))
+                            my_test((_keymap_))
 #define mi_is_all_keys_active(_keymap_,_keys_) \
                             ((_keymap_) == mi_get_mask_all_keys_active(_keys_))
 #define mi_set_all_keys_active(_keymap_,_keys_) \

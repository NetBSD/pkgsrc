$NetBSD: patch-src_lib_fcitx-config_hotkey.c,v 1.1 2025/12/07 03:00:55 maya Exp $

Fix ctype abuse by casting to unsigned char

--- src/lib/fcitx-config/hotkey.c.orig	2025-12-06 22:31:02.707466261 +0000
+++ src/lib/fcitx-config/hotkey.c
@@ -675,7 +675,7 @@ char* FcitxHotkeyGetReadableKeyString(Fc
         if (i == 0) {
             continue;
         }
-        key[i] = tolower(key[i]);
+        key[i] = tolower((unsigned char) key[i]);
     }
     strcpy(str + len, key);
 

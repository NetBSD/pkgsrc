$NetBSD: patch-src_ui_kimpanel_kimpanel.c,v 1.1 2025/12/07 03:00:56 maya Exp $

Fix ctype abuse by casting to unsigned char

--- src/ui/kimpanel/kimpanel.c.orig	2025-12-06 22:36:52.753698558 +0000
+++ src/ui/kimpanel/kimpanel.c
@@ -232,8 +232,8 @@ static void SetIMMenu(FcitxIM *pim, char
                 strlen("fcitx-keyboard-")) != 0) {
         icon = pim->strIconName;
     } else if (isUnity()) {
-        layout[INDICATOR_KEYBOARD_LENGTH] = toupper(pim->langCode[0]);
-        layout[INDICATOR_KEYBOARD_LENGTH + 1] = tolower(pim->langCode[1]);
+        layout[INDICATOR_KEYBOARD_LENGTH] = toupper((unsigned char) pim->langCode[0]);
+        layout[INDICATOR_KEYBOARD_LENGTH + 1] = tolower((unsigned char) pim->langCode[1]);
         icon = layout;
     }
     boolean result = CheckAddPrefix(&icon);
@@ -262,9 +262,9 @@ static void SetIMIcon(FcitxInstance* ins
                         strlen("fcitx-keyboard-")) == 0) {
                 if (isUnity()) {
                     layout[INDICATOR_KEYBOARD_LENGTH] =
-                        toupper(im->langCode[0]);
+                        toupper((unsigned char) im->langCode[0]);
                     layout[INDICATOR_KEYBOARD_LENGTH + 1] =
-                        tolower(im->langCode[1]);
+                        tolower((unsigned char) im->langCode[1]);
                     icon = layout;
                 } else {
                     icon = "";

$NetBSD: patch-src_ui_classic_skin.c,v 1.1 2025/12/07 03:00:56 maya Exp $

Fix ctype abuse by casting to unsigned char

--- src/ui/classic/skin.c.orig	2025-12-06 22:35:36.759885141 +0000
+++ src/ui/classic/skin.c
@@ -768,7 +768,7 @@ SkinImage* GetIMIcon(FcitxClassicUI* cla
         if (*im->langCode) {
             strncpy(temp, im->langCode, LANGCODE_LENGTH);
             iconText = temp;
-            iconText[0] = toupper(iconText[0]);
+            iconText[0] = toupper((unsigned char) iconText[0]);
         } else {
             iconText = im->uniqueName + strlen("fcitx-keyboard-");
         }

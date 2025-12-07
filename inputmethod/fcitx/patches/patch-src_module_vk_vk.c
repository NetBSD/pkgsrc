$NetBSD: patch-src_module_vk_vk.c,v 1.1 2025/12/07 03:00:56 maya Exp $

Fix ctype abuse by casting to unsigned char

--- src/module/vk/vk.c.orig	2025-12-06 22:33:28.222526551 +0000
+++ src/module/vk/vk.c
@@ -600,7 +600,7 @@ void LoadVKMapFile(FcitxVKState *vkstate
                 continue;
 
             for (i = 0; i < VK_NUMBERS; i++) {
-                if (vkTable[i] == tolower(pstr[0])) {
+                if (vkTable[i] == tolower((unsigned char) pstr[0])) {
                     pstr += 2;
                     while (*pstr == ' ' || *pstr == '\t')
                         pstr++;

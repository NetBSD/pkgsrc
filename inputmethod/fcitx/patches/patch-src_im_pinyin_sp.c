$NetBSD: patch-src_im_pinyin_sp.c,v 1.1 2026/08/28 01:52:12 tsutsui Exp $

Fix ctype abuse by casting to unsigned char

--- src/im/pinyin/sp.c.orig	2026-08-28 01:41:25.905117302 +0000
+++ src/im/pinyin/sp.c
@@ -137,7 +137,7 @@ void LoadSPData(FcitxPinyinState *pystat
                 continue;
 
             if (pstr[0] == '=') //是零声母设置
-                pyconfig->cNonS = tolower(pstr[1]);
+                pyconfig->cNonS = tolower((unsigned char) pstr[1]);
             else {
                 i = 0;
 
@@ -150,12 +150,12 @@ void LoadSPData(FcitxPinyinState *pystat
                         i = GetSPIndexQP_S(pyconfig, strS);
 
                         if (i != -1)
-                            SPMap_S[i].cJP = tolower(pstr[1]);
+                            SPMap_S[i].cJP = tolower((unsigned char) pstr[1]);
                         else {
                             i = GetSPIndexQP_C(pyconfig, strS);
 
                             if (i != -1)
-                                SPMap_C[i].cJP = tolower(pstr[1]);
+                                SPMap_C[i].cJP = tolower((unsigned char) pstr[1]);
                         }
 
                         break;

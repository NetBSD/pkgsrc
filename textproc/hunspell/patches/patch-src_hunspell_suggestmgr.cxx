$NetBSD: patch-src_hunspell_suggestmgr.cxx,v 1.1 2020/08/03 11:19:28 wiz Exp $

Fix CVE-2019-16707
https://github.com/hunspell/hunspell/commit/ac938e2ecb48ab4dd21298126c7921689d60571b#diff-783289d6b6330291ec79bf507002106e

--- src/hunspell/suggestmgr.cxx.orig	2018-11-12 20:38:56.000000000 +0000
+++ src/hunspell/suggestmgr.cxx
@@ -2040,7 +2040,7 @@ int SuggestMgr::leftcommonsubstring(
   int l2 = su2.size();
   // decapitalize dictionary word
   if (complexprefixes) {
-    if (su1[l1 - 1] == su2[l2 - 1])
+    if (l1 && l2 && su1[l1 - 1] == su2[l2 - 1])
       return 1;
   } else {
     unsigned short idx = su2.empty() ? 0 : (su2[0].h << 8) + su2[0].l;

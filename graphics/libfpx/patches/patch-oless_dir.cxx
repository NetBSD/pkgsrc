$NetBSD: patch-oless_dir.cxx,v 1.1 2017/10/04 17:19:33 nros Exp $
possible fix for CVE-2017-12920
--- oless/dir.cxx.orig	2017-10-03 18:36:32.000000000 +0000
+++ oless/dir.cxx
@@ -1100,6 +1100,8 @@ SCODE CDirectory::GetDirEntry(
     DIRINDEX id = sid / _cdeEntries;
 
     msfChk(_dv.GetTable(id, dwFlags, &pds));
+    if (ppde == NULL)
+        msfErr(Err, ERROR_INVALID_ADDRESS);
 
     *ppde = pds->GetEntry((DIROFFSET)(sid % _cdeEntries));
 

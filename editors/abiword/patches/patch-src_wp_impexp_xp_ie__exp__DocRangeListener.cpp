$NetBSD: patch-src_wp_impexp_xp_ie__exp__DocRangeListener.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13834, SVN revision 35392: Crash fixes.

--- src/wp/impexp/xp/ie_exp_DocRangeListener.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/wp/impexp/xp/ie_exp_DocRangeListener.cpp
@@ -166,7 +166,7 @@ void  IE_Exp_DocRangeListener::freeAtts(
   UT_sint32 i=0;
   while(sAtts[i])
   {
-      delete [] (sAtts[i]);
+      g_free(const_cast<char*>(sAtts[i]));
       i++;
   }
   delete [] sAtts;

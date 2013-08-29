$NetBSD: patch-intl_strres_src_nsStringBundleTextOverride.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- intl/strres/src/nsStringBundleTextOverride.cpp.orig	2013-07-14 14:46:54.000000000 +0000
+++ intl/strres/src/nsStringBundleTextOverride.cpp
@@ -302,7 +302,7 @@ nsPropertyEnumeratorByURL::HasMoreElemen
     }
 
     if (!hasMore)
-        mCurrent = false;
+        mCurrent = NULL;
     
     *aResult = mCurrent ? true : false;
     

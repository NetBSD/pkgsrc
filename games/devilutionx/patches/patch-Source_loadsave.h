$NetBSD: patch-Source_loadsave.h,v 1.1 2019/07/28 10:26:43 nia Exp $

64bit Compatible Saves
https://patch-diff.githubusercontent.com/raw/diasurgical/devilutionX/pull/162.patch

--- Source/loadsave.h.orig	2019-05-19 17:06:45.000000000 +0000
+++ Source/loadsave.h
@@ -9,6 +9,11 @@ char BLoad();
 int WLoad();
 int ILoad();
 BOOL OLoad();
+void CopyItems(const int n, ItemStruct *pItem);
+void CopyItem(ItemStruct *pItem);
+void SaveItem(ItemStruct *pItem);
+void SaveItems(ItemStruct *pItem, const int n);
+
 void LoadPlayer(int i);
 void LoadMonster(int i);
 void LoadMissile(int i);

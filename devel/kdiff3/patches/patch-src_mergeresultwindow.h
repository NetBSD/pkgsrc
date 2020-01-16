$NetBSD: patch-src_mergeresultwindow.h,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

Fix intermittent crashes. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/8a700c10780b157e681637404e97718f5ba0cff2

Fix missing menu items. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/mergeresultwindow.h.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/mergeresultwindow.h
@@ -40,7 +40,16 @@ public:
       const Diff3LineList* pDiff3LineList,
       TotalDiffStatus* pTotalDiffStatus
       );
-   void initActions(KActionCollection* ac);
+
+   inline void clearMergeList()
+   {
+       m_mergeLineList.clear();
+       m_totalSize = 0;
+   }
+
+   static void initActions(KActionCollection* ac);
+
+   void connectActions();
    void reset();
 
    bool saveDocument( const QString& fileName, QTextCodec* pEncoding, e_LineEndStyle eLineEndStyle );
@@ -119,15 +128,15 @@ private:
    void merge(bool bAutoSolve, e_SrcSelector defaultSelector, bool bConflictsOnly=false, bool bWhiteSpaceOnly=false );
    QString getString( int lineIdx );
 
-   QAction* chooseAEverywhere = nullptr;
-   QAction* chooseBEverywhere = nullptr;
-   QAction* chooseCEverywhere = nullptr;
-   QAction* chooseAForUnsolvedConflicts = nullptr;
-   QAction* chooseBForUnsolvedConflicts = nullptr;
-   QAction* chooseCForUnsolvedConflicts = nullptr;
-   QAction* chooseAForUnsolvedWhiteSpaceConflicts = nullptr;
-   QAction* chooseBForUnsolvedWhiteSpaceConflicts = nullptr;
-   QAction* chooseCForUnsolvedWhiteSpaceConflicts = nullptr;
+   static QAction* chooseAEverywhere;
+   static QAction* chooseBEverywhere;
+   static QAction* chooseCEverywhere;
+   static QAction* chooseAForUnsolvedConflicts;
+   static QAction* chooseBForUnsolvedConflicts;
+   static QAction* chooseCForUnsolvedConflicts;
+   static QAction* chooseAForUnsolvedWhiteSpaceConflicts;
+   static QAction* chooseBForUnsolvedWhiteSpaceConflicts;
+   static QAction* chooseCForUnsolvedWhiteSpaceConflicts;
 
    Options* m_pOptions = nullptr;
 

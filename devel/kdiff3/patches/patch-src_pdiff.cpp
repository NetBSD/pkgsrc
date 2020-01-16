$NetBSD: patch-src_pdiff.cpp,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

Fix intermittent crashes. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/8a700c10780b157e681637404e97718f5ba0cff2

Fix missing menu items. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/pdiff.cpp.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/pdiff.cpp
@@ -142,6 +142,8 @@ void KDiff3App::mainInit(TotalDiffStatus
     // so painting must be suppressed
     if(bGUI) setLockPainting(true);
 
+    //ensure merge result window never has stale iterators.
+    if(m_pMergeResultWindow) m_pMergeResultWindow->clearMergeList();
     m_diff3LineList.clear();
     m_diff3LineVector.clear();
 
@@ -338,7 +340,7 @@ void KDiff3App::mainInit(TotalDiffStatus
         oldHeights = m_pMainSplitter->sizes();
 
     initView();
-    m_pMergeResultWindow->initActions(actionCollection());
+    m_pMergeResultWindow->connectActions();
 
     if(m_pDirectoryMergeSplitter->isVisible())
     {

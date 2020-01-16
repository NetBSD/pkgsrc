$NetBSD: patch-src_kdiff3.cpp,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

Fix missing menu items. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/kdiff3.cpp.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/kdiff3.cpp
@@ -312,6 +312,8 @@ KDiff3App::KDiff3App(QWidget* pParent, c
     ///////////////////////////////////////////////////////////////////
     // call inits to invoke all other construction parts
     initActions(actionCollection());
+    MergeResultWindow::initActions(actionCollection());
+
     initStatusBar();
 
     m_pFindDialog = new FindDialog(this);

$NetBSD: patch-src_kile_kileprojectview.h,v 1.1 2013/03/28 21:43:06 joerg Exp $

--- src/kile/kileprojectview.h.orig	2013-03-28 13:28:50.000000000 +0000
+++ src/kile/kileprojectview.h
@@ -25,7 +25,6 @@
 class KURL;
 class KPopupMenu;
 class KToggleAction;
-class KileDocument::Info;
 class KileInfo;
 
 namespace KileType {enum ProjectView { Project=0, ProjectItem, ProjectExtra, File, Folder};}

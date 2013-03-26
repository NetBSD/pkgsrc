$NetBSD: patch-vcs_cvsservice_cvspart.h,v 1.1 2013/03/26 23:30:44 joerg Exp $

--- vcs/cvsservice/cvspart.h.orig	2013-03-25 21:20:02.000000000 +0000
+++ vcs/cvsservice/cvspart.h
@@ -23,8 +23,6 @@ class Context;
 class QPopupMenu;
 class QDir;
 class KDialogBase;
-class KURL;
-class KURL::List;
 class KAction;
 
 class CvsProcessWidget;

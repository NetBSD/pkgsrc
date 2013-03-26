$NetBSD: patch-vcs_cvsservice_cvspartimpl.h,v 1.1 2013/03/26 23:30:44 joerg Exp $

--- vcs/cvsservice/cvspartimpl.h.orig	2013-03-25 21:17:47.000000000 +0000
+++ vcs/cvsservice/cvspartimpl.h
@@ -21,8 +21,6 @@
 
 class CvsServicePart;
 class KDialogBase;
-class KURL;
-class KURL::List;
 class CvsProcessWidget;
 class KDevMainWindow;
 class KDevCore;

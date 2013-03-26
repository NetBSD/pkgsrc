$NetBSD: patch-Src_DasherCore_View_DelayedDraw.h,v 1.1 2013/03/26 23:30:45 joerg Exp $

--- Src/DasherCore/View/DelayedDraw.h.orig	2013-03-26 19:23:47.000000000 +0000
+++ Src/DasherCore/View/DelayedDraw.h
@@ -15,7 +15,6 @@ namespace Dasher {
   class CDasherScreen;
 }
 
-class Dasher::CDasherScreen;
 
 namespace Dasher {
   /// \ingroup View

$NetBSD: patch-src_Maps_Projection.h,v 1.1 2013/02/26 11:15:19 joerg Exp $

--- src/Maps/Projection.h.orig	2013-02-25 22:35:30.000000000 +0000
+++ src/Maps/Projection.h
@@ -6,7 +6,7 @@
 
 #include <QPointF>
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 
 #include "Preferences/MerkaartorPreferences.h"
 

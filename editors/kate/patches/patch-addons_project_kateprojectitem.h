$NetBSD: patch-addons_project_kateprojectitem.h,v 1.1 2024/02/23 04:00:03 gutteridge Exp $

Fix non-PCH-enabled build by adding missing includes.

--- addons/project/kateprojectitem.h.orig	2023-12-04 03:09:43.000000000 +0000
+++ addons/project/kateprojectitem.h
@@ -7,6 +7,8 @@
 
 #pragma once
 
+#include <QtGlobal>
+
 #if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
 #include <KTextEditor/Document>
 #else

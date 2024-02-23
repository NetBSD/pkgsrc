$NetBSD: patch-addons_project_kateproject.h,v 1.2 2024/02/23 04:59:00 gutteridge Exp $

Fix non-PCH-enabled build by adding missing include.
https://invent.kde.org/utilities/kate/-/issues/116

--- addons/project/kateproject.h.orig	2023-12-04 03:09:43.000000000 +0000
+++ addons/project/kateproject.h
@@ -7,6 +7,8 @@
 
 #pragma once
 
+#include <QtGlobal>
+
 #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
 #include <KTextEditor/ModificationInterface>
 #endif

$NetBSD: patch-addons_project_git_gitstatus.h,v 1.2 2024/02/23 04:59:00 gutteridge Exp $

Fix non-PCH-enabled build by adding missing include.
https://invent.kde.org/utilities/kate/-/issues/116

--- addons/project/git/gitstatus.h.orig	2023-12-04 03:09:43.000000000 +0000
+++ addons/project/git/gitstatus.h
@@ -5,6 +5,7 @@
 */
 #pragma once
 
+#include <QSet>
 #include <QString>
 #include <QVector>
 

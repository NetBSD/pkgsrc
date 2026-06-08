$NetBSD: patch-src_levelset.h,v 1.1 2026/06/08 11:23:03 markd Exp $

Add missing include
https://github.com/KDE/katomic/commit/a087676d60118a4cd7684d1650a29a5abe4c5588

--- src/levelset.h.orig	2025-11-01 10:02:55.000000000 +0000
+++ src/levelset.h
@@ -13,8 +13,9 @@
 
 #include <KSharedConfig>
 
-#include <QString>
+#include <QHash>
 #include <QList>
+#include <QString>
 
 class Molecule;
 

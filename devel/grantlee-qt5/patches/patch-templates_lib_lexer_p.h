$NetBSD: patch-templates_lib_lexer_p.h,v 1.1 2019/08/27 06:26:19 markd Exp $

From: Michael Pyne <mpyne@kde.org>
Date: Tue, 18 Dec 2018 17:47:21 -0500
Subject: [PATCH] Fix build with Qt 5.13 / GCC 8.2.

At this point Grantlee doesn't build for me because QList is an
incomplete type. I think the compiler is right to complain, so I fix by
including the appropriate header.

--- templates/lib/lexer_p.h.orig	2019-08-25 11:37:32.228371777 +0000
+++ templates/lib/lexer_p.h
@@ -24,7 +24,7 @@
 #include "textprocessingmachine_p.h"
 #include "token.h"
 
-template <typename T> class QList;
+#include <QList>
 
 namespace Grantlee
 {

$NetBSD: patch-src_rosteravatarframe.cpp,v 1.1 2020/06/18 13:55:15 nia Exp $

Fix Qt 5.15 build issues

--- src/rosteravatarframe.cpp.orig	2018-11-02 00:15:39.000000000 +0000
+++ src/rosteravatarframe.cpp
@@ -22,6 +22,7 @@
 #include "psioptions.h"
 #include "iconset.h"
 #include "qpainter.h"
+#include "qpainterpath.h"
 
 
 RosterAvatarFrame::RosterAvatarFrame(QWidget *parent)

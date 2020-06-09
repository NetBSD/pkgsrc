$NetBSD: patch-plugins_Eq_EqSpectrumView.h,v 1.1 2020/06/09 16:03:00 nia Exp $

[PATCH] Fix Qt 5.15 build issues (#5498)

Add missing QPainterPath includes

https://github.com/LMMS/lmms/commit/29a5abc30b5d5efa30b7f6b73fe06d76ec851cca.patch

--- plugins/Eq/EqSpectrumView.h.orig	2018-11-03 01:43:42.000000000 +0000
+++ plugins/Eq/EqSpectrumView.h
@@ -24,6 +24,7 @@
 #define EQSPECTRUMVIEW_H
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QWidget>
 
 #include "fft_helpers.h"

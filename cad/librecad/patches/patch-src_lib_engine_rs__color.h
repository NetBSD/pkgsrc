$NetBSD: patch-src_lib_engine_rs__color.h,v 1.1 2013/05/04 12:59:45 joerg Exp $

--- src/lib/engine/rs_color.h.orig	2013-05-04 00:11:59.000000000 +0000
+++ src/lib/engine/rs_color.h
@@ -29,6 +29,7 @@
 #define RS_COLOR_H
 
 #include <QColor>
+#include <ostream>
 
 #include "rs_flags.h"
 

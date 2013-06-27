$NetBSD: patch-library_canvas_src_mdc__text.cpp,v 1.1 2013/06/27 15:48:42 joerg Exp $

--- library/canvas/src/mdc_text.cpp.orig	2013-06-27 14:44:19.000000000 +0000
+++ library/canvas/src/mdc_text.cpp
@@ -1,5 +1,6 @@
 #include "stdafx.h"
 
+#include <cstdlib>
 #include <cstring>
 #include "stdafx.h"
 

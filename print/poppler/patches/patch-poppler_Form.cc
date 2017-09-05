$NetBSD: patch-poppler_Form.cc,v 1.1 2017/09/05 09:39:41 tnn Exp $

needs <ctype.h> for isdigit(3).

--- poppler/Form.cc.orig	2017-08-15 22:16:09.000000000 +0000
+++ poppler/Form.cc
@@ -31,6 +31,7 @@
 #include <limits>
 #include <stddef.h>
 #include <string.h>
+#include <ctype.h>
 #include "goo/gmem.h"
 #include "goo/GooString.h"
 #include "Error.h"

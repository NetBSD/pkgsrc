$NetBSD: patch-cupshelper.cxx,v 1.1 2011/12/06 19:48:47 joerg Exp $

--- cupshelper.cxx.orig	2011-12-06 14:22:14.000000000 +0000
+++ cupshelper.cxx
@@ -34,6 +34,7 @@
 #include "cupshelper.h"
 #include "passworddialog.h"
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <cups/language.h>
 

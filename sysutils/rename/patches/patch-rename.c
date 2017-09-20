$NetBSD: patch-rename.c,v 1.2 2017/09/20 11:03:14 jperkin Exp $

Fix CPP.

--- rename.c.orig	2002-05-20 15:50:50.000000000 +0000
+++ rename.c
@@ -65,7 +65,7 @@
 
 #if HAVE_REGEX_H
   #include <regex.h>
-#elif
+#else
   #include "regex.h"
 #endif
 

$NetBSD: patch-interface_xaw_i.c,v 1.1 2025/10/12 08:46:59 mrg Exp $

Since this uses an IntrinsicP.h interface, include that.


--- interface/xaw_i.c.orig	2025-10-12 01:39:41.580310205 -0700
+++ interface/xaw_i.c	2025-10-12 01:39:50.376390214 -0700
@@ -56,7 +56,7 @@
 #include "strtab.h"
 #include "arc.h"
 
-#include <X11/Intrinsic.h>
+#include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
 #include <X11/Xatom.h>
 

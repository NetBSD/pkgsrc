$NetBSD: patch-gtk_src_Display.cpp,v 1.1 2014/12/06 19:04:14 dholland Exp $

Use standard headers.

--- gtk/src/Display.cpp~	2003-05-27 23:56:54.000000000 +0000
+++ gtk/src/Display.cpp
@@ -18,6 +18,8 @@
  * 02111-1307, USA.
  */
 
+#include <cstring>
+
 #include "Display.h"
 #include "Meaning.h"
 #include "DialogMediator.h"

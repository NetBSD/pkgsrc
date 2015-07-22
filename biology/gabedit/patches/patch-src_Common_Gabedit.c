$NetBSD: patch-src_Common_Gabedit.c,v 1.1.1.1 2015/07/22 19:05:10 asau Exp $

--- src/Common/Gabedit.c.orig	2013-10-30 12:46:50.000000000 +0000
+++ src/Common/Gabedit.c
@@ -26,6 +26,9 @@ DEALINGS IN THE SOFTWARE.
 #include <glib/gi18n.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if defined(__NetBSD__)
+#include <locale.h>
+#endif
 
 #include "Global.h"
 #include "MenuToolBar.h"

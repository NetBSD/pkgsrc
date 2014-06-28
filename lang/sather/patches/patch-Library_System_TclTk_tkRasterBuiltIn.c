$NetBSD: patch-Library_System_TclTk_tkRasterBuiltIn.c,v 1.1 2014/06/28 23:10:39 dholland Exp $

Use standard headers.

--- Library/System/TclTk/tkRasterBuiltIn.c~	2007-07-01 03:53:35.000000000 +0000
+++ Library/System/TclTk/tkRasterBuiltIn.c
@@ -11,6 +11,7 @@
 /* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA                     */
 /*------------>  Please email comments to <bug-sather@gnu.org>  <------------*/
 
+#include <stdlib.h>
 #include <tk.h>
 #include "tkRaster.h"
 #include "tkRasterBuiltIn.h"

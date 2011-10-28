$NetBSD: patch-src_geventloop.h,v 1.1 2011/10/28 17:34:07 schnoebe Exp $

# wrap the usage of ev.h in WITH_LIBEVENT (as should have been done.)
# pushed upstream as http://spectrum.im/issues/233

--- src/geventloop.h.orig	2011-06-11 13:17:44.000000000 +0000
+++ src/geventloop.h
@@ -24,7 +24,9 @@
 #include <glib.h>
 #include "purple.h"
 #include "eventloop.h"
-#include "ev.h"
+#ifdef WITH_LIBEVENT
+#  include "ev.h"
+#endif
 
 #define READ_COND  (G_IO_IN | G_IO_HUP | G_IO_ERR)
 #define WRITE_COND (G_IO_OUT | G_IO_HUP | G_IO_ERR | G_IO_NVAL)

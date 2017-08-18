$NetBSD: patch-src_cdpar.h,v 1.1 2017/08/18 12:21:29 triaxx Exp $

Add a test to include cdparanoia headers.

XXX: this patch could be useless if the cdparanoia package provided by pkgsrc
did not override the default include directory.

--- src/cdpar.h.orig	2016-12-30 19:56:07.000000000 +0000
+++ src/cdpar.h
@@ -26,7 +26,10 @@
 #ifdef HAVE_CDDA_INTERFACE_H
 #include <cdda_interface.h>
 #include <cdda_paranoia.h>
-#else
+#elif HAVE_CDDA_CDDA_INTERFACE_H
 #include <cdda/cdda_interface.h>
 #include <cdda/cdda_paranoia.h>
+#else
+#include <cdparanoia/cdda_interface.h>
+#include <cdparanoia/cdda_paranoia.h>
 #endif

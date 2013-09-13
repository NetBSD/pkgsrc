$NetBSD: patch-build_rpmfc.c,v 1.1 2013/09/13 12:41:32 ryoon Exp $

* basemname(3) requires libgen.h on NetBSD.

--- build/rpmfc.c.orig	2013-06-10 15:55:10.000000000 +0000
+++ build/rpmfc.c
@@ -16,6 +16,10 @@
 #include <rpm/rpmfi.h>
 #include <rpm/rpmstrpool.h>
 
+#if defined(__NetBSD__)
+#include <libgen.h>
+#endif
+
 #include "build/rpmbuild_internal.h"
 
 #include "debug.h"

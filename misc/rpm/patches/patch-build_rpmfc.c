$NetBSD: patch-build_rpmfc.c,v 1.2 2015/03/15 05:34:56 ryoon Exp $

* basemname(3) requires libgen.h on NetBSD.

--- build/rpmfc.c.orig	2014-08-26 09:49:39.000000000 +0000
+++ build/rpmfc.c
@@ -7,6 +7,10 @@
 #include <magic.h>
 #include <regex.h>
 
+#if defined(__NetBSD__)
+#include <libgen.h>
+#endif
+
 #include <rpm/header.h>
 #include <rpm/argv.h>
 #include <rpm/rpmfc.h>

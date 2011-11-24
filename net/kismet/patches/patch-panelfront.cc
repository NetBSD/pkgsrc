$NetBSD: patch-panelfront.cc,v 1.1 2011/11/24 13:43:11 joerg Exp $

--- panelfront.cc.orig	2011-11-24 01:48:35.000000000 +0000
+++ panelfront.cc
@@ -21,6 +21,7 @@
 #include <math.h>
 #include <sys/types.h>
 #include <dirent.h>
+#include <limits.h>
 
 #if defined(SYS_OPENBSD) && defined(HAVE_MACHINE_APMVAR_H)
 #include <machine/apmvar.h>

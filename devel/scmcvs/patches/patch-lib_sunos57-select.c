$NetBSD: patch-lib_sunos57-select.c,v 1.1 2026/11/20 19:46:23 nros Exp $

* On Illumos FD_ZERO expands to memset... but sys/select.h where
  FD_ZERO is defined does not include string.h where memset is declared.
  So include string.h to fix build on Illumos, include sys/select.h
  that has FD_* on illumos just in case its implicit inclusion change.

--- lib/sunos57-select.c.orig	2004-11-04 08:30:56.000000000 +0000
+++ lib/sunos57-select.c
@@ -40,6 +40,12 @@
 #include <sys/stat.h>
 #include <errno.h>
 
+#ifdef HAVE_STRING_H
+# include <string.h>
+#endif /* HAVE_STRING_H */
+#ifdef HAVE_SYS_SELECT_H
+# include <sys/select.h>
+#endif /* HAVE_SYS_SELECT_H */
 #ifdef HAVE_UNISTD_H
 # include <unistd.h>
 #endif /* HAVE_UNISTD_H */

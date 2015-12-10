$NetBSD: patch-libspectre_spectre-gs.c,v 1.1 2015/12/10 12:03:41 markd Exp $

gs 9.18 renamed error namespace, but provides no good way of testing the
version number so allow for both old and new names by testing the guard
define of the gserrors.h that appeared at the same point.

--- libspectre/spectre-gs.c.orig	2010-04-18 16:01:05.000000000 +0000
+++ libspectre/spectre-gs.c
@@ -29,6 +29,12 @@
 #include <ghostscript/iapi.h>
 #include <ghostscript/ierrors.h>
 
+#ifdef gserrors_INCLUDED
+# define e_Fatal gs_error_Fatal
+# define e_ExecStackUnderflow gs_error_ExecStackUnderflow
+# define e_NeedInput gs_error_NeedInput
+#endif
+
 #define BUFFER_SIZE 32768
 
 struct SpectreGS {

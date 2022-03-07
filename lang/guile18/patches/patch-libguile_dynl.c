$NetBSD: patch-libguile_dynl.c,v 1.1 2022/03/07 20:34:16 wiz Exp $

Add search path for bundled modules.

--- libguile/dynl.c.orig	2010-12-13 17:24:39.000000000 +0000
+++ libguile/dynl.c
@@ -56,6 +56,7 @@ maybe_drag_in_eprintf ()
 #include "libguile/lang.h"
 #include "libguile/validate.h"
 #include "libguile/dynwind.h"
+#include "libguile/libpath.h"
 
 #include <ltdl.h>
 
@@ -73,6 +74,7 @@ maybe_drag_in_eprintf ()
 static void *
 sysdep_dynl_link (const char *fname, const char *subr)
 {
+  lt_dladdsearchdir(SCM_LIB_DIR);
   lt_dlhandle handle;
   handle = lt_dlopenext (fname);
   if (NULL == handle)

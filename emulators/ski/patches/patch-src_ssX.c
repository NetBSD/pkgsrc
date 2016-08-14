$NetBSD: patch-src_ssX.c,v 1.1 2016/08/14 18:27:05 scole Exp $

Find default X resource file.

--- src/ssX.c.orig	2008-02-04 23:11:37.000000000 -0500
+++ src/ssX.c		2016-04-28 09:45:23.000000000 -0400
@@ -49,6 +49,7 @@
 #include "coreui.h"
 #include "ssDCmd.h"
 #include "libcore.h"
+#include "line_separator.h"
 
 #if 0
 /* Include files not needed for now in the simulator */
@@ -174,6 +175,24 @@
     Arg args[10];
     unsigned i, n;
     int argc = 0;
+    const char* xenv = "XENVIRONMENT";
+    const char* genv = getenv(xenv);
+    const char* xski_rc = "XSKI_RESOURCE_FILE";
+    
+    /*
+     * XXX how to add pkgsrc paths to X app-default search path?  For
+     * simplicity, just set environment variable or give warning if
+     * already set.  If XSki app-defaults not found, xski will display
+     * jumbled gui but doesn't look like it can run.
+     */
+    if (genv && (strcmp(genv, xski_rc) != 0)) {
+	printf("WARNING: If GUI not displayed correctly, try setting "
+	       "environment variable \"%s\" to \"%s\"%s",
+	       xenv, xski_rc, LINE_SEPARATOR);
+    }
+    else {
+	setenv(xenv, xski_rc, 0);
+    }
 
     addRegwRsrcOpts();
     addDatwRsrcOpts();

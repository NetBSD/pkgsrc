$NetBSD: patch-etc_papd_print_cups.c,v 1.1 2017/04/13 14:35:53 hauke Exp $

Post-1.6 CUPS has deprecated various function calls, and turned
central data structures opaque, only to be accessed by accessor
functions.  Since the project offers little help in migrating existing
source, we follow everybody else in flicking the magic switches to
re-enable the olde ways.
    
--- etc/papd/print_cups.c.orig	2013-07-23 09:10:55.000000000 +0000
+++ etc/papd/print_cups.c
@@ -39,7 +39,14 @@
 
 #ifdef HAVE_CUPS
 
+/* enable pre-1.6 CUPS API for now */
+#define _PPD_DEPRECATED
+/* expose structs that are private post-1.5 CUPS */
+#define _IPP_PRIVATE_STRUCTURES 1
+
+#include <cups/ipp.h>
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/language.h>
 #include <atalk/unicode.h>
 #include <atalk/logger.h>

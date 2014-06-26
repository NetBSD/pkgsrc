$NetBSD: patch-lib_mktime.c,v 1.1 2014/06/26 22:46:57 asau Exp $

This code is broken and uncompilable on 32-bit NetBSD.
The problem is the same as reported here:
   http://sourceware.org/bugzilla/show_bug.cgi?id=12401

The path of least resistance is just to skip the entire file on
NetBSD, as there is a perfectly good mktime() in libc.

--- lib/mktime.c.orig	2005-09-19 16:16:56.000000000 +0000
+++ lib/mktime.c
@@ -21,6 +21,8 @@
    mktime.  */
 /* #define DEBUG 1 */
 
+#ifndef __NetBSD__
+
 #ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif
@@ -656,6 +658,7 @@ main (int argc, char **argv)
 }
 
 #endif /* DEBUG */
+#endif /* __NetBSD__ */
 
 /*
 Local Variables:

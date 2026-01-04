$NetBSD: patch-dict-web1913-1.4_libmaa_obstack.c,v 1.1 2026/01/04 14:08:24 wiz Exp $

Add missing header.

--- dict-web1913-1.4/libmaa/obstack.c.orig	1998-02-22 19:32:33.000000000 +0000
+++ dict-web1913-1.4/libmaa/obstack.c
@@ -23,6 +23,7 @@ Cambridge, MA 02139, USA.  */
 
 /* This is just to get __GNU_LIBRARY__ defined.  */
 #include <stdio.h>
+#include <stdlib.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C

$NetBSD: patch-misc_fnmatch.c,v 1.1 2013/09/15 12:32:22 joerg Exp $

--- misc/fnmatch.c.orig	2013-09-14 20:58:02.000000000 +0000
+++ misc/fnmatch.c
@@ -17,6 +17,7 @@
    Boston, MA 02111-1307, USA.  */
 
 # include "system.h"
+#include <ctype.h>
 # include <stdlib.h>
 
 /* Find the first occurrence of C in S or the final NUL byte.  */

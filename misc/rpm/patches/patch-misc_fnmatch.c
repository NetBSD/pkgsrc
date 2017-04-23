$NetBSD: patch-misc_fnmatch.c,v 1.3 2017/04/23 08:18:15 adam Exp $

Add missing include.

--- misc/fnmatch.c.orig	2014-06-30 08:47:14.000000000 +0000
+++ misc/fnmatch.c
@@ -17,6 +17,7 @@
    Boston, MA 02111-1307, USA.  */
 
 # include "system.h"
+# include <ctype.h>
 # include <stdlib.h>
 
 /* Find the first occurrence of C in S or the final NUL byte.  */

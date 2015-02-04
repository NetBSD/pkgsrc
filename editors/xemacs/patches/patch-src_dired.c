$NetBSD: patch-src_dired.c,v 1.1 2015/02/04 09:19:20 hauke Exp $

--- src/dired.c.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/dired.c
@@ -21,6 +21,7 @@ Boston, MA 02111-1307, USA.  */
 /* Synched up with: FSF 19.30. */
 
 #include <config.h>
+#include <limits.h>
 #include "lisp.h"
 
 #include "sysfile.h"
@@ -97,7 +98,11 @@ If FILES-ONLY is the symbol t, then only
   directory = Ffile_name_as_directory (directory);
   directorylen = XSTRING_LENGTH (directory);
 
+#ifdef NAME_MAX
+  statbuf = (char *)alloca (directorylen + NAME_MAX + 1);
+#else
   statbuf = (char *)alloca (directorylen + MAXNAMLEN + 1);
+#endif
   memcpy (statbuf, XSTRING_DATA (directory), directorylen);
   statbuf_tail = statbuf + directorylen;
 

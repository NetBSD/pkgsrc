$NetBSD: patch-src_dired.c,v 1.1 2017/11/15 14:58:53 hauke Exp $

Prefer NAME_MAX over MAXNAMLEN, if available

Was patch-ak

--- src/dired.c.orig	2013-08-21 17:43:45.000000000 +0000
+++ src/dired.c
@@ -20,6 +20,7 @@ along with XEmacs.  If not, see <http://
 /* Synched up with: FSF 19.30. */
 
 #include <config.h>
+#include <limits.h>
 #include "lisp.h"
 
 #include "buffer.h"
@@ -103,7 +104,11 @@ If FILES-ONLY is the symbol t, then only
   directory = Ffile_name_as_directory (directory);
   directorylen = XSTRING_LENGTH (directory);
 
+#ifdef NAME_MAX
+  statbuf = alloca_ibytes (directorylen + NAME_MAX + 1);
+#else
   statbuf = alloca_ibytes (directorylen + MAXNAMLEN + 1);
+#endif
   memcpy (statbuf, XSTRING_DATA (directory), directorylen);
   statbuf_tail = statbuf + directorylen;
 

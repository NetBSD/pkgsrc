$NetBSD: patch-src_util.c,v 1.1 2016/04/09 10:09:14 richard Exp $

config.h should always be first

--- src/util.c.orig	2015-10-07 07:43:18.000000000 +0000
+++ src/util.c
@@ -22,6 +22,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#include "config.h"
 /* MSVC does not have these */
 #ifndef _MSC_VER
 #include <sys/time.h>
@@ -34,7 +35,6 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <string.h>
-#include "config.h"
 #include "libmtp.h"
 #include "util.h"
 

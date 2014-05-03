$NetBSD: patch-unix_unxcfg.h,v 1.2 2014/05/03 11:24:19 ryoon Exp $

* Fix build on Debian GNU/kFreeBSD.
* Fix build under OpenBSD 5.5
  Patch from OpenBSD Ports
  "timeb was already well deprecated on 4.4BSD"

--- unix/unxcfg.h.orig	2009-04-16 18:36:12.000000000 +0000
+++ unix/unxcfg.h
@@ -52,6 +52,7 @@
 
 #include <sys/types.h>          /* off_t, time_t, dev_t, ... */
 #include <sys/stat.h>
+#include <unistd.h>
 
 #ifdef NO_OFF_T
   typedef long zoff_t;
@@ -111,7 +112,9 @@ typedef struct stat z_stat;
 
 #ifdef BSD
 #  include <sys/time.h>
-#  include <sys/timeb.h>
+#  ifndef BSD4_4
+#    include <sys/timeb.h>
+#  endif
 #  if (defined(_AIX) || defined(__GLIBC__) || defined(__GNU__))
 #    include <time.h>
 #  endif

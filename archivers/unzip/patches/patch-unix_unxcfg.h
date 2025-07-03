$NetBSD: patch-unix_unxcfg.h,v 1.4 2025/07/03 09:59:10 jperkin Exp $

* Fix build on Debian GNU/kFreeBSD.
* Fix build under OpenBSD 5.5
  Patch from OpenBSD Ports
  "timeb was already well deprecated on 4.4BSD"
* Remove K&R prototype for gmtime()

--- unix/unxcfg.h.orig	2009-04-16 18:36:12.000000000 +0000
+++ unix/unxcfg.h
@@ -52,6 +52,7 @@
 
 #include <sys/types.h>          /* off_t, time_t, dev_t, ... */
 #include <sys/stat.h>
+#include <unistd.h>
 
 #ifdef NO_OFF_T
   typedef long zoff_t;
@@ -111,16 +112,17 @@ typedef struct stat z_stat;
 
 #ifdef BSD
 #  include <sys/time.h>
-#  include <sys/timeb.h>
+#  ifndef BSD4_4
+#    include <sys/timeb.h>
+#  endif
 #  if (defined(_AIX) || defined(__GLIBC__) || defined(__GNU__))
 #    include <time.h>
 #  endif
 #else
 #  include <time.h>
-   struct tm *gmtime(), *localtime();
 #endif
 
-#if (defined(BSD4_4) || (defined(SYSV) && defined(MODERN)))
+#if (defined(BSD4_4) || defined(__illumos__) || (defined(SYSV) && defined(MODERN)))
 #  include <unistd.h>           /* this includes utime.h on SGIs */
 #  if (defined(BSD4_4) || defined(linux) || defined(__GLIBC__))
 #    include <utime.h>
@@ -130,7 +132,7 @@ typedef struct stat z_stat;
 #    include <utime.h>
 #    define GOT_UTIMBUF
 #  endif
-#  if (!defined(GOT_UTIMBUF) && defined(__GNU__))
+#  if (!defined(GOT_UTIMBUF) && (defined(__GNU__) || defined(__illumos__)))
 #    include <utime.h>
 #    define GOT_UTIMBUF
 #  endif

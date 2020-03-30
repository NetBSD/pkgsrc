$NetBSD: patch-src_libs_libgroff_curtime.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/libs/libgroff/curtime.cpp.orig	2020-03-29 11:10:42.888676630 +0000
+++ src/libs/libgroff/curtime.cpp
@@ -15,6 +15,10 @@ for more details.
 The GNU General Public License version 2 (GPL2) is available in the
 internet at <http://www.gnu.org/licenses/gpl-2.0.txt>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <errno.h>
 #include <limits.h>
 #include <stdlib.h>

$NetBSD: patch-mozilla_media_mtransport_third__party_nICEr_src_util_mbslen.c,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c.orig	2014-07-18 00:05:39.000000000 +0000
+++ mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c
@@ -54,6 +54,13 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 # endif
 #endif
 
+#ifdef __DragonFly__
+#include <osreldate.h>
+# if __DragonFly_version > 300502
+#  define HAVE_XLOCALE
+# endif
+#endif
+
 #ifdef HAVE_XLOCALE
 #include <xlocale.h>
 #endif /* HAVE_XLOCALE */

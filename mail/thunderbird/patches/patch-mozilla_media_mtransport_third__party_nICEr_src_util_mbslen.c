$NetBSD: patch-mozilla_media_mtransport_third__party_nICEr_src_util_mbslen.c,v 1.3 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c.orig	2016-04-07 21:33:22.000000000 +0000
+++ mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c
@@ -47,6 +47,13 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #define HAVE_XLOCALE
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

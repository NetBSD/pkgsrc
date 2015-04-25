$NetBSD: patch-src_mesa_drivers_dri_common_xmlconfig.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Fix broken ifdef.

--- src/mesa/drivers/dri/common/xmlconfig.c.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mesa/drivers/dri/common/xmlconfig.c
@@ -53,7 +53,7 @@ extern char *program_invocation_name, *p
 #        include <stdlib.h>
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
-#elif defined(__NetBSD__) && defined(__NetBSD_Version) && (__NetBSD_Version >= 106000100)
+#elif defined(__NetBSD__) && defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
 #    include <stdlib.h>
 #    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__APPLE__)

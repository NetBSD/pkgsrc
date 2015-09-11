$NetBSD: patch-src_mesa_drivers_dri_common_xmlconfig.c,v 1.2 2015/09/11 00:03:36 tnn Exp $

PR pkg/50202.

--- src/mesa/drivers/dri/common/xmlconfig.c.orig	2015-07-14 18:10:47.000000000 +0000
+++ src/mesa/drivers/dri/common/xmlconfig.c
@@ -50,12 +50,17 @@ extern char *program_invocation_name, *p
 #    define GET_PROGRAM_NAME() program_invocation_short_name
 #elif defined(__CYGWIN__)
 #    define GET_PROGRAM_NAME() program_invocation_short_name
+/*
 #elif defined(__FreeBSD__) && (__FreeBSD__ >= 2)
 #    include <osreldate.h>
 #    if (__FreeBSD_version >= 440000)
 #        include <stdlib.h>
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
+*/
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#    include <stdlib.h>
+#    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__NetBSD__) && defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
 #    include <stdlib.h>
 #    define GET_PROGRAM_NAME() getprogname()

$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_src_log_r__log.c,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/src/log/r_log.c.orig	2013-10-23 22:09:11.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/src/log/r_log.c
@@ -48,6 +48,7 @@ static char *RCSSTRING __UNUSED__ ="$Id:
 #include "hex.h"
 
 #include <string.h>
+#include <errno.h>
 #ifndef _MSC_VER
 #include <strings.h>
 #include <syslog.h>

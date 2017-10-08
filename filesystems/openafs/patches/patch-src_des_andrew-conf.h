$NetBSD: patch-src_des_andrew-conf.h,v 1.1 2017/10/08 02:41:39 sevan Exp $

- Include BSD config for 32-bit ARM config

--- src/des/andrew-conf.h.orig	2017-07-15 20:59:16.278490000 +0000
+++ src/des/andrew-conf.h
@@ -47,6 +47,8 @@
 #ifdef AFS_XBSD_ENV
 #ifdef AFS_X86_XBSD_ENV
 #include "conf-i386-obsd.h"
+#elif defined(AFS_ARM32_XBSD_ENV)
+#include "conf-arm32-bsd.h"
 #elif defined(AFS_ALPHA_ENV)
 #include "conf-alpha-bsd.h"
 #else

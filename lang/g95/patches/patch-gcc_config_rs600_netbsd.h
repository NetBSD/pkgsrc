$NetBSD: patch-gcc_config_rs600_netbsd.h,v 1.1.2.2 2017/06/21 18:53:33 bsiegert Exp $

Don't try to link against a non-existent file on netbsd/powerpc

--- ../gcc-4.1.2/gcc/config/rs6000/netbsd.h.orig	2005-06-25 01:22:41.000000000 +0000
+++ ../gcc-4.1.2/gcc/config/rs6000/netbsd.h
@@ -76,8 +76,7 @@
 #define STARTFILE_SPEC NETBSD_STARTFILE_SPEC
 
 #undef  ENDFILE_SPEC
-#define ENDFILE_SPEC \
-  "crtsavres%O%s %(netbsd_endfile_spec)"
+#define ENDFILE_SPEC "%(netbsd_endfile_spec)"
 
 #undef  LIB_SPEC
 #define LIB_SPEC NETBSD_LIB_SPEC

$NetBSD: patch-libstdc++-v3_config_os_bsd_netbsd_ctype__base.h,v 1.1 2012/06/08 15:42:29 joerg Exp $

--- libstdc++-v3/config/os/bsd/netbsd/ctype_base.h.orig	2012-06-05 12:36:50.000000000 +0000
+++ libstdc++-v3/config/os/bsd/netbsd/ctype_base.h
@@ -30,8 +30,6 @@
 // Full details can be found from the CVS files at:
 //   anoncvs@anoncvs.netbsd.org:/cvsroot/basesrc/include/ctype.h
 // See www.netbsd.org for details of access.
-  
-#include <sys/param.h>
 
 namespace std _GLIBCXX_VISIBILITY(default)
 {
@@ -47,7 +45,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
     // on the mask type. Because of this, we don't use an enum.
     typedef unsigned char      	mask;
 
-#if __NetBSD_Version__ < 599004100
+#if !defined(_CTYPE_U)
     static const mask upper    	= _U;
     static const mask lower 	= _L;
     static const mask alpha 	= _U | _L;

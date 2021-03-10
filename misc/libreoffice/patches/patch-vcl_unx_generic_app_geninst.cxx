$NetBSD: patch-vcl_unx_generic_app_geninst.cxx,v 1.1 2021/03/10 16:07:53 ryoon Exp $

Set "OS Environment" on NetBSD,same as FreeBSD.

To Fix:
Help -> About LibreOffice
 Environment: OS: unknown


--- vcl/unx/generic/app/geninst.cxx.org	2021-02-25 12:19:22.000000000 +0000
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 
@@ -73,7 +73,7 @@ OUString SalGenericInstance::getOSVersio
         fclose( pVersion );
     }
     return aKernelVer;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     struct utsname stName;
     if ( uname( &stName ) != 0 )
         return aKernelVer;

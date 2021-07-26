$NetBSD: patch-vcl_unx_generic_app_geninst.cxx,v 1.2 2021/07/26 12:42:24 ryoon Exp $

Set "OS Environment" on NetBSD,same as FreeBSD.

To Fix:
Help -> About LibreOffice
 Environment: OS: unknown

Tweaked by Yasushi Oshima, PR pkg/56048.

--- vcl/unx/generic/app/geninst.cxx.orig	2021-07-16 21:17:42.000000000 +0000
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 
@@ -73,14 +73,18 @@ OUString SalGenericInstance::getOSVersio
         fclose( pVersion );
     }
     return aKernelVer;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     struct utsname stName;
     if ( uname( &stName ) != 0 )
         return aKernelVer;
 
+    aKernelVer = OUString::createFromAscii( stName.release );
+#if defined(__NetBSD__)
+    return OUString::createFromAscii( stName.sysname ) + " " +
+        aKernelVer.copy( 0, aKernelVer.getLength() );
+#else
     sal_Int32 nDots = 0;
     sal_Int32 nIndex = 0;
-    aKernelVer = OUString::createFromAscii( stName.release );
     while ( nIndex++ < aKernelVer.getLength() )
     {
         const char c = stName.release[ nIndex ];
@@ -89,6 +93,7 @@ OUString SalGenericInstance::getOSVersio
     }
     return OUString::createFromAscii( stName.sysname ) + " " +
         aKernelVer.copy( 0, nIndex );
+#endif
 #else
     return aKernelVer;
 #endif

$NetBSD: patch-vcl_unx_generic_app_geninst.cxx,v 1.3 2022/08/22 13:58:32 ryoon Exp $

Set "OS Environment" on NetBSD,same as FreeBSD.

To Fix:
Help -> About LibreOffice
 Environment: OS: unknown

Tweaked by Yasushi Oshima, PR pkg/56048.

--- vcl/unx/generic/app/geninst.cxx.orig	2022-08-10 14:14:32.000000000 +0000
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 
@@ -72,14 +72,18 @@ OUString SalGenericInstance::getOSVersio
         }
         fclose( pVersion );
     }
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
@@ -87,6 +91,7 @@ OUString SalGenericInstance::getOSVersio
             break;
     }
     aKernelVer = OUString::createFromAscii(stName.sysname) + " " + aKernelVer.copy(0, nIndex);
+#endif
 #elif defined(EMSCRIPTEN)
 #define str(s) #s
 #define xstr(s) str(s)

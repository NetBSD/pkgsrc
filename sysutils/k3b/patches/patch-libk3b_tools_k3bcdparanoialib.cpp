$NetBSD: patch-libk3b_tools_k3bcdparanoialib.cpp,v 1.2 2014/11/15 03:35:26 markd Exp $

--- libk3b/tools/k3bcdparanoialib.cpp.orig	2014-11-04 18:37:31.000000000 +0000
+++ libk3b/tools/k3bcdparanoialib.cpp
@@ -68,7 +68,7 @@ typedef short int int16_t;
 #define LIBCDIO_CDDA "cdio_cdda.dll"
 #define LIBCDIO_PARANOIA "cdio_paranoia.dll"
 #else
-#ifdef __NETBSD__
+#ifdef Q_OS_NETBSD
 #define CDDA_LIBCDDA_INTERFACE "cdda/libcdda_interace.so"
 #define CDDA_LIBCDDA_PARANOIA "cdda/libcdda_paranoia.so"
 #define LIBCDDA_INTERFACE "libcdda_interface.so"
@@ -555,7 +555,7 @@ K3b::CdparanoiaLib* K3b::CdparanoiaLib::
 
 #ifndef Q_OS_WIN32
         if( !s_libInterface ) {
-#ifndef __NETBSD__
+#ifndef Q_OS_NETBSD
             s_libInterface = dlopen( LIBCDIO_CDDA_1, RTLD_NOW|RTLD_GLOBAL );
             if( !s_libInterface ) {
                 s_libInterface = dlopen( LIBCDIO_CDDA_0, RTLD_NOW|RTLD_GLOBAL );
@@ -566,7 +566,7 @@ K3b::CdparanoiaLib* K3b::CdparanoiaLib::
                     // try the redhat & Co. location
                     if( !s_libInterface )
                         s_libInterface = dlopen( CDDA_LIBCDDA_INTERFACE, RTLD_NOW|RTLD_GLOBAL );
-#ifndef __NETBSD__
+#ifndef Q_OS_NETBSD
                 }
             }
 #endif
@@ -581,7 +581,7 @@ K3b::CdparanoiaLib* K3b::CdparanoiaLib::
 #ifndef Q_OS_WIN32
         if( s_haveLibCdio ) {
             s_libParanoia = dlopen( LIBCDIO_PARANOIA, RTLD_NOW );
-#ifndef __NETBSD__
+#ifndef Q_OS_NETBSD
             if( !s_libParanoia ) {
                 s_libParanoia = dlopen( LIBCDIO_PARANOIA_1, RTLD_NOW );
                 if( !s_libParanoia )

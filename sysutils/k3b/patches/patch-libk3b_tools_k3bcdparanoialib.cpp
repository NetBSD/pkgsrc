$NetBSD: patch-libk3b_tools_k3bcdparanoialib.cpp,v 1.1 2013/11/09 22:20:36 markd Exp $

Allow newer versions of libraries to be found.
Also fix problem where by k3b wont rip the first track when it is not
alphabetically the first track to be ripped.

--- libk3b/tools/k3bcdparanoialib.cpp.orig	2011-01-15 20:47:29.000000000 +0000
+++ libk3b/tools/k3bcdparanoialib.cpp
@@ -69,7 +69,7 @@ typedef short int int16_t;
 #define LIBCDIO_PARANOIA "cdio_paranoia.dll"
 #else
 #define LIBCDIO_CDDA "libcdio_cdda.so"
-#define LIBCDIO_PARANOIA "libcdio_paranoia.so.0"
+#define LIBCDIO_PARANOIA "libcdio_paranoia.so"
 #endif
 
 static bool s_haveLibCdio = false;
@@ -532,11 +532,11 @@ K3b::CdparanoiaLib* K3b::CdparanoiaLib::
     if( s_libInterface == 0 ) {
         s_haveLibCdio = false;
 #ifndef Q_OS_WIN32
-        s_libInterface = dlopen( "libcdda_interface.so.0", RTLD_NOW|RTLD_GLOBAL );
+        s_libInterface = dlopen( "libcdda_interface.so", RTLD_NOW|RTLD_GLOBAL );
 
         // try the redhat & Co. location
         if( s_libInterface == 0 )
-            s_libInterface = dlopen( "cdda/libcdda_interface.so.0", RTLD_NOW|RTLD_GLOBAL );
+            s_libInterface = dlopen( "cdda/libcdda_interface.so", RTLD_NOW|RTLD_GLOBAL );
 #endif
         // try the new cdio lib
         if( s_libInterface == 0 ) {
@@ -550,11 +550,11 @@ K3b::CdparanoiaLib* K3b::CdparanoiaLib::
         }
 
 #ifndef Q_OS_WIN32
-        s_libParanoia = dlopen( "libcdda_paranoia.so.0", RTLD_NOW );
+        s_libParanoia = dlopen( "libcdda_paranoia.so", RTLD_NOW );
 
         // try the redhat & Co. location
         if( s_libParanoia == 0 )
-            s_libParanoia = dlopen( "cdda/libcdda_paranoia.so.0", RTLD_NOW );
+            s_libParanoia = dlopen( "cdda/libcdda_paranoia.so", RTLD_NOW );
 #endif
         // try the new cdio lib
         if( s_haveLibCdio && s_libParanoia == 0 )
@@ -736,7 +736,7 @@ char* K3b::CdparanoiaLib::read( int* sta
 
     if( d->currentSector != d->data->sector() ) {
         kDebug() << "(K3b::CdparanoiaLib) need to seek before read. Looks as if we are reusing the paranoia instance.";
-        if( !d->data->paranoiaSeek( d->currentSector, SEEK_SET ) )
+        if( d->data->paranoiaSeek( d->currentSector, SEEK_SET ) == -1 )
             return 0;
     }
 

$NetBSD: patch-source_source_gameshared_q__arch.h,v 1.1 2025/09/29 13:31:28 nia Exp $

- Change "Linux" to Unix.
- Add support for NetBSD.
- Do not assume presence of alloca header.

--- source/source/gameshared/q_arch.h.orig	2016-03-26 19:22:10.000000000 +0000
+++ source/source/gameshared/q_arch.h
@@ -188,7 +188,7 @@ typedef UINT_PTR socket_handle_t;
 
 //==============================================
 
-#if defined ( __linux__ ) || defined ( __FreeBSD__ )
+#if defined ( __unix__ ) && !defined ( __APPLE__ )
 
 #define HAVE_INLINE
 
@@ -219,6 +219,9 @@ typedef UINT_PTR socket_handle_t;
 #if defined ( __FreeBSD__ )
 #define BUILDSTRING "FreeBSD"
 #define OSNAME "FreeBSD"
+#elif defined ( __NetBSD__ )
+#define BUILDSTRING "NetBSD"
+#define OSNAME "NetBSD"
 #elif defined ( __ANDROID__ )
 #define BUILDSTRING "Android"
 #define OSNAME "Android"
@@ -277,7 +280,9 @@ typedef UINT_PTR socket_handle_t;
 
 #define VAR( x ) # x
 
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
+#endif
 
 // wsw : aiwa : 64bit integers and integer-pointer types
 typedef int ioctl_param_t;

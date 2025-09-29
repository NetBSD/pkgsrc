$NetBSD: patch-source_source_snd__openal_qal.c,v 1.1 2025/09/29 13:31:29 nia Exp $

- Add support for more Unix-like platforms.

--- source/source/snd_openal/qal.c.orig	2025-09-29 07:57:44.069050118 +0000
+++ source/source/snd_openal/qal.c
@@ -42,7 +42,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define SYMLOAD( x, y ) GetProcAddress( x, y )
 #define OBJFREE( x ) FreeLibrary( x )
 
-#elif defined __linux__ || defined __FreeBSD__ || defined __MACOSX__ || defined __sun
+#elif defined __linux__ || defined __FreeBSD__ || defined __MACOSX__ || defined __sun || defined __unix__
 #include <dlfcn.h>
 #define OBJTYPE void *
 #define OBJLOAD( x ) dlopen( x, RTLD_LAZY | RTLD_GLOBAL )
@@ -53,7 +53,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #error "No lib loading code defined for platform."
 #endif
 
-#if defined __linux__ || defined __FreeBSD__ || defined __MACOSX__
+#if defined __linux__ || defined __FreeBSD__ || defined __MACOSX__ || defined __unix__
 #include <unistd.h>
 #include <sys/types.h>
 #endif

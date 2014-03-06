$NetBSD: patch-Top_csmodule.c,v 1.1 2014/03/06 10:16:53 mrg Exp $

--- Top/csmodule.c.orig	2014-01-07 08:54:20.000000000 -0800
+++ Top/csmodule.c	2014-02-13 02:01:01.000000000 -0800
@@ -89,7 +89,7 @@
 #endif
 
 #if !(defined (NACL))
-#if defined(LINUX) || defined(NEW_MACH_CODE)
+#if defined(LINUX) || defined(NEW_MACH_CODE) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <dlfcn.h>
 #elif defined(WIN32)
 #include <windows.h>
@@ -132,7 +132,7 @@
 
 /* default directory to load plugins from if environment variable is not set */
 #if !(defined (NACL))
-#if !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__)))
+#if !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)))
 #  define ENABLE_OPCODEDIR_WARNINGS 1
 #  ifdef CS_DEFAULT_PLUGINDIR
 #    undef CS_DEFAULT_PLUGINDIR
@@ -142,9 +142,9 @@
 #  define ENABLE_OPCODEDIR_WARNINGS 0
 #  ifndef CS_DEFAULT_PLUGINDIR
 #    ifndef USE_DOUBLE
-#      define CS_DEFAULT_PLUGINDIR  "/usr/local/lib/csound/plugins"
+#      define CS_DEFAULT_PLUGINDIR  __PKGSRC_PREFIX__ "lib/csound6/plugins-6.0"
 #    else
-#      define CS_DEFAULT_PLUGINDIR  "/usr/local/lib/csound/plugins64"
+#      define CS_DEFAULT_PLUGINDIR  __PKGSRC_PREFIX__ "lib/csound6/plugins-6.0"
 #    endif
 #  endif
 #endif
@@ -247,7 +247,7 @@
     err = csoundOpenLibrary(&h, libraryPath);
     if (UNLIKELY(err)) {
       char ERRSTR[256];
-#if !(defined(NACL)) && defined(LINUX)
+#if !(defined(NACL)) && (defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__))
       sprintf(ERRSTR, Str("could not open library '%s' (%s)"),
                       libraryPath, dlerror());
  #else
@@ -684,7 +684,7 @@
     return (void*) GetProcAddress((HMODULE) library, procedureName);
 }
 
-#elif !(defined(NACL)) && (defined(LINUX) || defined (NEW_MACH_CODE))
+#elif !(defined(NACL)) && (defined(LINUX) || defined (NEW_MACH_CODE) || defined(__NetBSD__) || defined(__DragonFly__))
 
 PUBLIC int csoundOpenLibrary(void **library, const char *libraryPath)
 {

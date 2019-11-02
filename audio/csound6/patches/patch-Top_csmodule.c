$NetBSD: patch-Top_csmodule.c,v 1.4 2019/11/02 22:25:46 mrg Exp $

Fix the installation path for csound6 plugins.
Add NetBSD and DragonFlyBSD support.

--- Top/csmodule.c.orig	2019-07-12 14:54:19.000000000 -0700
+++ Top/csmodule.c	2019-10-29 13:48:52.707598788 -0700
@@ -89,7 +89,7 @@
 #endif
 
 #if !(defined (NACL))
-#if defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__)
+#if defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <dlfcn.h>
 #elif defined(WIN32)
 #include <windows.h>
@@ -149,7 +149,7 @@
         "/boot/home/config/non-packaged/lib/csound6/plugins64";
 # endif
 # define CS_DEFAULT_PLUGINDIR  haikudirs
-#elif !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__)))
+#elif !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)))
 #  define ENABLE_OPCODEDIR_WARNINGS 1
 #  ifdef CS_DEFAULT_PLUGINDIR
 #    undef CS_DEFAULT_PLUGINDIR
@@ -159,9 +159,9 @@
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
@@ -264,7 +264,7 @@
     err = csoundOpenLibrary(&h, libraryPath);
     if (UNLIKELY(err)) {
       char ERRSTR[256];
- #if !(defined(NACL)) && (defined(LINUX) || defined(__HAIKU__))
+ #if !(defined(NACL)) && (defined(LINUX) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__))
       snprintf(ERRSTR, 256, Str("could not open library '%s' (%s)"),
                libraryPath, dlerror());
  #else
@@ -751,7 +751,7 @@
     return (void*) GetProcAddress((HMODULE) library, procedureName);
 }
 
-#elif !(defined(NACL)) && (defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__))
+#elif !(defined(NACL)) && (defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__))
 
 PUBLIC int csoundOpenLibrary(void **library, const char *libraryPath)
 {
@@ -906,7 +906,7 @@
                                  hrtfreverb_localops_init, minmax_localops_init,
                                  vaops_localops_init, paulstretch_localops_init,
                                  squinewave_localops_init, tabaudio_localops_init,
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
                                  cpumeter_localops_init,
 #endif
 #ifndef NACL

$NetBSD: patch-CPP_Windows_DLL.cpp,v 1.1 2014/12/01 12:43:07 wiz Exp $

Adapt for pkgsrc on OS X.

--- CPP/Windows/DLL.cpp.orig	2010-02-28 12:44:52.000000000 +0000
+++ CPP/Windows/DLL.cpp
@@ -2,7 +2,7 @@
 
 #include "StdAfx.h"
 
-#ifdef __APPLE_CC__
+#if defined(USE_APPLE_BUNDLE)
 #include <mach-o/dyld.h>
 #elif ENV_BEOS
 #include <kernel/image.h>
@@ -39,7 +39,7 @@ TRACEN((printf("CLibrary::Free(%p)\n",(v
   if (_module == 0)
     return true;
 
-#ifdef __APPLE_CC__
+#if defined(USE_APPLE_BUNDLE)
   int ret = NSUnLinkModule ((NSModule)_module, 0);
 #elif ENV_BEOS
   int ret = unload_add_on((image_id)_module);
@@ -57,7 +57,7 @@ static FARPROC local_GetProcAddress(HMOD
   void *ptr = 0;
   TRACEN((printf("local_GetProcAddress(%p,%s)\n",(void *)module,lpProcName)))
   if (module) {
-#ifdef __APPLE_CC__
+#if defined(USE_APPLE_BUNDLE)
     char name[MAX_PATHNAME_LEN];
     snprintf(name,sizeof(name),"_%s",lpProcName);
     name[sizeof(name)-1] = 0;
@@ -115,7 +115,7 @@ bool CLibrary::Load(LPCTSTR lpLibFileNam
 
   TRACEN((printf("CLibrary::Load(%ls) => %s\n",lpLibFileName,name)))
 
-#ifdef __APPLE_CC__
+#if defined(USE_APPLE_BUNDLE)
   NSObjectFileImage image;
   NSObjectFileImageReturnCode nsret;
 
@@ -173,7 +173,7 @@ TRACEN((printf("load_add_on(%s)=%d\n",p.
     if (fctTest) fctTest();
 
   } else {
-#ifdef __APPLE_CC__
+#if defined(USE_APPLE_BUNDLE)
     NSLinkEditErrors c;
     int num_err;
     const char *file,*err;

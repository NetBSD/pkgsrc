$NetBSD: patch-avidemux_ADM__core_include_ADM__assert.h,v 1.1 2013/06/13 14:30:17 joerg Exp $

--- avidemux/ADM_core/include/ADM_assert.h.orig	2013-06-13 13:39:33.000000000 +0000
+++ avidemux/ADM_core/include/ADM_assert.h
@@ -91,15 +91,7 @@ extern adm_fast_memcpy myAdmMemcpy;
 #endif
 
 #if !defined(__APPLE__) && !defined(__WIN64)
-#ifndef ADM_LEGACY_PROGGY
-  #define malloc #error
-  #define realloc #error
-  #define memalign #error
-  #define free  #error
-  #undef strdup
-  #define strdup #error
-  #define calloc #error
-#else
+#ifdef ADM_LEGACY_PROGGY
   #define malloc ADM_alloc
   #define realloc ADM_realloc
   #define memalign(x,y) ADM_alloc(y)

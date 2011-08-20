$NetBSD: patch-include-allegro-internal-alconfig.h,v 1.1 2011/08/20 15:28:09 joerg Exp $

--- include/allegro/internal/alconfig.h.orig	2011-08-19 14:59:33.000000000 +0000
+++ include/allegro/internal/alconfig.h
@@ -73,7 +73,7 @@
    #define ALLEGRO_GCC
 
    #ifndef AL_INLINE
-      #ifdef __cplusplus
+      #if defined(__cplusplus) || (defined(__GNUC_STDC_INLINE__) && __GNUC_STDC_INLINE__)
          #define AL_INLINE(type, name, args, code)    \
             static inline type name args;             \
             static inline type name args code

$NetBSD: patch-libgcc_crtstuff.c,v 1.2 2024/04/01 14:33:57 js Exp $

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90147

Disable TM clone registry on QNX, as the linker does not support it.

--- libgcc/crtstuff.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libgcc/crtstuff.c
@@ -81,7 +81,7 @@ call_ ## FUNC (void)					\
 #endif
 
 #if defined(TARGET_DL_ITERATE_PHDR) && \
-   (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__))
+   (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
 #define BSD_DL_ITERATE_PHDR_AVAILABLE
 #endif
  
@@ -151,7 +151,8 @@ call_ ## FUNC (void)					\
 # define HIDDEN_DTOR_LIST_END
 #endif
 
-#if !defined(USE_TM_CLONE_REGISTRY) && defined(OBJECT_FORMAT_ELF)
+#if !defined(USE_TM_CLONE_REGISTRY) && defined(OBJECT_FORMAT_ELF) \
+    && !defined(__QNX__)
 # define USE_TM_CLONE_REGISTRY 1
 #elif !defined(USE_TM_CLONE_REGISTRY)
 # define USE_TM_CLONE_REGISTRY 0

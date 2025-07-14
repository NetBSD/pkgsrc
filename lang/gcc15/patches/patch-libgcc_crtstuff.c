$NetBSD: patch-libgcc_crtstuff.c,v 1.1 2025/07/14 17:44:53 wiz Exp $

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90147

--- libgcc/crtstuff.c.orig	2025-04-25 08:18:04.000000000 +0000
+++ libgcc/crtstuff.c
@@ -81,7 +81,7 @@ call_ ## FUNC (void)					\
 #endif
 
 #if defined(TARGET_DL_ITERATE_PHDR) && \
-   (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__))
+   (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
 #define BSD_DL_ITERATE_PHDR_AVAILABLE
 #endif
 

$NetBSD: patch-compat_sha2.h,v 1.1 2024/02/11 14:47:07 vins Exp $

attribute __bounded__ is only defined in OpenBSD's GCC.

--- compat/sha2.h.orig	2023-03-13 14:37:38.000000000 +0000
+++ compat/sha2.h
@@ -39,6 +39,10 @@
 #ifndef _SSHSHA2_H
 #define _SSHSHA2_H

+#if !defined(HAVE_ATTRIBUTE__BOUNDED__) && !defined(__OpenBSD__)
+#define __bounded__(x, y, z)
+#endif
+
 #if !defined(HAVE_SHA256UPDATE) || !defined(HAVE_SHA384UPDATE) || \
     !defined(HAVE_SHA512UPDATE)
 

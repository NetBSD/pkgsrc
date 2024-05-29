$NetBSD: patch-compat_sha2.h,v 1.2 2024/05/29 17:28:29 vins Exp $

attribute __bounded__ is only defined in OpenBSD's GCC.

--- compat/sha2.h.orig	2024-05-29 15:52:53.668746638 +0000
+++ compat/sha2.h
@@ -39,6 +39,10 @@
 #ifndef _SSHSHA2_H
 #define _SSHSHA2_H
 
+#if !defined(HAVE_ATTRIBUTE__BOUNDED__) && !defined(__OpenBSD__)
+#define __bounded__(x, y, z)
+#endif
+
 #if !defined(HAVE_SHA256UPDATE)
 
 /*** SHA-256/384/512 Various Length Definitions ***********************/

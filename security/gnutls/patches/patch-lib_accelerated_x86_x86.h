$NetBSD: patch-lib_accelerated_x86_x86.h,v 1.1 2014/02/10 12:01:20 tron Exp $

Fix build under Mac OS X when assembler code is enabled.
Patch taken from here:

https://www.gitorious.org/gnutls/gnutls/commit/54768ca1cd9049bbd1c695696ef3c8595c6052db

--- lib/accelerated/x86/x86.h.orig	2014-01-01 17:14:59.000000000 +0000
+++ lib/accelerated/x86/x86.h	2014-02-10 11:31:27.000000000 +0000
@@ -22,6 +22,8 @@
 
 #include <config.h>
 
+extern unsigned int _gnutls_x86_cpuid_s[4];
+
 #if defined(ASM_X86)
 
 void gnutls_cpuid(unsigned int func, unsigned int *ax, unsigned int *bx,
@@ -43,5 +45,4 @@
  (nettle_hash_digest_func *) digest_func	\
 } 
 
-
 #endif

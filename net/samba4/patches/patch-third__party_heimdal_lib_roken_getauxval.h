$NetBSD: patch-third__party_heimdal_lib_roken_getauxval.h,v 1.1 2022/07/29 20:33:38 jperkin Exp $

Avoid auxv_t conflict on SunOS.

--- third_party/heimdal/lib/roken/getauxval.h.orig	2022-01-24 10:27:00.525315000 +0000
+++ third_party/heimdal/lib/roken/getauxval.h
@@ -44,7 +44,7 @@
 #include <sys/exec_elf.h>
 #endif
 
-#ifndef HAVE_AUXV_T
+#if !defined(HAVE_AUXV_T) && !defined(__sun)
 /*
  * Illumos defines auxv_t per the ABI standards, but all other OSes seem
  * to use { long; long; } instead, depends on sizeof(long) ==

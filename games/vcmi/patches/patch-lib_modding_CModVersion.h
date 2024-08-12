$NetBSD: patch-lib_modding_CModVersion.h,v 1.1 2024/08/12 11:19:26 nia Exp $

Add support for NetBSD.

--- lib/modding/CModVersion.h.orig	2024-08-11 18:21:51.574618351 +0000
+++ lib/modding/CModVersion.h
@@ -10,7 +10,7 @@
 
 #pragma once
 
-#if defined(__UCLIBC__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__UCLIBC__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #undef major
 #undef minor
 #undef patch

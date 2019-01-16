$NetBSD: patch-loudmouth_lm-resolver.c,v 1.1 2019/01/16 01:36:12 gutteridge Exp $

Fix a build breakage on non-x86 NetBSD architectures where arpa/
nameser_compat.h was being unnecessarily included (without additional
dependent macros being defined, as nameser.h takes care of when it's
included first).

--- loudmouth/lm-resolver.c.orig	2016-02-14 17:05:11.000000000 +0000
+++ loudmouth/lm-resolver.c
@@ -21,7 +21,7 @@
 #include <string.h>
 
 /* Needed on Mac OS X */
-#if HAVE_ARPA_NAMESER_COMPAT_H
+#if defined(__APPLE__) && HAVE_ARPA_NAMESER_COMPAT_H
 #include <arpa/nameser_compat.h>
 #endif
 

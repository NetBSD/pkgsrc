$NetBSD: patch-cups_versioning.h,v 1.1 2021/04/21 13:18:22 adam Exp $

Fix building on Darwin.

--- cups/versioning.h.orig	2021-02-21 14:28:23.000000000 +0000
+++ cups/versioning.h
@@ -39,6 +39,7 @@
 
 #  ifdef __APPLE__
 #    include <os/availability.h>
+#    include <TargetConditionals.h>
 #  endif /* __APPLE__ */
 
 #  ifdef __has_extension		/* Clang */

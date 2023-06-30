$NetBSD: patch-gettext-runtime_intl_intl-compat.c,v 1.1 2023/06/30 08:31:04 tnn Exp $

Make sure bindtextdomain(3) is visible on macOS, as it cannot be exported otherwise:

ld: warning: cannot export hidden symbol _bindtextdomain from .libs/intl-compat.o

--- gettext-runtime/intl/intl-compat.c.orig	2023-06-30 08:04:29.086186639 +0000
+++ gettext-runtime/intl/intl-compat.c
@@ -47,7 +47,7 @@
 /* When building a DLL, we must export some functions.  Note that because
    the functions are only defined for binary backward compatibility, we
    don't need to use __declspec(dllimport) in any case.  */
-#if HAVE_VISIBILITY && BUILDING_DLL
+#if HAVE_VISIBILITY && BUILDING_DLL || defined(__APPLE__)
 # define DLL_EXPORTED __attribute__((__visibility__("default")))
 #elif defined _MSC_VER && BUILDING_DLL
 # define DLL_EXPORTED __declspec(dllexport)

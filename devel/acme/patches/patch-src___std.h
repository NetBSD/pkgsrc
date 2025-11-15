$NetBSD: patch-src___std.h,v 1.1 2025/11/15 14:48:22 rhialto Exp $

- Use the default library location

--- src/_std.h.orig	2025-11-15 13:56:54.402868858 +0000
+++ src/_std.h
@@ -18,7 +18,7 @@
 
 // string containing the prefix for accessing files from the library tree
 // (use "--libpath" cli switch or "ACME" environment variable to set this)
-#define PLATFORM_LIBPREFIX	NULL
+#define PLATFORM_LIBPREFIX	DEFAULT_ACME_LIB
 #define PLATFORM_USE_ENV_VAR	1	// library access needs "ACME" environment variable
 // if you are building an "ACME" package for a linux or bsd distribution, you
 // could put the library files at /usr/share/acme/lib/ and use that path instead

$NetBSD: patch-va_va__internal.h,v 1.1 2026/07/03 06:01:25 adam Exp $

Fix build.

--- va/va_internal.h.orig	2026-07-03 05:55:49.613855116 +0000
+++ va/va_internal.h
@@ -34,6 +34,7 @@ extern "C" {
 /* No setuid/setgid on Windows, secure_getenv is just getenv */
 #define secure_getenv getenv
 #else
+#include <unistd.h>
 static inline char * secure_getenv(const char *name)
 {
     if (getuid() == geteuid() && getgid() == getegid())

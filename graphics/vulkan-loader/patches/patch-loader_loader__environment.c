$NetBSD: patch-loader_loader__environment.c,v 1.2 2026/07/29 13:52:15 kikadf Exp $

* Support NetBSD

--- loader/loader_environment.c.orig	2026-07-17 04:40:32.000000000 +0000
+++ loader/loader_environment.c
@@ -49,7 +49,7 @@ char *loader_getenv(const char *name, co
 }
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.

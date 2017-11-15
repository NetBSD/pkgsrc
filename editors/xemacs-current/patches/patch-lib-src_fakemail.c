$NetBSD: patch-lib-src_fakemail.c,v 1.1 2017/11/15 14:57:58 hauke Exp $

Fix build on DragonFly.

Was patch-aj

--- lib-src/fakemail.c.orig	2013-08-21 17:43:44.000000000 +0000
+++ lib-src/fakemail.c
@@ -148,15 +148,13 @@ extern char *malloc (), *realloc ();
 #include <osreldate.h>
 #endif
 
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 || defined(__DragonFly__)
 #define CURRENT_USER 
 #endif 
 
 #ifdef CURRENT_USER
 extern struct passwd *getpwuid ();
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 
-extern uid_t geteuid (); 
-#else 
+#if defined(__FreeBSD_version) && __FreeBSD_version < 400000 
 extern unsigned short geteuid (); 
 #endif 
 static struct passwd *my_entry;

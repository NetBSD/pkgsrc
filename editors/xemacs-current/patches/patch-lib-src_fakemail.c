$NetBSD: patch-lib-src_fakemail.c,v 1.2 2023/05/21 00:13:56 hauke Exp $

Fix build on DragonFly.

Was patch-aj

--- lib-src/fakemail.c.orig	2023-05-13 18:09:52.000000000 +0000
+++ lib-src/fakemail.c
@@ -140,16 +140,16 @@ static boolean no_problems = true;
 #include <osreldate.h>
 #endif
 
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 || defined(__DragonFly__)
 #define CURRENT_USER 
 #endif 
 
 #ifdef CURRENT_USER
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 || defined(__DragonFly__)
 #include <sys/types.h>
 #include <pwd.h>
 #include <stdlib.h>
-#else 
+#else
 extern unsigned short geteuid (); 
 #endif 
 static struct passwd *my_entry;

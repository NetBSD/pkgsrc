$NetBSD: patch-params.h,v 1.1 2018/08/05 15:00:46 schmonz Exp $

Avoid Linuxisms.

--- params.h.orig	2004-01-13 16:17:32.000000000 +0000
+++ params.h
@@ -18,7 +18,7 @@
 #define WANT_USAGE              1 /* see usage.c */
 #define WANT_PIDINFO            1 /* see doname.c */
 #define WANT_VALID_SHELL        1 /* check for a valid shell */
-#define WANT_SHADOW_PASSWD      1 /* support for getspnam() */
+#define WANT_SHADOW_PASSWD      0 /* support for getspnam() */
 #define WANT_LASTPOP            0 /* support for the .lastpop file */
 #define WANT_DIE_MSG            1 /* die_msg(code, "description") -> exit(exit) */
 #define WANT_DEBUG              0 /* enable extra debugging messages */
@@ -40,8 +40,8 @@
 #define LOG_VHOME_FOUND		1 /* see doc/ENVIRON */
 
 /* define here the setuid/setgid functions of your system */
-#define SETuid(x) setresuid(x,x,x)
-#define SETgid(x) setresgid(x,x,x)
+#define SETuid(x) setuid(x)
+#define SETgid(x) setgid(x)
 
 /* seconds - for pop3-before-smtp (todo!) */
 #define LASTPOP_DEFAULT         23

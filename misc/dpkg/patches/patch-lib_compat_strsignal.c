$NetBSD: patch-lib_compat_strsignal.c,v 1.1 2017/02/05 18:46:29 wiz Exp $

  CC       libcompat_test_la-scandir.lo
strsignal.c:63:26: error: conflicting types for 'sys_siglist'
 extern const char *const sys_siglist[];
                          ^
In file included from strsignal.c:22:0:
/usr/include/signal.h:52:27: note: previous declaration of 'sys_siglist' was here
 extern const char *const *sys_siglist __RENAME(__sys_siglist14);
                           ^

--- lib/compat/strsignal.c.orig	2017-01-31 03:03:31.000000000 +0000
+++ lib/compat/strsignal.c
@@ -60,7 +60,6 @@ const char *const sys_siglist[] = {
 #  define NSIG 32
 # endif
 # define COMPAT_NSIGLIST NSIG
-extern const char *const sys_siglist[];
 #endif
 
 const char *

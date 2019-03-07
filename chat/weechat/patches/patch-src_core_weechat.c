$NetBSD: patch-src_core_weechat.c,v 1.1 2019/03/07 18:09:24 jperkin Exp $

Need unistd.h for mkdtemp(3).

--- src/core/weechat.c.orig	2019-02-17 07:20:07.000000000 +0000
+++ src/core/weechat.c
@@ -47,6 +47,7 @@
 #include <sys/time.h>
 #include <time.h>
 #include <signal.h>
+#include <unistd.h>
 
 #ifdef HAVE_LANGINFO_CODESET
 #include <langinfo.h>

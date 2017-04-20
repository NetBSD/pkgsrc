$NetBSD: patch-lib_notmuch-private.h,v 1.1 2017/04/20 09:06:34 jperkin Exp $

Include strings.h for index(3).

--- lib/notmuch-private.h.orig	2017-04-01 12:29:38.000000000 +0000
+++ lib/notmuch-private.h
@@ -38,6 +38,7 @@ NOTMUCH_BEGIN_DECLS
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <string.h>
+#include <strings.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>

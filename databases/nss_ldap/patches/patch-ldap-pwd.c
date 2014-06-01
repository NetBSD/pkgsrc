$NetBSD: patch-ldap-pwd.c,v 1.1 2014/06/01 19:38:10 asau Exp $

--- ldap-pwd.c.orig	2009-11-06 10:28:08.000000000 +0000
+++ ldap-pwd.c
@@ -23,2 +23,6 @@ static char rcsId[] =
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <unistd.h>
+#endif
 #include "config.h"

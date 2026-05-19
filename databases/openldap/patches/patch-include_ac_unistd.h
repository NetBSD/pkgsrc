$NetBSD: patch-include_ac_unistd.h,v 1.1 2026/05/19 08:28:13 jperkin Exp $

Fix for modern C.

--- include/ac/unistd.h.orig	2026-05-19 08:26:56.915523060 +0000
+++ include/ac/unistd.h
@@ -32,7 +32,7 @@
 /* note: callers of crypt(3) should include <ac/crypt.h> */
 
 #if defined(HAVE_GETPASSPHRASE)
-LDAP_LIBC_F(char*)(getpassphrase)();
+LDAP_LIBC_F(char*)(getpassphrase)(const char *);
 
 #else
 #define getpassphrase(p) lutil_getpass(p)

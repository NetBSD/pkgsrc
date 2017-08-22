$NetBSD: patch-support_unistd.c,v 1.1 2017/08/22 13:43:35 jperkin Exp $

Support private domainname functions from SunOS libnsl.

--- support/unistd.c.orig	2015-08-25 20:33:41.000000000 +0000
+++ support/unistd.c
@@ -209,6 +209,11 @@ Mono_Posix_Syscall_sethostid (gint64 hos
 }
 #endif /* def HAVE_SETHOSTID */
 
+#ifdef __sun
+int getdomainname(char *, int);
+int setdomainname(char *, int);
+#endif
+
 #ifdef HAVE_GETDOMAINNAME
 gint32
 Mono_Posix_Syscall_getdomainname (char *name, mph_size_t len)

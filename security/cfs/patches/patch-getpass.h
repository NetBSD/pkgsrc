$NetBSD: patch-getpass.h,v 1.1 2022/12/19 23:18:37 gdt Exp $

See scheme in pkgsrc Makefile to use getpass rather than cfs's getpassword.

The entire scheme needs discussion with upstream.

--- getpass.h.orig	2022-12-19 22:34:48.546071775 +0000
+++ getpass.h
@@ -4,7 +4,9 @@
 /* Historically getpass only allowed 127 chars, but stdin entry allowed 255 */
 #define	MAX_PASSPHRASE_LEN	255
 
+#ifndef HAVE_GETPASS
 char 	*getpassword(char *);
+#endif
 int	 old_pwcrunch(char *, cfs_admkey *);
 int	 new_pwcrunch(char *, cfs_admkey *);
 void	 decrypt_key(cfs_admkey *, u_char *);

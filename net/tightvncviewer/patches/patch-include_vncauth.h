$NetBSD: patch-include_vncauth.h,v 1.1 2025/10/12 22:35:32 mrg Exp $

Add missing prototypes.


--- include/vncauth.h.orig	2000-06-11 05:00:51.000000000 -0700
+++ include/vncauth.h	2025-10-12 15:23:50.435408620 -0700
@@ -24,7 +24,9 @@
 #define MAXPWLEN 8
 #define CHALLENGESIZE 16
 
-extern int vncEncryptAndStorePasswd(char *passwd, char *fname);
-extern char *vncDecryptPasswdFromFile(char *fname);
-extern void vncRandomBytes(unsigned char *bytes);
-extern void vncEncryptBytes(unsigned char *bytes, char *passwd);
+int vncEncryptAndStorePasswd(char *passwd, char *fname);
+int vncEncryptAndStorePasswd2(char *passwd, char *passwdViewOnly, char *fname);
+char *vncDecryptPasswdFromFile(char *fname);
+int vncDecryptPasswdFromFile2(char *fname, char *passwdFullControl, char *passwdViewOnly);
+void vncRandomBytes(unsigned char *bytes);
+void vncEncryptBytes(unsigned char *bytes, char *passwd);

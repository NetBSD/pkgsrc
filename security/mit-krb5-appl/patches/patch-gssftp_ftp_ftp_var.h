$NetBSD: patch-gssftp_ftp_ftp_var.h,v 1.2 2012/11/29 07:31:02 adam Exp $

Don't redefine sig_t and sigtype.

--- gssftp/ftp/ftp_var.h.orig	2012-02-26 13:04:30.000000000 +0000
+++ gssftp/ftp/ftp_var.h
@@ -53,15 +53,6 @@
 #define PERROR_SOCKET(str) perror(str)
 #endif
 
-#ifdef _WIN32
-typedef void (*sig_t)(int);
-typedef void sigtype;
-#else
-#define sig_t my_sig_t
-#define sigtype krb5_sigtype
-typedef sigtype (*sig_t)();
-#endif
-
 /*
  * FTP global variables.
  */
@@ -168,6 +159,15 @@
 extern struct macel macros[16];
 extern char macbuf[4096];
 
+#ifdef _WIN32
+typedef void (*sig_t)(int);
+typedef void sigtype;
+#else
+#define sig_t my_sig_t
+#define sigtype krb5_sigtype
+typedef sigtype (*sig_t)();
+#endif
+
 #ifdef DEFINITIONS
 #undef extern
 #endif

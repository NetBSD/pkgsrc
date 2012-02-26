$NetBSD: patch-gssftp_ftp_ftp_var.h,v 1.1 2012/02/26 13:16:32 adam Exp $

Don't redefine sig_t and sigtype.

--- gssftp/ftp/ftp_var.h.orig	2012-02-26 13:04:30.000000000 +0000
+++ gssftp/ftp/ftp_var.h
@@ -57,9 +57,7 @@ FILE* fdopen_socket(SOCKET s, char* mode
 typedef void (*sig_t)(int);
 typedef void sigtype;
 #else
-#define sig_t my_sig_t
 #define sigtype krb5_sigtype
-typedef sigtype (*sig_t)();
 #endif
 
 /*

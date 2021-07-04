$NetBSD: patch-ai,v 1.10 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/mci.c.orig	2020-05-19 19:54:33.000000000 +0000
+++ sendmail/mci.c
@@ -20,6 +20,7 @@ SM_RCSID("@(#)$Id: mci.c,v 8.225 2013-11
 #endif
 
 #include <dirent.h>
+#include <limits.h>
 #if STARTTLS
 # include <tls.h>
 #endif
@@ -788,7 +789,11 @@ mci_lock_host_statfile(mci)
 {
 	int save_errno = errno;
 	int retVal = EX_OK;
+#if defined(PATH_MAX)
+	char fname[PATH_MAX];
+#else
 	char fname[MAXPATHLEN];
+#endif
 
 	if (HostStatDir == NULL || mci->mci_host == NULL)
 		return EX_OK;

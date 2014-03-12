$NetBSD: patch-src_gpshell.c,v 1.1 2014/03/12 21:29:25 gdt Exp $

Don't exit with an error if the card is locked.  See:
http://sourceforge.net/mailarchive/forum.php?thread_name=CADr12F1tV04Atz-n5f43%2BenQNYF09HXMextZsLF-2QpomQAJWw%40mail.gmail.com&forum_name=opensc-devel
Not yet reported upstream.

--- src/gpshell.c.orig	2010-10-12 19:49:35.000000000 +0000
+++ src/gpshell.c
@@ -935,8 +935,14 @@ static int handleCommands(FILE *fd)
                 {
                     _tprintf (_T("select_application() returns 0x%08lX (%s)\n"),
                               status.errorCode, status.errorMessage);
-                    rv = EXIT_FAILURE;
-                    goto end;
+
+                    /* 6283 is warning  we want to continue  and unlock */
+                    if (status.errorCode != OPGP_ISO7816_WARNING_CM_LOCKED)
+                    {
+                        rv = EXIT_FAILURE;
+                        goto end;
+                    }
+                    status.errorStatus =  OPGP_ERROR_STATUS_SUCCESS;
                 }
                 memcpy(selectedAID, optionStr.AID, optionStr.AIDLen);
                 selectedAIDLength = optionStr.AIDLen;

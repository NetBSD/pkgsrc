$NetBSD: patch-nss_cmd_signtool_certgen.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/cmd/signtool/certgen.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/cmd/signtool/certgen.c
@@ -50,7 +50,7 @@ GenerateCert(char *nickname, int keysize
                "\n\"y\" to continue, or anything else to abort: ");
     pr_fgets(stdinbuf, 160, PR_STDIN);
     PR_fprintf(PR_STDOUT, "\n");
-    if (tolower(stdinbuf[0]) != 'y') {
+    if (tolower((unsigned char)stdinbuf[0]) != 'y') {
         PR_fprintf(errorFD, "Operation aborted at user's request.\n");
         errorCount++;
         return -1;

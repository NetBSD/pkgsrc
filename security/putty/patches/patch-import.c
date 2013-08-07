$NetBSD: patch-import.c,v 1.3 2013/08/07 11:06:39 drochner Exp $

--- import.c.orig	2013-07-20 13:15:20.000000000 +0000
+++ import.c
@@ -725,8 +725,8 @@ int openssh_write(const Filename *filena
     unsigned char *outblob;
     int outlen;
     struct mpint_pos numbers[9];
-    int nnumbers, pos, len, seqlen, i;
-    char *header, *footer;
+    int nnumbers = 0, pos = 0, len = 0, seqlen = 0, i = 0;
+    char *header = NULL, *footer = NULL;
     char zero[1];
     unsigned char iv[8];
     int ret = 0;
@@ -1547,8 +1547,8 @@ int sshcom_write(const Filename *filenam
     unsigned char *outblob;
     int outlen;
     struct mpint_pos numbers[6];
-    int nnumbers, initial_zero, pos, lenpos, i;
-    char *type;
+    int nnumbers = 0, initial_zero = 0, pos = 0, lenpos = 0, i = 0;
+    char *type = NULL;
     char *ciphertext;
     int cipherlen;
     int ret = 0;

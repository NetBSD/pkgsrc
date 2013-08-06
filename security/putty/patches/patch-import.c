$NetBSD: patch-import.c,v 1.2 2013/08/06 12:23:37 drochner Exp $

see http://svn.tartarus.org/sgt?view=revision&sortby=date&revision=9896

--- import.c.orig	2010-04-12 11:02:06.000000000 +0000
+++ import.c
@@ -290,7 +290,7 @@ static int ssh2_read_mpint(void *data, i
     if (len < 4)
         goto error;
     bytes = GET_32BIT(d);
-    if (len < 4+bytes)
+    if (bytes < 0 || len-4 < bytes)
         goto error;
 
     ret->start = d + 4;
@@ -717,8 +717,8 @@ int openssh_write(const Filename *filena
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
@@ -1513,8 +1513,8 @@ int sshcom_write(const Filename *filenam
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

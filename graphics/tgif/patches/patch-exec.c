$NetBSD: patch-exec.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora

--- exec.c.orig	2011-05-18 22:41:20.000000000 +0000
+++ exec.c
@@ -530,6 +530,7 @@ int AppendToTmpStr(psz)
 
 int AppendToTmpStr2(psz1, psz2, tg2)
    char *psz1, *psz2;
+   int tg2;
 {
    int len1=strlen(psz1), len2=strlen(psz2), rc=0;
    char *psz=(char*)malloc((len1+len2+1)*sizeof(char));

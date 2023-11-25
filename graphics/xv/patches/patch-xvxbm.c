$NetBSD: patch-xvxbm.c,v 1.1 2023/11/25 08:03:01 tsutsui Exp $

- fix a bug that puts a garbage in the first 8 pixels when loading xbm
  filename contains '0x' strings

--- xvxbm.c.orig	2023-11-25 07:43:40.021758068 +0000
+++ xvxbm.c
@@ -80,6 +80,11 @@ int LoadXBM(fname, pinfo)
 
 
 
+  /* scan forward until we see '= {' before bitmap array to skip filename */
+  c = getc(fp);
+  while (c!=EOF && c!='=') { c = getc(fp); }
+  while (c!=EOF && c!='{') { c = getc(fp); }
+
   /* scan forward until we see the first '0x' */
   c = getc(fp);  c1 = getc(fp);
   while (c1!=EOF && !(c=='0' && c1=='x') ) { c = c1;  c1 = getc(fp); }

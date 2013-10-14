$NetBSD: patch-src_ignore.c,v 1.1 2013/10/14 06:51:02 adam Exp $

--- src/ignore.c.orig	2005-09-12 18:57:45.000000000 -0700
+++ src/ignore.c	2005-09-12 18:57:58.000000000 -0700
@@ -36,7 +36,7 @@
 
 const char *ign_default = ". .. core RCSLOG tags TAGS RCS SCCS .make.state\
  .nse_depinfo #* .#* cvslog.* ,* CVS CVS.adm .del-* *.a *.olb *.o *.obj\
- *.so *.Z *~ *.old *.elc *.ln *.bak *.BAK *.orig *.rej *.exe _$* *$";
+ *.so *.Z *~ *.old *.elc *.ln *.bak *.BAK *.orig *.rej *.exe _$* *$ ._*";
 
 #define IGN_GROW 16			/* grow the list by 16 elements at a
 					 * time */

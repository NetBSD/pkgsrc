$NetBSD: patch-qterm.h,v 1.1 2019/08/30 14:17:07 nia Exp $

Fix build with modern C compilers.

--- qterm.h.orig	1997-04-11 13:25:04.000000000 +0000
+++ qterm.h
@@ -10,6 +10,7 @@
 
 #ifndef __qterm_h__
 #define __qterm_h__
+#include <string.h>
 
 #ifndef TABFILE
 # define TABFILE	"/usr/local/etc/qtermtab" /* Default qtermtab file */
@@ -77,7 +78,6 @@ char		       *strerror();
 char		       *xmalloc();
 extern char	       *ProgName;
 extern char	       *TermFile;
-extern char	       *strcpy();
 extern int		Debug;
 extern int		DoSysTabFile;
 extern int		DoUsrTabFile;
@@ -87,7 +87,12 @@ void			AlarmOff();
 void			Done();
 void			MakeTable();
 void			SetupSignals();
-
+int			ReadTabFile();
+int			SetTtyModes();
+int			UnSetTtyModes();
+char			*FixCntrl();
+int			StrToArgs();
+int			RegExMatch();
 #ifdef HAVE_STDARG_H
 void			Error(char *fmt, ...);
 void			dprintf(char *fmt, ...);

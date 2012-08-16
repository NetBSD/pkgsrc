$NetBSD: patch-Src_prototypes.h,v 1.1 2012/08/16 13:31:20 wiz Exp $

Fix build on NetBSD-5.99.40.
Patch from Peter Stephenson <Peter.Stephenson@csr.com> on zsh-workers.

--- Src/prototypes.h.orig	2011-05-03 18:38:21.000000000 +0000
+++ Src/prototypes.h
@@ -49,11 +49,18 @@ extern int tgetent _((char *bp, TC_CONST
 extern int tgetnum _((char *id));
 extern int tgetflag _((char *id));
 extern char *tgetstr _((char *id, char **area));
-extern char *tgoto _((TC_CONST char *cm, int destcol, int destline));
 extern int tputs _((TC_CONST char *cp, int affcnt, int (*outc) (int)));
 #undef TC_CONST
 #endif
 
+/*
+ * Some systems that do have termcap headers nonetheless don't
+ * declare tgoto, so we detect if that is missing separately.
+ */
+#ifdef TGOTO_PROTO_MISSING
+char *tgoto(const char *cap, int col, int row);
+#endif
+
 /* MISSING PROTOTYPES FOR VARIOUS OPERATING SYSTEMS */
 
 #if defined(__hpux) && defined(_HPUX_SOURCE) && !defined(_XPG4_EXTENDED)

$NetBSD: patch-Wnn_uum_sdefine.h,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/sdefine.h.orig	2001-06-14 18:16:08.000000000 +0000
+++ Wnn/uum/sdefine.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000
+ * Copyright FreeWnn Project 1999, 2000, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -33,6 +33,89 @@
  * define of standard i/o
  *************************/
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#include "commonhd.h"
+
+/* ncurses' term.h defines them to either 0 or 1! */
+#ifndef HAVE_TERMIOS_H
+#  define DONT_HAVE_TERMIOS_H
+#endif
+#ifndef HAVE_TERMIO_H
+#  define DONT_HAVE_TERMIO_H
+#endif
+#ifndef HAVE_SYS_TERMIO_H
+#  define DONT_HAVE_SYS_TERMIO_H
+#endif
+#ifndef HAVE_SGTTY_H
+#  define DONT_HAVE_SGTTY_H
+#endif
+
+#if defined(HAVE_TERMINFO)
+#  if defined(HAVE_CURSES_H)
+#    include <curses.h>
+#  elif defined(HAVE_NCURSES_H)
+#    include <ncurses.h>
+#  else
+#    error "no terminfo header"
+#  endif /* HAVE_CURSES_H */
+#  ifdef HAVE_TERM_H
+#    include <term.h>
+#  endif
+#else /* HAVE_TERMINFO */
+#  if defined(HAVE_TERMCAP_H)
+#    include <termcap.h>
+#  endif /* HAVE_TERMCAP_H */
+#endif /* HAVE_TERMINFO */
+
+#ifdef DONT_HAVE_TERMIOS_H
+#  undef HAVE_TERMIOS_H
+#  undef DONT_HAVE_TERMIOS_H
+#endif
+#ifdef DONT_HAVE_TERMIO_H
+#  undef HAVE_TERMIO_H
+#  undef DONT_HAVE_TERMIO_H
+#endif
+#ifdef DONT_HAVE_SYS_TERMIO_H
+#  undef HAVE_SYS_TERMIO_H
+#  undef DONT_HAVE_SYS_TERMIO_H
+#endif
+#ifdef DONT_HAVE_SGTTY_H
+#  undef HAVE_SGTTY_H
+#  undef DONT_HAVE_SGTTY_H
+#endif
+
+#ifdef HAVE_KILLPG
+# define KILLPG(pgrp, sig) killpg(pgrp, sig)
+#else
+# define KILLPG(pgrp, sig) kill(-(pgrp), sig)
+#endif /* HAVE_KILLPG */
+
+#if defined(HAVE_GETPGID)	/* SVR4 and most modern systems */
+#  define GETPGID(pid) getpgid(pid)
+#elif defined(HAVE_GETPGRP) && !defined(GETPGRP_VOID) /* 4.3BSD */
+#  define GETPGID(pid) getpgrp(pid)
+#elif defined(uniosu)
+#  define GETPGID(pid) ngetpgrp(pid)
+#else
+/* no way to get process group id */
+#endif /* GETPGID */
+
+#if defined(HAVE_GETPGRP)
+#  if defined(GETPGRP_VOID)
+#    define GETMYPGRP() getpgrp()	/* SYSV, POSIX */
+#  else
+#    define GETMYPGRP() getpgrp(0)
+#  endif /* !GETPGRP_VOID */
+#elif defined(GETPGID)
+#  define GETMYPGRP() GETPGID(getpid())
+#else
+/* probably some build error occured */
+#  error "don't know how to get my process group id"
+#endif /* GETMYPGRP */
+
 #define MAXCHG 80               /* 解析可能文字数 */
         /*漢字バッファ(次候補、単語検索など)の大きさ */
 #define MAX_ICHIRAN_KOSU 36     /* 一覧表示字の表示個数 */

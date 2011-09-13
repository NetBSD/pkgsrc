$NetBSD: patch-Wnn_conv_cvt__read.c,v 1.1 2011/09/13 07:23:16 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/conv/cvt_read.c.orig	2002-04-03 04:16:19.000000000 +0000
+++ Wnn/conv/cvt_read.c
@@ -10,9 +10,10 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2003, 2006
+ * Copyright Taketo Kabe 2003
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -52,16 +53,91 @@
 #if HAVE_FCNTL_H
 #  include <fcntl.h>
 #endif
+#ifdef HAVE_UNISTD_H
+#  include <unistd.h>
+#endif
 
-#include "cvt_head.h"
+/* Solaris 2.x needs termio.h , so include both. */
+#if HAVE_TERMIOS_H
+#  include <termios.h>
+#endif
+#if HAVE_TERMIO_H
+#  include <termio.h>
+#endif
+
+#if defined(HAVE_TERMIOS_H)
+/* #  include <termios.h> */
+#  define USE_TERMIOS 1
+#elif defined(HAVE_TERMIO_H)
+/* #  include <termio.h> */
+#  define USE_TERMIO  1
+#elif defined(HAVE_SYS_TERMIO_H)
+#  include <sys/termio.h>
+#  define USE_TERMIO  1
+#elif defined(HAVE_SGTTY_H)
+#  include <sgtty.h>
+#  define USE_SGTTY
+#else
+#  error "No termio header."
+#endif /* HAVE_TERMIOS_H */
 
-#ifdef SYSVR2
-#ifdef TERMINFO
-#include <curses.h>
-#endif /* TERMINFO */
-#include <term.h>
+#ifdef HAVE_TERMINFO
+#  define TERMINFO 1
+#else
+#  define TERMCAP  1
+#endif /* HAVE_TERMINFO */
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
 #endif
 
+#include "wnn_os.h"
+#include "cvt_head.h"
+
 #define ENTRY_LEN 10            /* コンバート表のエントリ名の最大長 */
 
 /*
@@ -455,6 +531,40 @@ convert_getstrs (flg)
   keydef_key[i++] = stradd (&tdataptr, key_f29);
   keydef_key[i++] = stradd (&tdataptr, key_f30);
   keydef_key[i++] = stradd (&tdataptr, key_f31);
+# ifndef uniosu
+  keydef_key[i++] = stradd (&tdataptr, key_f32);
+  keydef_key[i++] = stradd (&tdataptr, key_f33);
+  keydef_key[i++] = stradd (&tdataptr, key_f34);
+  keydef_key[i++] = stradd (&tdataptr, key_f35);
+  keydef_key[i++] = stradd (&tdataptr, key_f36);
+  keydef_key[i++] = stradd (&tdataptr, key_f37);
+  keydef_key[i++] = stradd (&tdataptr, key_f38);
+  keydef_key[i++] = stradd (&tdataptr, key_f39);
+  keydef_key[i++] = stradd (&tdataptr, key_f40);
+  keydef_key[i++] = stradd (&tdataptr, key_f41);
+  keydef_key[i++] = stradd (&tdataptr, key_f42);
+  keydef_key[i++] = stradd (&tdataptr, key_f43);
+  keydef_key[i++] = stradd (&tdataptr, key_f44);
+  keydef_key[i++] = stradd (&tdataptr, key_f45);
+  keydef_key[i++] = stradd (&tdataptr, key_f46);
+  keydef_key[i++] = stradd (&tdataptr, key_f47);
+  keydef_key[i++] = stradd (&tdataptr, key_f48);
+  keydef_key[i++] = stradd (&tdataptr, key_f49);
+  keydef_key[i++] = stradd (&tdataptr, key_f50);
+  keydef_key[i++] = stradd (&tdataptr, key_f51);
+  keydef_key[i++] = stradd (&tdataptr, key_f52);
+  keydef_key[i++] = stradd (&tdataptr, key_f53);
+  keydef_key[i++] = stradd (&tdataptr, key_f54);
+  keydef_key[i++] = stradd (&tdataptr, key_f55);
+  keydef_key[i++] = stradd (&tdataptr, key_f56);
+  keydef_key[i++] = stradd (&tdataptr, key_f57);
+  keydef_key[i++] = stradd (&tdataptr, key_f58);
+  keydef_key[i++] = stradd (&tdataptr, key_f59);
+  keydef_key[i++] = stradd (&tdataptr, key_f60);
+  keydef_key[i++] = stradd (&tdataptr, key_f61);
+  keydef_key[i++] = stradd (&tdataptr, key_f62);
+  keydef_key[i++] = stradd (&tdataptr, key_f63);
+# endif /* !uniosu */
 #endif /* SUPPORT_TWODIGIT_FUNCTIONS */
 /* 以下順に
         "kcuu1", "kcuf1", "kcub1", "kcud1", "khome",

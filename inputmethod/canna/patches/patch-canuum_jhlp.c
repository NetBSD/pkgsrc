$NetBSD: patch-canuum_jhlp.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Pull various fixes include support for openpty(3), posix_openpt(3),
and ptsname(3) etc. from the latest FreeWnn-1.1.1-a023

--- canuum/jhlp.c.orig	2004-04-26 21:48:37.000000000 +0000
+++ canuum/jhlp.c
@@ -11,9 +11,11 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2003, 2006, 2009, 2013
+ * Copyright Canna Project 2002
+ * Copyright Taketo Kabe 2003
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -31,7 +33,7 @@
  */
 
 #ifndef lint
-static char *rcs_id = "jhlp.c,v 1.13 2002/08/26 09:27:21 aono Exp";
+static char *rcs_id = "jhlp.c,v 1.26 2013/09/02 11:01:40 itisango Exp";
 #endif /* lint */
 
 #ifdef HAVE_CONFIG_H
@@ -39,6 +41,7 @@ static char *rcs_id = "jhlp.c,v 1.13 200
 #endif
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <setjmp.h>
 #include <signal.h>
 #if STDC_HEADERS
@@ -54,12 +57,20 @@ static char *rcs_id = "jhlp.c,v 1.13 200
 #endif /* STDC_HEADERS */
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/stat.h>
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif
-#include <sys/stat.h>
-#include <sys/time.h>
-#include <sys/types.h>
+#if TIME_WITH_SYS_TIME
+#  include <sys/time.h>
+#  include <time.h>
+#else
+#  if HAVE_SYS_TIME_H
+#    include <sys/time.h>
+#  else
+#    include <time.h>
+#  endif /* HAVE_SYS_TIME_H */
+#endif /* TIME_WITH_SYS_TIME */
 #if HAVE_FCNTL_H
 #  include <fcntl.h>
 #endif
@@ -67,56 +78,68 @@ static char *rcs_id = "jhlp.c,v 1.13 200
 #ifdef HAVE_UNISTD_H
 #  include <unistd.h>
 #endif
+#if HAVE_SYS_WAIT_H
+#  include <sys/wait.h>
+#endif
+#ifdef HAVE_LIBUTIL_H
+#  include <libutil.h>
+#endif
+#ifdef HAVE_UTIL_H
+#include <util.h>
+#endif
 #ifdef UX386
 #include <sys/kdef.h>
 #endif
 
-#include "commonhd.h"
-#include "sdefine.h"
-#include "sheader.h"
-#include "wnn_config.h"
-#include "wnn_os.h"
-
-
-jmp_buf kk_env;
-
-
-#ifdef HAVE_WAIT3
-#       include <sys/wait.h>
-#endif /* HAVE_WAIT3 */
-
-#ifdef USE_LIBSPT
-# include <libspt.h>
+/* Solaris 2.x needs termio.h , so include both. */
+#if HAVE_TERMIOS_H
+#  include <termios.h>
+#endif
+#if HAVE_TERMIO_H
+#  include <termio.h>
 #endif
 
 #if defined(HAVE_TERMIOS_H)
-# include <termios.h>
-# define USE_TERMIOS
+/* #  include <termios.h> */
+#  define USE_TERMIOS 1
 #elif defined(HAVE_TERMIO_H)
-# include <termio.h>
-# define USE_TERMIO
+/* #  include <termio.h> */
+#  define USE_TERMIO  1
 #elif defined(HAVE_SYS_TERMIO_H)
-# include <sys/termio.h>
-# define USE_TERMIO
+#  include <sys/termio.h>
+#  define USE_TERMIO  1
 #elif defined(HAVE_SGTTY_H)
-# include <sgtty.h>
-# define USE_SGTTY
+#  include <sgtty.h>
+#  define USE_SGTTY
 #else
-# error "No termio header."
-#endif
+#  error "No termio header."
+#endif /* HAVE_TERMIOS_H */
 
-#ifdef linux
-/* # define USE_LINUX_TERM */
+#ifdef USE_LIBSPT
+#  include <libspt.h>
 #endif
 
+/*
+ * Enable old Linux specific code.
+ * We hope you don't have to use this #define ...
+ * (We will remove this #define and related code in near future.)
+ */
+/* #define USE_LINUX_TERM */
+
+
+#include "sdefine.h"
+
+#include "commonhd.h"
+#include "sheader.h"
+#include "wnn_config.h"
+#include "wnn_os.h"
+
 #ifdef nec_ews_svr2
-#include <sys/jtermio.h>
+#  include <sys/jtermio.h>
 #endif /* nec_ews_svr2 */
-
 #if defined(uniosu)
 #       include <sys/pty.h>
 #endif /* defined(uniosu) */
-
 #ifdef SVR4
 #include <sys/stropts.h>
 #include <sys/euc.h>
@@ -132,11 +155,12 @@ jmp_buf kk_env;
 
 #define ERROR -1
 
+jmp_buf kk_env;
 #ifdef TIOCSSIZE
 struct ttysize pty_rowcol;
 #endif /* TIOCSSIZE */
 
-int ttyfd;
+int ttyfd;			/* master tty */
 
 char *tname;                    /* terminal name */
 char *cmdnm = "csh";            /* char *cmdnm = "csh"; */
@@ -145,28 +169,33 @@ int child_id;
 char *prog;
 #ifdef USE_LIBSPT
 spt_handle *spth = NULL;
-int need_utmp_clear = 0;
 #endif
+int need_utmp_clear = 0;
 
-extern char *optarg;
-extern int optind;
-
-extern char *ttyname ();
-
-static void save_signals ();
-static void restore_signals ();
-
-static RETSIGTYPE terminate_handler ();
-static void do_end (), open_pty (), open_ttyp (), do_main (), exec_cmd (), parse_options (), setsize (), get_rubout (), usage (), change_size (), default_usage ();
-static void j_term_save (), j_term_restore (), j_term_p_init (int);
+static void save_signals (void);
+static void restore_signals (void);
+static RETSIGTYPE terminate_handler (int);
+static void do_end (void);
+static void open_pty (void);
+static void open_pty_traditional (void);
+static void open_ttyp (void);
+static void do_main (void);
+static void exec_cmd (char **);
+static void parse_options (int, char **);
+static void setsize (void);
+static void get_rubout (void);
+static void usage (char *);
+static void change_size (void);
+static void default_usage (void);
+static void j_term_save (void);
+static void j_term_restore (void);
+static void j_term_p_init (int);
+static unsigned char keyin0 (void);
+static void uum_err (char *);
 
-/** メイン */
 int
-main (argc, argv)
-     int argc;
-     char **argv;
+main (int argc, char **argv)
 {
-
   char *name;
   char *p;
   char nlspath[64];
@@ -174,7 +203,7 @@ main (argc, argv)
   char *server_env;
   char errprefix[1024] = "error";
   int i;
-  extern char *get_server_env ();
+  extern char *get_server_env (char *);
 
   prog = argv[0];
   flow_control = FLOW_CONTROL;
@@ -344,7 +373,7 @@ main (argc, argv)
     }
 
   j_term_save ();
-  /* do_end() is allowed after here */
+  /* do_end () is allowed from here */
   save_signals ();
 
 #ifdef TERMCAP
@@ -377,6 +406,9 @@ main (argc, argv)
 
   ttyfd = 0;
   open_pty ();
+/* It is normal to open tty here, before fork().
+   Don't know why linux is different.
+   So temporally comment it out to make it as other OSes. */
 #ifndef USE_LINUX_TERM
   open_ttyp ();
 #endif
@@ -387,7 +419,7 @@ main (argc, argv)
   switch (init_uum ())
     {                           /* initialize of kana-kanji henkan */
     case -1:
-      terminate_handler ();
+      terminate_handler (-1);
       break;
     case -2:
       epilogue ();
@@ -399,7 +431,7 @@ main (argc, argv)
 
   if (j_term_init () == ERROR)
     {
-      err ("term initialize fault.");
+      uum_err ("term initialize fault.");
     }
 
 #ifndef CANNA
@@ -415,7 +447,7 @@ main (argc, argv)
         }
       flush ();
     }
-#endif /* !CANNA */
+#endif /* CANNA */
 
   puteustring (MSG_GET (1),
                /*
@@ -434,6 +466,7 @@ main (argc, argv)
 #endif /* defined(uniosu) */
 
   do_main ();
+  return 0;
 }
 
 /*
@@ -441,7 +474,7 @@ main (argc, argv)
  */
 
 static int
-do_h_opt ()
+do_h_opt (void)
 {
   henkan_off_flag = 1;
   defined_by_option |= OPT_WAKING_UP_MODE;
@@ -449,7 +482,7 @@ do_h_opt ()
 }
 
 static int
-do_H_opt ()
+do_H_opt (void)
 {
   henkan_off_flag = 0;
   defined_by_option |= OPT_WAKING_UP_MODE;
@@ -458,42 +491,42 @@ do_H_opt ()
 
 #ifdef  JAPANESE
 int
-do_u_opt ()
+do_u_opt (void)
 {
   pty_c_flag = J_EUJIS;
   return 0;
 }
 
 int
-do_j_opt ()
+do_j_opt (void)
 {
   pty_c_flag = J_JIS;
   return 0;
 }
 
 int
-do_s_opt ()
+do_s_opt (void)
 {
   pty_c_flag = J_SJIS;
   return 0;
 }
 
 int
-do_U_opt ()
+do_U_opt (void)
 {
   tty_c_flag = J_EUJIS;
   return 0;
 }
 
 int
-do_J_opt ()
+do_J_opt (void)
 {
   tty_c_flag = J_JIS;
   return 0;
 }
 
 int
-do_S_opt ()
+do_S_opt (void)
 {
   tty_c_flag = J_SJIS;
   return 0;
@@ -502,28 +535,28 @@ do_S_opt ()
 
 #ifdef  CHINESE
 int
-do_b_opt ()
+do_b_opt (void)
 {
   pty_c_flag = C_BIG5;
   return 0;
 }
 
 int
-do_t_opt ()
+do_t_opt (void)
 {
   pty_c_flag = C_ECNS11643;
   return 0;
 }
 
 int
-do_B_opt ()
+do_B_opt (void)
 {
   tty_c_flag = C_BIG5;
   return 0;
 }
 
 int
-do_T_opt ()
+do_T_opt (void)
 {
   tty_c_flag = C_ECNS11643;
   return 0;
@@ -532,14 +565,14 @@ do_T_opt ()
 
 #ifdef KOREAN
 int
-do_u_opt ()
+do_u_opt (void)
 {
   pty_c_flag = K_EUKSC;
   return 0;
 }
 
 int
-do_U_opt ()
+do_U_opt (void)
 {
   tty_c_flag = K_EUKSC;
   return 0;
@@ -547,14 +580,14 @@ do_U_opt ()
 #endif /* KOREAN */
 
 static int
-do_P_opt ()
+do_P_opt (void)
 {
   sleep (20);
   return 0;
 }
 
 static int
-do_x_opt ()
+do_x_opt (void)
 {
   flow_control = 0;
   defined_by_option |= OPT_FLOW_CTRL;
@@ -562,7 +595,7 @@ do_x_opt ()
 }
 
 static int
-do_X_opt ()
+do_X_opt (void)
 {
   flow_control = 1;
   defined_by_option |= OPT_FLOW_CTRL;
@@ -570,7 +603,7 @@ do_X_opt ()
 }
 
 static int
-do_k_opt ()
+do_k_opt (void)
 {
   strncpy(uumkey_name_in_uumrc, optarg, PATHNAMELEN-1);
   uumkey_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -583,7 +616,7 @@ do_k_opt ()
 }
 
 static int
-do_c_opt ()
+do_c_opt (void)
 {
   strncpy(convkey_name_in_uumrc, optarg, PATHNAMELEN-1);
   convkey_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -596,7 +629,7 @@ do_c_opt ()
 }
 
 static int
-do_r_opt ()
+do_r_opt (void)
 {
   strncpy(rkfile_name_in_uumrc, optarg, PATHNAMELEN-1);
   rkfile_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -609,14 +642,14 @@ do_r_opt ()
 }
 
 static int
-do_l_opt ()
+do_l_opt (void)
 {
   conv_lines = atoi (optarg);
   return 0;
 }
 
 static int
-do_D_opt ()
+do_D_opt (void)
 {
   strncpy(def_servername, optarg, PATHNAMELEN-1);
   def_servername[PATHNAMELEN-1] = '\0';
@@ -629,7 +662,7 @@ do_D_opt ()
 }
 
 static int
-do_n_opt ()
+do_n_opt (void)
 {
   strncpy(username, optarg, PATHNAMELEN-1);
   username[PATHNAMELEN-1] = '\0';
@@ -641,13 +674,13 @@ do_n_opt ()
 }
 
 static int
-do_v_opt ()
+do_v_opt (void)
 {
   defined_by_option |= OPT_VERBOSE;
   return 0;
 }
 
-static int (*do_opt[]) () =
+static int (*do_opt[]) (void) =
 {
   do_h_opt,                     /* 'h' : waking_up_in_henkan_mode */
     do_H_opt,                   /* 'H' : waking_up_no_henkan_mode */
@@ -693,43 +726,31 @@ parse_options (argc, argv)
 /** tty に対する ioctl のセット */
 
 #ifdef USE_SGTTY
-#if defined(BSD43) || defined(DGUX) /* should be "defined(LPASS8)"? */
-#  define SET_PASS8
-#endif
+#  if defined(BSD43) || defined(DGUX) /* should be "defined(LPASS8)"? */
+#    define SET_PASS8  1
+#  endif
+
 struct sgttyb savetmio;
-struct sgttyb ttyb_def =
-{ B9600, B9600, 0x7f, 0x15, EVENP | ODDP | ECHO | CRMOD };
+struct sgttyb ttyb_def = { B9600, B9600, 0x7f, 0x15,
+			   EVENP | ODDP | ECHO | CRMOD };
 int local_mode_def = LCRTBS | LCRTERA | LCRTKIL | LCTLECH | LPENDIN | LDECCTQ;
-
 /* added later */
 struct tchars tcharsv;
 struct ltchars ltcharsv;
 struct sgttyb ttyb;
 int local_mode;
-#ifdef SET_PASS8
+#  ifdef SET_PASS8
 static int local_mode_sv;
-#endif
-
+#  endif
 
 static void
-get_rubout ()
+get_rubout (void)
 {
-#ifdef nodef
-  if (savetmio.sg_erase == UNDEF_STTY)
-    {
-      rubout_code = RUBOUT;
-    }
-  else
-    {
-#endif
-      rubout_code = savetmio.sg_erase;
-#ifdef nodef
-    }
-#endif
+  rubout_code = savetmio.sg_erase;
 }
 
 int
-j_term_init ()
+j_term_init (void)
 {
   struct sgttyb buf;
 
@@ -737,43 +758,42 @@ j_term_init ()
   buf.sg_flags |= RAW;
   buf.sg_flags &= ~ECHO;
   ioctl (ttyfd, TIOCSETP, &buf);
-#ifdef SET_PASS8
+#  ifdef SET_PASS8
   ioctl (ttyfd, TIOCLSET, &local_mode);
-#endif
+#  endif
 
   return 0;
 }
 
 static void
-j_term_save ()
+j_term_save (void)
 {
   ioctl (ttyfd, TIOCGETC, &tcharsv);
   ioctl (ttyfd, TIOCGLTC, &ltcharsv);
   if (ioctl (ttyfd, TIOCGETP, &ttyb))
     ttyb = ttyb_def;
   savetmio = ttyb;
-#ifdef SET_PASS8
+#  ifdef SET_PASS8
   if (ioctl (ttyfd, TIOCLGET, &local_mode_sv))
     local_mode_sv = local_mode_def;
-  local_mode = local_mode_sv | LPASS8;  /* set PASS8 */
-#else /* !SET_PASS8 */
+  local_mode = local_mode_sv | LPASS8;	/* set PASS8 */
+#  else  /* !SET_PASS8 */
   if (ioctl (ttyfd, TIOCLGET, &local_mode))
     local_mode = local_mode_def;
-#endif /* !SET_PASS8 */
+#  endif /* !SET_PASS8 */
 }
 
 static void
-j_term_restore ()
+j_term_restore (void)
 {
   ioctl (ttyfd, TIOCSETP, &savetmio);
-#ifdef SET_PASS8
+#  ifdef SET_PASS8
   ioctl (ttyfd, TIOCLSET, &local_mode_sv);
-#endif /* SET_PASS8 */
+#  endif /* SET_PASS8 */
 }
 
 static void
-j_term_p_init (ttypfd)
-  int ttypfd;
+j_term_p_init (int ttypfd)
 {
   int word;
   ioctl (ttypfd, TIOCSETC, &tcharsv);
@@ -791,35 +811,33 @@ j_term_p_init (ttypfd)
 #if defined(USE_TERMIO) || defined(USE_TERMIOS)
 
 #ifdef USE_TERMIOS
-# define TERMIO termios
-# define GET_TERMATTR(fd, tio) tcgetattr(fd, tio)
-# define SET_TERMATTR(fd, tio) tcsetattr(fd, TCSADRAIN, tio)
-# define UNDEF_STTY _POSIX_VDISABLE
-# define SET_ATTR_ERROR "error in tcsetattr.\n"
-#else
-# define TERMIO termio
-# define GET_TERMATTR(fd, tio) ioctl(fd, TCGETA, tio)
-# ifdef TCSETAW
-#  define SET_TERMATTR(fd, tio) ioctl(fd, TCSETAW, tio)
-# else
-#  define SET_TERMATTR(fd, tio) ioctl(fd, TCSETA, tio)
-# endif
-# define UNDEF_STTY 0xff
-# define SET_ATTR_ERROR "error in ioctl TCSETA.\n"
-#endif
+#  define TERMIO termios
+#  define GET_TERMATTR(fd, tio) tcgetattr(fd, tio)
+#  define SET_TERMATTR(fd, tio) tcsetattr(fd, TCSADRAIN, tio)
+#  define UNDEF_STTY _POSIX_VDISABLE
+#  define SET_ATTR_ERROR "error in tcsetattr.\n"
+#else /* !USE_TERMIOS */
+#  define TERMIO termio
+#  define GET_TERMATTR(fd, tio) ioctl(fd, TCGETA, tio)
+#  ifdef TCSETAW
+#    define SET_TERMATTR(fd, tio) ioctl(fd, TCSETAW, tio)
+#    define SET_ATTR_ERROR "error in ioctl TCSETAW.\n"
+#  else
+#    define SET_TERMATTR(fd, tio) ioctl(fd, TCSETA, tio)
+#    define SET_ATTR_ERROR "error in ioctl TCSETA.\n"
+#  endif
+#  define UNDEF_STTY 0xff
+#endif /* !USE_TERMIOS */
 #ifdef CERASE
-# define WNN_CERASE CERASE
-#elif defined(CDEL)
-# define WNN_CERASE CDEL
+#  define WNN_CERASE CERASE
 #else
-# define WNN_CERASE 0x7f
+#  define WNN_CERASE 0x7f
 #endif
 
 struct TERMIO savetmio;
 
 static void
-set_default_termio (terms)
-  struct TERMIO *terms;
+set_default_termio (struct TERMIO *terms)
 {
   bzero (terms, sizeof *terms);
   terms->c_iflag = IGNBRK | ICRNL | IXON;
@@ -839,12 +857,12 @@ set_default_termio (terms)
   terms->c_cc[VKILL] = 0x15;
   terms->c_cc[VEOF] = 0x4;
   terms->c_cc[VEOL] = _POSIX_VDISABLE;
-#ifdef VEOL2
+#  ifdef VEOL2
   terms->c_cc[VEOL2] = _POSIX_VDISABLE;
-#endif
+#  endif
   cfsetospeed (terms, B9600);
   cfsetispeed (terms, B9600);
-#else
+#else /* !USE_TERMIOS */
   terms->c_line = 0;
   terms->c_cc[0] = 0x3;
   terms->c_cc[1] = 0x1c;
@@ -854,7 +872,7 @@ set_default_termio (terms)
   terms->c_cc[5] = 0;
   terms->c_cc[6] = 0;
   terms->c_cc[7] = 0;
-#endif
+#endif /* !USE_TERMIOS */
 }
 
 #if defined(uniosu)
@@ -866,7 +884,7 @@ struct auxtermio auxterm = {
 #endif /* defined(uniosu) */
 
 static void
-get_rubout ()
+get_rubout (void)
 {
   if (savetmio.c_cc[VERASE] == UNDEF_STTY)
     {
@@ -879,7 +897,7 @@ get_rubout ()
 }
 
 int
-j_term_init ()
+j_term_init (void)
 {
   struct TERMIO buf1;
 #if defined(uniosu)
@@ -887,33 +905,37 @@ j_term_init ()
 #endif /* defined(uniosu) */
 
   buf1 = savetmio;
-#ifdef USE_LINUX_TERM
+#ifdef linux
   buf1.c_lflag &= ~(ECHONL | ECHOK | ECHOE | ECHO | XCASE | ICANON | ISIG);
   buf1.c_iflag = 0;
   buf1.c_oflag &= ~OPOST;
   buf1.c_cflag |= CS8;
   buf1.c_cc[VMIN] = 1;          /* cf. ICANON */
   buf1.c_cc[VTIME] = 0;
-#else /* !USE_LINUX_TERM */
+  buf1.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IUCLC | IXON);
+#else /* !linux */
   buf1.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IXON);
-#ifdef IUCLC
-  buf1.c_iflag &= IUCLC;
-#endif
+#  ifdef IUCLC
+  buf1.c_iflag &= ~(IUCLC);
+#  endif
   if (flow_control)
     {
       buf1.c_iflag |= IXON;
     }
   buf1.c_lflag &= ~(ECHONL | ECHOK | ECHOE | ECHO | ICANON | ISIG);
-#ifdef XCASE
-  buf1.c_lflag &= XCASE;
-#endif
+#  ifdef XCASE
+  buf1.c_lflag &= ~(XCASE);
+#  endif
+#  ifdef IEXTEN
+  buf1.c_lflag &= ~(IEXTEN);
+#  endif
   buf1.c_oflag = OPOST;
-#ifdef USE_TERMIOS
-  buf1.c_cc[VMIN] = 1;          /* cf. ICANON */
+#  ifdef USE_TERMIOS
+  buf1.c_cc[VMIN] = 1;
   buf1.c_cc[VTIME] = 0;
   cfsetispeed(&buf1, cfgetispeed(&savetmio));
   cfsetospeed(&buf1, cfgetospeed(&savetmio));
-#else /* !USE_TERMIOS */
+#  else /* !USE_TERMIOS */
   buf1.c_cc[VEOF] = 1;          /* cf. ICANON */
   buf1.c_cc[VEOL] = 0;
   /* not needed? cf.ISIG*/
@@ -921,8 +943,8 @@ j_term_init ()
   buf1.c_cc[VQUIT] = WNN_CERASE;
   buf1.c_cc[VERASE] = WNN_CERASE;
   buf1.c_cc[VKILL] = WNN_CERASE;
-#endif /* !USE_TERMIOS */
-#endif /* !USE_LINUX_TERM */
+#  endif /* !USE_TERMIOS */
+#endif /* !linux */
   if (SET_TERMATTR (ttyfd, &buf1) < 0)
     {
       fprintf (stderr, SET_ATTR_ERROR);
@@ -979,12 +1001,12 @@ j_term_init ()
 }
 
 static void
-j_term_save ()
+j_term_save (void)
 {
   if (GET_TERMATTR (ttyfd, &savetmio) < 0)
-    {
-      set_default_termio (&savetmio);
-    }
+  {
+    set_default_termio (&savetmio);
+  }
 #if defined(uniosu)
   if (ioctl (ttyfd, JTERMGET, &savejtmio) < 0)
     {
@@ -995,7 +1017,7 @@ j_term_save ()
 }
 
 static void
-j_term_restore ()
+j_term_restore (void)
 {
   if (SET_TERMATTR (ttyfd, &savetmio) < 0)
     {
@@ -1013,8 +1035,7 @@ j_term_restore ()
 }
 
 static void
-j_term_p_init (ttypfd)
-  int ttypfd;
+j_term_p_init (int ttypfd)
 {
   struct TERMIO buf1;
 #if defined(uniosu)
@@ -1094,20 +1115,18 @@ j_term_p_init (ttypfd)
 #endif /* USE_TERMIO || USE_TERMIOS */
 
 /** signal SIGCHLD を受けた後の処理をする。*/
-/* *INDENT-OFF* */
 RETSIGTYPE
-chld_handler ()
-/* *INDENT-ON* */
+chld_handler (int sig)
 {
 #ifdef HAVE_WAIT3
-#if !defined(_POSIX_VERSION) && defined(HAVE_UNION_WAIT) /* older way */
+#if !defined(_POSIX_VERSION) && defined(HAVE_UNION_WAIT)
   union wait status;
 #else /* POSIX */
   int status;
 #endif
   int pid;
 
-  if ((pid = wait3(&status, WNOHANG | WUNTRACED, NULL)) == child_id)
+  if ((pid = wait3 (&status, WNOHANG | WUNTRACED, NULL)) == child_id)
     {
       if (WIFSTOPPED (status))
         {
@@ -1156,7 +1175,7 @@ chld_handler ()
 
 /** signal SIGTERM を受けた時の処理をする。*/
 static RETSIGTYPE
-terminate_handler ()
+terminate_handler (int sig)
 {
   signal (SIGCHLD, SIG_IGN);
   epilogue_no_close ();
@@ -1169,10 +1188,8 @@ terminate_handler ()
 }
 
 #ifdef  SIGWINCH
-/* *INDENT-OFF* */
 RETSIGTYPE
-resize_handler ()
-/* *INDENT-ON* */
+resize_handler (int sig)
 {
   re_signal (SIGWINCH, resize_handler);
   change_size ();
@@ -1187,10 +1204,10 @@ resize_handler ()
 /** メインループ */
 
 wnn_fd_set sel_ptn;
-int ptyfd = -1;
+int ptyfd;
 
 static void
-do_main ()
+do_main (void)
 {
 #ifndef CANNA
   unsigned char *buf;
@@ -1206,10 +1223,11 @@ do_main ()
       epilogue ();
       do_end ();
     }
-#else /* CANNA */
-  extern void canna_mainloop();
+#else  /* CANNA */
+  extern void canna_mainloop(void);
 #endif /* CANNA */
 
+  WNN_FD_ZERO (&sel_ptn);
   WNN_FD_SET(ptyfd, &sel_ptn);
   WNN_FD_SET(ttyfd, &sel_ptn);
 
@@ -1221,23 +1239,19 @@ do_main ()
 #ifndef CANNA
   for (;;)
     {
-
       ml = kk ();
-
       make_history (return_buf, ml);
       ml = (*code_trans[(internal_code << 2) | pty_c_flag]) (buf, return_buf, sizeof (w_char) * ml);
       if (ml > 0)
         write (ptyfd, buf, ml);
     }
-#else /* CANNA */
+#else  /* CANNA */
   canna_mainloop();
 #endif /* CANNA */
 }
 
-unsigned char keyin0 ();
-
 int
-keyin2 ()
+keyin2 (void)
 {
   int total, ret;
   unsigned char in;
@@ -1259,15 +1273,14 @@ keyin2 ()
 
 /** convert_key nomi okonau key-in function */
 int
-conv_keyin (inkey)
-     char *inkey;
+conv_keyin (char *inkey)
 {
   return keyin1 (keyin2, inkey);
 }
 
 /** キー入力関数 1 */
 int
-keyin ()
+keyin (void)
 {
   char inkey[16];
   return (conv_keyin (inkey));
@@ -1280,10 +1293,7 @@ keyin ()
  */
 
 static void
-throughlike(dest, src, n)
-w_char *dest;
-unsigned char *src;
-int n;
+throughlike(w_char *dest, unsigned char *src, int n)
 {
   while (n-- > 0) {
     *dest++ = (w_char)*src++;
@@ -1291,8 +1301,8 @@ int n;
 }
 
 /** キー入力関数 2 */
-unsigned char
-keyin0 ()
+static unsigned char
+keyin0 (void)
 {
   static unsigned char buf[BUFSIZ];
   static unsigned char outbuf[BUFSIZ];
@@ -1341,7 +1351,7 @@ keyin0 ()
       time_out.tv_sec = 0;
       time_out.tv_usec = 200 * 1000;    /* 200 msec 間待つのだゾ! */
       for (rfds = sel_ptn;
-#ifdef USE_LINUX_TERM
+#ifdef linux
            (sel_ret = select (20, &rfds, 0, 0, NULL)) < 0 && errno == EINTR;
 #else
            (sel_ret = select (20, &rfds, 0, 0, &time_out)) < 0 && errno == EINTR;
@@ -1392,7 +1402,8 @@ keyin0 ()
                       p += j;
                       i -= j;
                     }
-		  WNN_FD_SET(ttyfd, &mask);
+		  WNN_FD_ZERO (&mask);
+		  WNN_FD_SET (ttyfd, &mask);
                   select (32, 0, &mask, 0, 0);
                 }
               pop_cursor ();
@@ -1439,8 +1450,8 @@ keyin0 ()
 #if defined(uniosu)
 /** pty から ioctl がかかった時の処理 */
 int
-arrange_ioctl (jflg)
-     int jflg;                  /* jtermio の j_flg の変換フラグがオフの時 0 オンの時 1 */
+arrange_ioctl (int jflg)
+/* jflg: jtermio の j_flg の変換フラグがオフの時 0 オンの時 1 */
 {
   struct jtermio jbuf1;
   struct TERMIO frombuf;
@@ -1511,11 +1522,10 @@ arrange_ioctl (jflg)
 
 /** 子プロセスを起こす。*/
 
-int ttypfd = -1;
+int ttypfd = -1;	/* slave tty */
 
 static void
-exec_cmd (argv)
-     char **argv;
+exec_cmd (char **argv)
 {
   int i;
 #if defined(USE_LIBSPT) && !defined(USE_LINUX_TERM)
@@ -1525,21 +1535,20 @@ exec_cmd (argv)
 #ifdef BSD42
   int pid;
 #endif
-#ifdef USE_LINUX_TERM
+#endif /* (!USE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
+#if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
   struct winsize win;
-  extern Term_RowWidth, crow;
+  extern int Term_RowWidth;
 #endif
-#endif /* (!USE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
 
   child_id = fork ();
   if (child_id < 0)
-    err ("cannot fork.");
+    uum_err ("cannot fork.");
   if (!child_id)
     {
       /* --- start changing controlling tty --- */
 #if defined(USE_LIBSPT) && !defined(USE_LINUX_TERM)
 #if defined(SIGWINCH) && defined(TIOCSWINSZ)
-      struct winsize win;
       if (ioctl (ttyfd, TIOCGWINSZ, &win) == 0)
 	ioctl (ttypfd, TIOCSWINSZ, &win);
 #endif /* SIGWINCH && TIOCSWINSZ */
@@ -1547,37 +1556,31 @@ exec_cmd (argv)
       spth = NULL;
       if (spt_detach_ctty () || spt_set_ctty2 (ttypfd))
 	{
-	  err ("cannot change controlling tty.");
+	  uum_err ("cannot change controlling tty.");
 	}
 
 #elif defined(HAVE_SETSID) && !defined(USE_LINUX_TERM) /* !USE_LIBSPT */
 
       int fd;
-#if defined(SIGWINCH) && defined(TIOCSWINSZ)
-      struct winsize win;
+# if defined(SIGWINCH) && defined(TIOCSWINSZ)
       if (ioctl (ttyfd, TIOCGWINSZ, &win) == 0)
 	ioctl (ttypfd, TIOCSWINSZ, &win);
-#endif /* SIGWINCH && TIOCSWINSZ */
+# endif /* SIGWINCH && TIOCSWINSZ */
       setsid ();
-#ifdef TIOCSCTTY
+# ifdef TIOCSCTTY
       ioctl (ttypfd, TIOCSCTTY, 0);
-#else
+# else
       close (open (ttyname (ttypfd), O_WRONLY, 0));
-#endif
+# endif
       if ((fd = open("/dev/tty", O_WRONLY)) < 0)
 	{
-          err ("cannot change controlling tty.");
+	  uum_err ("cannot change controlling tty.");
 	}
       close (fd);
       /* disable utmp logging for now */
 
 #else /* (!USE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
 
-#if defined(SYSVR2) && !defined(USE_LINUX_TERM)
-      setpgrp ();
-      close (open (ttyname (ttypfd), O_WRONLY, 0));
-#endif /* SYSVR2 */
-
 #ifdef BSD42
 #ifdef TIOCNOTTY
       /* set notty */
@@ -1601,18 +1604,28 @@ exec_cmd (argv)
       close (open (ttyname (ttypfd), O_WRONLY, 0));
       setpgrp (0, pid);
 #endif /* BSD42 */
+#if defined(SYSVR2) && !defined(linux)
+      setpgrp (); /* should setpgrp() AFTER fork() */
+      close (open (ttyname (ttypfd), O_WRONLY, 0));
+#endif /* SYSVR2 */
 
-#ifdef USE_LINUX_TERM
+/* It is bizarre to open tty after fork().
+   So, try to do same as other os.
+   If it does work, we can remove this. */
+# ifdef linux
       setsid ();
       open_ttyp ();
       close (ptyfd);
-      ioctl (ttyfd, TIOCGWINSZ, &win);
       ioctl (ttypfd, TCSETA, &savetmio);
-#endif
+# endif
+# if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
+      ioctl (ttyfd, TIOCGWINSZ, &win);
+# endif
+
 #endif /* (!USE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
       /* --- finish changing controlling tty --- */
 
-#ifndef USE_LINUX_TERM
+#ifndef linux
       setgid (getgid ());
       setuid (getuid ());
 #endif
@@ -1626,7 +1639,7 @@ exec_cmd (argv)
       close (2);
       if (dup (ttypfd) != 0 || dup (ttypfd) != 1 || dup (ttypfd) != 2)
         {
-          err ("redirection fault.");
+          uum_err ("redirection fault.");
         }
 #endif /* !HAVE_DUP2 */
       for (i = WNN_NFD - 1; i > 2; i--)
@@ -1646,15 +1659,18 @@ exec_cmd (argv)
       signal (SIGTTOU, SIG_IGN);
 #endif
 
-#ifdef USE_LINUX_TERM
+#if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
       crow = win.ws_row = Term_RowWidth = win.ws_row - conv_lines;
       ioctl (ttyfd, TIOCSWINSZ, &win);
+#endif
+#ifdef linux
       setgid (getgid ());
       setuid (getuid ());
 #endif
       execvp (cmdnm, argv);
-      err ("exec fault.");
+      uum_err ("exec fault.");
     }
+
   /* parent */
 #ifdef USE_LIBSPT
   ttynm = ttyname (0);
@@ -1676,7 +1692,7 @@ exec_cmd (argv)
     {
       spt_perror ("exec_cmd (login_utmp)", r);
     }
-#endif
+#endif /* USE_LIBSPT */
 }
 
 #if !(HAVE_SETENV)
@@ -1687,10 +1703,7 @@ exec_cmd (argv)
  * The 3rd parameter is ignored. It is added for compatibility only.
  */
 int
-setenv (var, value, overwrite)
-     char *var;
-     char *value;
-     int  overwrite;
+setenv (char *var, char *value, int overwrite)
 {
   extern char **environ;
   char **newenv;
@@ -1730,9 +1743,7 @@ setenv (var, value, overwrite)
 
 #ifdef SVR4
 static int
-euc_set (eucioc, ttyfd)
-     eucioc_t *eucioc;
-     int ttyfd;
+euc_set (eucioc_t *eucioc, int ttyfd)
 {
   struct strioctl sb;
 
@@ -1747,9 +1758,8 @@ euc_set (eucioc, ttyfd)
   return (0);
 }
 
-static void
-set_euc_term (ttyfd)
-     int ttyfd;
+static int
+set_euc_term (int ttyfd)
 {
   eucioc_t eucioc;
 
@@ -1765,17 +1775,16 @@ set_euc_term (ttyfd)
   if (euc_set (&eucioc, ttyfd) != 0)
     {
       fprintf (stderr, "eucwidth set failed\n");
-      return;
+      return (1);
     }
-  return;
+  return (0);
 }
 
 #endif /* SVR4 */
 
 #ifdef nec_ews_svr2
 static void
-set_jterm (ttyfd, ttypfd)
-     int ttyfd, ttypfd;
+set_jterm (int ttyfd, int ttypfd)
 {
   struct jtermio buf;
 
@@ -1796,46 +1805,50 @@ set_jterm (ttyfd, ttypfd)
 
 #ifdef sony
 static void
-set_sony_jterm(ttyfd, ttypfd)
-int ttyfd, ttypfd;
+set_sony_jterm (int ttyfd, int ttypfd)
 {
 #ifdef TIOCKGET
   int tmode, jmode = 0;
   struct jtchars jtc;
 
-  if (ioctl(ttyfd, TIOCKGET, &tmode) < 0) {
-    fprintf(stderr, "error in ioctl TIOCKGET.\n");
-    exit(1);
-  }
+  if (ioctl(ttyfd, TIOCKGET, &tmode) < 0)
+    {
+      fprintf(stderr, "error in ioctl TIOCKGET.\n");
+      exit (1);
+    }
   jmode = tmode;
   tmode &= ~(KM_SYSCODE | KM_TTYPE);
-  switch (pty_c_flag) {
-  case J_EUJIS:
-    tmode |= KM_EUC | KM_SYSEUC;
-    break;
-  case J_JIS:
-    tmode |= KM_ASCII;
-    break;
-  case J_SJIS:
-    tmode |= KM_SJIS | KM_SYSSJIS;
-    break;
-  }
-  if (ioctl(ttypfd, TIOCKSET, &tmode) < 0) {
-    fprintf(stderr, "error in ioctl TIOCKSET.\n");
-    exit(1);
-  }
+  switch (pty_c_flag)
+    {
+    case J_EUJIS:
+      tmode |= KM_EUC | KM_SYSEUC;
+      break;
+    case J_JIS:
+      tmode |= KM_ASCII;
+      break;
+    case J_SJIS:
+      tmode |= KM_SJIS | KM_SYSSJIS;
+      break;
+    }
+  if (ioctl(ttypfd, TIOCKSET, &tmode) < 0)
+    {
+      fprintf(stderr, "error in ioctl TIOCKSET.\n");
+      exit (1);
+    }
 #endif /* TIOCKGET */
 
 #ifdef TIOCKGETC    
-  if ((jmode & KM_TTYPE) == KM_JIS) {
-    ioctl(ttyfd, TIOCKGETC, &jtc);
-    jtc.t_ascii = 'B';
-    jtc.t_kanji = 'B';
-    if (ioctl(ttypfd, TIOCKSETC, &jtc) < 0) {
-      fprintf(stderr, "error in ioctl TIOCKSETC.\n");
-      exit(1);
+  if ((jmode & KM_TTYPE) == KM_JIS)
+    {
+      ioctl(ttyfd, TIOCKGETC, &jtc);
+      jtc.t_ascii = 'B';
+      jtc.t_kanji = 'B';
+      if (ioctl(ttypfd, TIOCKSETC, &jtc) < 0)
+	{
+	  fprintf(stderr, "error in ioctl TIOCKSETC.\n");
+	  exit(1);
+	}
     }
-  }
 #endif
 }
 #endif /* sony */
@@ -1843,132 +1856,233 @@ int ttyfd, ttypfd;
 /** ttyp のオープン */
 
 #ifndef USE_LIBSPT
-#define MAXPTYNO (0x10 * (('z' - 'p' + 1) + ('Z' - 'P' + 1)))
-int ptyno;
-char *ptynm = "/dev/pty";
-#ifdef sgi
-extern char *_getpty (int *, int, mode_t, int);
-char *ttypnm = "/dev/ttyqxxx";
-#else
-char *ttypnm = "/dev/tty";
-#endif /* sgi */
+/* ways to get a pty'
+ == Traditional
+   Try opening each /dev/ptyXX and use the succeeded one
+ == SGI IRIX
+   use _getpty()
+ == BSD? (HAVE_OPENPTY)
+   use openpty()
+ == STREAMS (Solaris) (HAVE_PTSNAME)
+   use posix_openpt() (or open /dev/ptmx directly) and ptsname()
+   (see pts(7D) for EXAMPLE)
+*/
+
+#if !defined(sgi) && !defined(HAVE_PTSNAME)
+char tty_master[32]; /*VVVV overflow?*/
+#endif
+char tty_slave [32]; /*VVVV overflow?*/
 
-#ifndef sgi
-static void ptyname ();
+#if defined(BSD43) || defined(DGUX)	/* FOR PASS8 */
+static int local_mode_sv;
 #endif
 #endif /* !USE_LIBSPT */
 
+/* open slave side of pty to ttypfd */
 static void
-open_ttyp ()
+open_ttyp (void)
 {
-  char nmbuf[20];
+#ifndef USE_LIBSPT     /* && !defined(linux) ? */
+  struct stat tstat;
+  char chown_failed = 0;
+  const char *msg_insecure = "Your ttyp (%s) may be insecure from other users, but continue anyway ...\r\n";
+#endif /* !USE_LIBSPT */
 
 #ifdef USE_LIBSPT
   if ((ttypfd = spt_open_slave(spth)) == ERROR)
+#else /* USE_LIBSPT */
+# if defined(sgi)
+  if ((ttypfd = open (tty_slave, O_RDWR)) == ERROR)
+# elif defined(HAVE_PTSNAME)
+  if ((ttypfd = open(tty_slave, O_RDWR)) == ERROR	/* open slave */
+#   if defined(I_PUSH)
+	/* for systems that have STREAMS */
+       || ioctl (ttypfd, I_PUSH, "ptem") == ERROR	/* push ptem */
+       || ioctl (ttypfd, I_PUSH, "ldterm") == ERROR	/* push ldterm */
+#   endif
+     )
+# elif defined (HAVE_OPENPTY)
+  if (ttypfd < 0)		/* already open */
+# else
+  if ((ttypfd = open (tty_slave, O_RDWR, 0)) == ERROR)	/* old method */
+# endif /* sgi */
+#endif /* USE_LIBSPT */
     {
-#elif defined(sgi)
-  if ((ttypfd = open (ttypnm, O_RDWR)) == ERROR)
-    {
-#else
-  ptyname (nmbuf, ttypnm, ptyno);
-  if ((ttypfd = open (nmbuf, O_RDWR, 0)) == ERROR)
-    {
-#endif
-      err ("Can't open ttyp.");
+      perror(tty_slave);	/* debug */
+      uum_err ("Can't open ttyp.");
     }
-#if !defined(USE_LINUX_TERM) && !defined(USE_LIBSPT)
-  chown (nmbuf, getuid (), getgid ());
-  chmod (nmbuf, 0622);
-#endif /* !USE_LINUX_TERM && !USE_LIBSPT */
 #if defined(USE_LIBSPT)
   spt_init_slavefd(spth, ttypfd);
-#elif defined(I_PUSH) && defined(SVR4)
-  ioctl(ttypfd, I_PUSH, "ptem");
-  ioctl(ttypfd, I_PUSH, "ldterm");
-  ioctl(ttypfd, I_PUSH, "ttcompat");
-#endif
-	
+#else	/* USE_LIBSPT */
+/* #if !defined(linux) */
+  if(fstat(ttypfd, &tstat)==0) {
+    if(tstat.st_uid != getuid()) {
+      if(chown (tty_slave, getuid (), getgid ())!=0) {
+	perror("Can't change owner of ttyp.");
+	fprintf(stderr, msg_insecure, tty_slave);
+	chown_failed = 1;
+      }
+    }
+    if((tstat.st_mode & (S_IWGRP | S_IWOTH)) != 0) {
+      /* Ignore message if chown failed (chmod will fail also ...) */
+      if(chmod (tty_slave, 0622)!=0 && chown_failed == 0) {
+	perror("Can't change permission of ttyp.");
+	fprintf(stderr, msg_insecure, tty_slave);
+      }
+    }
+  } else {
+    perror("Can't stat ttyp.");
+    fprintf(stderr, msg_insecure, tty_slave);
+  }
+/* #endif */ /* linux */
+#endif /* USE_LIBSPT */
+
   /*
    * We save terminal settings in main() instead of here.
-   * When USE_LINUX_TERM open_ttyp() is invoked from child!
+   * When defined(linux) open_ttyp() is invoked from child!
    */
 #ifndef USE_LINUX_TERM
   j_term_p_init (ttypfd);
 #endif
 
 #ifdef TIOCSSIZE
-    pty_rowcol.ts_lines = crow; /* instead of lines */
-    pty_rowcol.ts_cols = maxlength; /* instead of columns */
-    ioctl(ttypfd, TIOCSSIZE, &pty_rowcol);
+  pty_rowcol.ts_lines = crow;   /* instead of lines */
+  pty_rowcol.ts_cols = maxlength;       /* instead of columns */
+  ioctl (ttypfd, TIOCSSIZE, &pty_rowcol);
 #endif /* TIOCSSIZE */
 
 #ifdef SVR4
   set_euc_term(ttypfd);
 #endif
-
 #if defined(nec_ews_svr2)
   set_jterm (ttyfd, ttypfd);
 #endif
-
 #ifdef sony
   set_sony_jterm(ttyfd, ttypfd);
 #endif
+}
+
+#if defined(HAVE_PTSNAME) && ! defined(HAVE_POSIX_OPENPT)
+/* Maybe harmless on defined(USE_LIBSPT) */
+#if !defined(HAVE__DEV_PTMX)
+#warning "If not cross compile, you must check pts master device (other than /dev/ptmx)."
+/* but continue anyway. */
+#endif
 
+/* fallback function to posix_openpt */
+static int
+posix_openpt (int flags)
+{
+  return open("/dev/ptmx", flags);
 }
+#endif		/* HAVE_PTSNAME && !HAVE_POSIX_OPENPT */
 
 /** pty のオープン */
-#if defined(USE_LIBSPT)
+/* allocate a new pty master into int ptyfd */
 static void
-open_pty ()
+open_pty (void)
 {
+#if defined(USE_LIBSPT)
   int r;
   r = spt_open_pty(&spth, &ptyfd, NULL, NULL);
   if (r != SPT_E_NONE && r != SPT_E_CHOWN_FAIL)
-    err ("Can't get pty.");
-  return;
-}
+    uum_err ("Can't get pty.");
+
 #elif defined(sgi)
-static void
-open_pty ()
-{
-  char nmbuf[20];
   char *tty_name_buff;
+  extern char *_getpty (int *, int, mode_t, int);
   tty_name_buff = _getpty (&ptyfd, O_RDWR | O_NDELAY, 0600, 0);
   if (tty_name_buff == 0)
-    err ("Can't get pty.");
-  strcpy (ttypnm, tty_name_buff);
-  return;
+    uum_err ("Can't get pty.");
+  strcpy (tty_slave, tty_name_buff);
+
+#elif defined(HAVE_PTSNAME)
+  char *p;
+  ptyfd = posix_openpt(O_RDWR);	/* open master */
+  if (ptyfd < 0)
+    uum_err ("Could not get a pty.");
+  grantpt (ptyfd);		/* change permission of slave */
+  unlockpt (ptyfd);		/* unlock slave */
+
+  p = ptsname (ptyfd);		/* get name of slave */
+  strcpy(tty_slave, p);
+  /* you can't get path of the "master" by ttyname;
+   * only the open filedes ptyfd is available.
+   */
+  /* strcpy (tty_master, "/dev/ptm/x"); */
+
+#elif HAVE_OPENPTY
+  if (openpty(&ptyfd, &ttypfd, tty_slave, NULL, NULL) == ERROR)
+    uum_err ("Could not get a pty.");
+    /* Note: slave tty is ALREADY OPEN as ttypfd */
+  strcpy(tty_master, ttyname(ptyfd));
 
-}
 #else
+  /* Traditional method that search in /dev/ttyXX */
+  open_pty_traditional ();
+#endif /* USE_LIBSPT */
+
+  return;
+}
+
+#if !(USE_LIBSPT) && !(sgi) && !(HAVE_PTSNAME) && !(HAVE_OPENPTY)
 static void
-open_pty ()
+open_pty_traditional (void)
 {
-  char nmbuf[20];
+  int ptyno;
+
+#ifdef hpux
+# define MAXPTYS (11*16)
+# define PTYDEV ";/dev/ptym/pty"
+# define TTYDEV "/dev/pty/tty"
+#else
+# define MAXPTYS 32
+# define PTYDEV "/dev/pty"
+# define TTYDEV "/dev/tty"
+#endif
 
-  for (ptyno = 0; ptyno < MAXPTYNO; ptyno++)
+  for (ptyno = 0; ptyno < MAXPTYS; ptyno++)	/* sysconf? */
     {
-      ptyname (nmbuf, ptynm, ptyno);
-      if ((ptyfd = open (nmbuf, O_RDWR, 0)) != ERROR)
+/*
+ * Change pseudo-devices.
+ * Because FreeBSD's master pseudo-devices are pty[p-sP-S][0-9a-v].
+ * Patched by Hidekazu Kuroki(hidekazu@cs.titech.ac.jp)         1996/8/20
+ */
+#if (defined(BSD) && (BSD >= 199306))   /* 4.4BSD-Lite by Taoka */
+# define PTXNAME(b, PFX, no) \
+    snprintf ((b), sizeof((b)), PFX "%1c%1c", "pqrsPQRS"[((no) >> 5)], "0123456789abcdefghijklmnopqrstuv"[(no) & 0x1f])
+#elif defined(hpux)
+#  define PTXNAME(b, PFX, no) \
+    sprintf ((b), PFX "%1c%1c", "zyxwvutsrqp"[(no)>>4], "fedcba9876543210"[(no)&0x0f])
+#else /* !4.4BSD-Lite, !hpux */
+#  define PTXNAME(b, PFX, no) \
+    sprintf ((b), PFX "%1c%1c", 'p' + ((no) >> 4), "0123456789abcdef"[(no) & 0x0f]);
+#endif /* !4.4BSD-Lite */
+#define PTMNAME(b, no) PTXNAME(b, PTYDEV, no)
+#define PTSNAME(b, no) PTXNAME(b, TTYDEV, no)
+
+      PTMNAME(tty_master, ptyno);
+      fprintf(stderr, "trying master <%s>\n", tty_master);	/* debug */
+      if ((ptyfd = open (tty_master, O_RDWR, 0)) != ERROR)
         {
-#if defined(uniosu)
+# if defined(uniosu)
           if (ioctl (ptyfd, PIOCPKT, 1) < 0)
             {                   /* packet mode on */
               fprintf (stderr, "error in ioctl PIOCPKT.\n");
               exit (1);
             }
-#endif
-	  return;
+# endif /* uniosu */
+	  PTSNAME(tty_slave, ptyno);
+          return;
         }
     }
-  err ("Can't get pty.");
+  uum_err ("Can't get pty.");
 }
-#endif
+#endif /* !(USE_LIBSPT) && !(sgi) && !(HAVE_PTSNAME) && !(HAVE_OPENPTY) */
 
 /** エラーだよ。さようなら。 */
 void
-err (s)
-     char *s;
+uum_err (char *s)
 {
   puts (s);
   fclose (stdout);
@@ -1979,12 +2093,10 @@ err (s)
 
 /** 立つ鳥後を濁さず 終わりの処理 */
 static void
-do_end ()
+do_end (void)
 {
 #ifdef USE_LIBSPT
   int r;
-#else
-  char nmbuf[20];
 #endif
 
   static int do_end_flg = 0;
@@ -1994,29 +2106,28 @@ do_end ()
 
   signal (SIGCHLD, SIG_DFL);
   fcntl (ttyfd, F_SETFL, 0);
-
   j_term_restore ();
 
 #if !defined(USE_LIBSPT) && !defined(sgi)
-  ptyname (nmbuf, ptynm, ptyno);
-  if (chown (nmbuf, 0, 0) == ERROR)
+# ifndef HAVE_PTSNAME
+  if (chown (tty_master, 0, 0) == ERROR)
     {
-      perror (prog);
+      perror ("Can't restore owner of tty_master.");
     }
-  if (chmod (nmbuf, 0666) == ERROR)
+  if (chmod (tty_master, 0666) == ERROR)
     {
-      perror (prog);
+      perror ("Can't restore permission of tty_master.");
     }
 
-  ptyname (nmbuf, ttypnm, ptyno);
-  if (chown (nmbuf, 0, 0) == ERROR)
+  if (chown (tty_slave, 0, 0) == ERROR)
     {
-      perror (prog);
+      perror ("Can't restore owner of ttyp.");
     }
-  if (chmod (nmbuf, 0666) == ERROR)
+  if (chmod (tty_slave, 0666) == ERROR)
     {
-      perror (prog);
+      perror ("Can't restore permission of ttyp.");
     }
+# endif /* HAVE_PTSNAME */
 
 #endif /* !USE_LIBSPT && !sgi */
   close (ttyfd);
@@ -2027,18 +2138,18 @@ do_end ()
     spt_perror(NULL, r);
 #else
   close (ptyfd);
-#endif
+#endif /* USE_LIBSPT */
 
   chdir ("/tmp");               /* to avoid making too many mon.out files */
 
   KILLPG (child_id, SIGHUP);
-  exit (0);
+  _exit (0);
 }
 
 #if defined(uniosu)
 /** 仮名漢字変換を ioctl でオフした時の keyin に代わる関数 */
 int
-ioctl_off ()
+ioctl_off (void)
 {
   static unsigned char buf[BUFSIZ];
   int n;
@@ -2086,44 +2197,15 @@ ioctl_off ()
 }
 #endif /* defined(uniosu) */
 
-
-#if !defined(USE_LIBSPT) && !defined(sgi)
-static void
-ptyname (b, pty, no)
-     char *b, *pty;
-{
-/*
- * Change pseudo-devices.
- * Because FreeBSD's master pseudo-devices are pty[p-sP-S][0-9a-v].
- * Patched by Hidekazu Kuroki(hidekazu@cs.titech.ac.jp)         1996/8/20
- */
-#if (defined(BSD) && (BSD >= 199306))   /* 4.4BSD-Lite by Taoka */
-  sprintf (b, "%s%1c%1c", pty, "pqrsPQRS"[(no >> 5)], (((no & 0x1f) > 9) ? 'a' : '0') + (no & 0x1f));
-#else /* ! 4.4BSD-Lite */
-  sprintf (b, "%s%1c%1x", pty, 'p' + (no >> 4), no & 0x0f);
-  if (no < 0x10 * ('z' - 'p' + 1))
-    {
-      sprintf(b, "%s%1c%1x", pty, 'p' + (no >> 4), no & 0x0f);
-    }
-  else
-    {
-      no -= 0x10 * ('z' - 'p' + 1);
-      sprintf(b, "%s%1c%1x", pty, 'P' + (no >> 4), no & 0x0f);
-    }
-#endif /* ! 4.4BSD-Lite */
-}
-#endif /* !USE_LIBSPT && !sgi */
-
 static void
-default_usage ()
+default_usage (void)
 {
   fprintf (stderr, "%s: Bad -L option\n", prog);
   exit (0);
 }
 
 static void
-usage (optstr)
-     char *optstr;
+usage (char *optstr)
 {
   printf ("usage: prog %s by lang \"%s\"\n", optstr, lang_dir);
   exit (0);
@@ -2139,10 +2221,10 @@ intfnptr sigwinch;
 #endif /* SIGWINCH */
 
 static void
-save_signals ()
+save_signals (void)
 {
   sigpipe = signal (SIGPIPE, SIG_IGN);
-#ifdef USE_LINUX_TERM			    /* XXX */
+#ifdef linux                    /* XXX */
   sighup = signal (SIGHUP, SIG_IGN);
 #endif
   sighup = signal (SIGHUP, terminate_handler);
@@ -2161,7 +2243,7 @@ save_signals ()
 }
 
 static void
-restore_signals ()
+restore_signals (void)
 {
   signal (SIGPIPE, sigpipe);
   signal (SIGHUP, sighup);
@@ -2179,14 +2261,13 @@ restore_signals ()
 #endif /* SIGTSTP */
 }
 
-/* should be "defined(SIGWINCH)"? */
 #if defined(BSD43) || defined(DGUX)
 static void
-setsize ()
+setsize (void)
 {
-  register int i;
+  int i;
   struct winsize win;
-  extern Term_LineWidth, Term_RowWidth, maxlength, crow;
+  extern int Term_LineWidth, Term_RowWidth, maxlength;
 
   if (ioctl (ttyfd, TIOCGWINSZ, &win) < 0)
     {
@@ -2209,11 +2290,11 @@ setsize ()
 
 #ifdef  SIGWINCH
 static void
-change_size ()
+change_size (void)
 {
   register int i;
   struct winsize win;
-  extern Term_LineWidth, Term_RowWidth, maxlength, crow;
+  extern int Term_LineWidth, Term_RowWidth, maxlength;
 
   if (ioctl (ttyfd, TIOCGWINSZ, &win) < 0)
     {

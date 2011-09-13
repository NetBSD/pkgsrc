$NetBSD: patch-Wnn_uum_jhlp.c,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/jhlp.c.orig	2005-08-28 16:44:21.000000000 +0000
+++ Wnn/uum/jhlp.c
@@ -10,7 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002-2003
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2003, 2006, 2009
+ * Copyright Canna Project 2002
+ * Copyright Taketo Kabe 2003
  *
  * Maintainer:  FreeWnn Project
  *
@@ -38,6 +40,7 @@ static char *rcs_id = "$Id: jhlp.c,v 1.1
 #endif
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <setjmp.h>
 #include <signal.h>
 #if STDC_HEADERS
@@ -53,12 +56,20 @@ static char *rcs_id = "$Id: jhlp.c,v 1.1
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
@@ -66,45 +77,64 @@ static char *rcs_id = "$Id: jhlp.c,v 1.1
 #ifdef HAVE_UNISTD_H
 #  include <unistd.h>
 #endif
+#if HAVE_SYS_WAIT_H
+#  include <sys/wait.h>
+#endif
+#ifdef HAVE_LIBUTIL_H
+#  include <libutil.h>
+#endif
+
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
+
+#ifdef HAVE_LIBSPT
+#  include <libspt.h>	/* lib from Canna. not used w/FreeWnn */
+#endif
+
+/*
+ * Enable old Linux specific code.
+ * We hope you don't have to use this #define ...
+ * (We will remove this #define and related code in near future.)
+ */
+/* #define USE_LINUX_TERM */
+
+
+#include "sdefine.h"
 
 #include "jllib.h"
 #include "commonhd.h"
-#include "sdefine.h"
 #include "sheader.h"
 #include "wnn_config.h"
 #include "wnn_os.h"
 
-jmp_buf kk_env;
-
-#ifdef HAVE_WAIT3
-#       include <sys/wait.h>
-#endif /* HAVE_WAIT3 */
-
-#ifdef BSD42
-#       include <sgtty.h>
-#endif /* BSD42 */
-
-#ifdef SYSVR2
-#ifdef TERMINFO
-#       include <curses.h>
-#endif /* TERMINFO */
-#       include <term.h>
-#endif /* SYSVR2 */
-#if defined(SVR4) || defined(hpux) || defined(sgi)
-#include <sys/termio.h>
-#endif
-#ifdef linux
-#include <termios.h>
-#endif
-
+/* old system check (don't know if it works) */
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
@@ -113,36 +143,44 @@ jmp_buf kk_env;
 
 #define ERROR -1
 
+jmp_buf kk_env;
 #ifdef TIOCSSIZE
 struct ttysize pty_rowcol;
 #endif /* TIOCSSIZE */
 
-int ttyfd;
+int ttyfd;			/* master tty */
 
 char *tname;                    /* terminal name */
 char *cmdnm = "csh";            /* char *cmdnm = "csh"; */
 
 int child_id;
 char *prog;
+#ifdef HAVE_LIBSPT
+spt_handle *spth = NULL;
+#endif
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
+static void save_signals (void);
+static void restore_signals (void);
+static RETSIGTYPE terminate_handler (void);
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
+static unsigned char keyin0 (void);
 
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
@@ -150,7 +188,6 @@ main (argc, argv)
   char *server_env;
   char errprefix[1024] = "error";
   int i;
-  extern char *get_server_env ();
 
   prog = argv[0];
   flow_control = FLOW_CONTROL;
@@ -182,6 +219,7 @@ main (argc, argv)
 
   if (*lang_dir == '\0')
     {
+#ifndef CANNA
       if ((p = getenv ("LANG")) != NULL)
         {
           if (strlen (p) >= 4)
@@ -194,6 +232,9 @@ main (argc, argv)
               strcpy (lang_dir, p);
             }
         }
+#else /* CANNA */
+      strcpy (lang_dir, WNN_DEFAULT_LANG);
+#endif /* CANNA */
     }
   for (f = function_db; *lang_dir && f && f->lang; f++)
     {
@@ -295,15 +336,14 @@ main (argc, argv)
       exit (1);
     }
 
-
-#if defined(BSD42) && !defined(DGUX)
-#if !(defined(BSD) && (BSD >= 199306))
+/* 2003.06 should delete this? */
+#ifndef HAVE_LIBSPT
+  /* saveutmp() does utmp handling if USE_UTMP is set to 1 */
   if (saveutmp () < 0)
     {
       puts ("Can't save utmp\n");
     }
-#endif
-#endif /* BSD42 */
+#endif /* !HAVE_LIBSPT */
 
 
   if (optind)
@@ -326,16 +366,11 @@ main (argc, argv)
       argv[1] = NULL;
     }
 
+  j_term_save ();
+  /* do_end () is allowed from here */
   save_signals ();
 
-#ifdef TERMCAP
-  if (getTermData () == -1)
-    {
-      fprintf (stderr, "Sorry. Something is wrong with termcap, maybe.\r\n");
-      exit (21);
-    }
-#endif /* TERMCAP */
-#ifdef TERMINFO
+#if HAVE_TERMINFO	/* TERMINFO */
   if (openTermData () == -1)
     {
       fprintf (stderr, "Sorry. Something is wrong with terminfo, maybe.\r\n");
@@ -343,37 +378,35 @@ main (argc, argv)
     }
   maxlength = columns;
   crow = lines - conv_lines;
-#endif /* TERMINFO */
+#else			/* Assume TERMCAP */
+  if (getTermData () == -1)
+    {
+      fprintf (stderr, "Sorry. Something is wrong with termcap, maybe.\r\n");
+      exit (21);
+    }
+#endif /* HAVE_TERMINFO */
 #if defined(BSD43) || defined(DGUX)
   setsize ();
 #endif /* BSD43 */
 
-#ifdef TERMCAP
+#if !HAVE_TERMINFO	/* Assume TERMCAP */
   if (set_TERMCAP () == -1)
     {
       fprintf (stderr, "Sorry. Something is wrong with termcap, maybe.\r\n");
       exit (21);
     }
-#endif /* TERMCAP */
+#endif /* !HAVE_TERMINFO */
 
+  ttyfd = 0;
   open_pty ();
-#ifndef linux
+/* It is normal to open tty here, before fork().
+   Don't know why linux is different.
+   So temporally comment it out to make it as other OSes. */
+#ifndef USE_LINUX_TERM
   open_ttyp ();
 #endif
   exec_cmd (argv);
 
-  /*
-     close(0);
-     close(1);
-     close(2);
-     if((ttyfd = open("/dev/tty", O_RDWR | O_NDELAY, 0)) != 0) {
-     err("Can't open /dev/tty.");
-     }
-     dup(0);
-     dup(0);
-   */
-
-  ttyfd = 0;
   get_rubout ();
 
   switch (init_uum ())
@@ -394,6 +427,7 @@ main (argc, argv)
       uum_err ("term initialize fault.");
     }
 
+#ifndef CANNA
   if (!jl_isconnect (bun_data_))
     {
       if (!servername || *servername == 0)
@@ -406,6 +440,7 @@ main (argc, argv)
         }
       flush ();
     }
+#endif /* CANNA */
 
   puteustring (MSG_GET (1),
                /*
@@ -424,6 +459,7 @@ main (argc, argv)
 #endif /* defined(uniosu) */
 
   do_main ();
+  return 0;
 }
 
 /*
@@ -431,7 +467,7 @@ main (argc, argv)
  */
 
 static int
-do_h_opt ()
+do_h_opt (void)
 {
   henkan_off_flag = 1;
   defined_by_option |= OPT_WAKING_UP_MODE;
@@ -439,7 +475,7 @@ do_h_opt ()
 }
 
 static int
-do_H_opt ()
+do_H_opt (void)
 {
   henkan_off_flag = 0;
   defined_by_option |= OPT_WAKING_UP_MODE;
@@ -448,42 +484,42 @@ do_H_opt ()
 
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
@@ -492,28 +528,28 @@ do_S_opt ()
 
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
@@ -522,14 +558,14 @@ do_T_opt ()
 
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
@@ -537,14 +573,14 @@ do_U_opt ()
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
@@ -552,7 +588,7 @@ do_x_opt ()
 }
 
 static int
-do_X_opt ()
+do_X_opt (void)
 {
   flow_control = 1;
   defined_by_option |= OPT_FLOW_CTRL;
@@ -560,7 +596,7 @@ do_X_opt ()
 }
 
 static int
-do_k_opt ()
+do_k_opt (void)
 {
   strncpy(uumkey_name_in_uumrc, optarg, PATHNAMELEN-1);
   uumkey_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -573,7 +609,7 @@ do_k_opt ()
 }
 
 static int
-do_c_opt ()
+do_c_opt (void)
 {
   strncpy(convkey_name_in_uumrc, optarg, PATHNAMELEN-1);
   convkey_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -586,7 +622,7 @@ do_c_opt ()
 }
 
 static int
-do_r_opt ()
+do_r_opt (void)
 {
   strncpy(rkfile_name_in_uumrc, optarg, PATHNAMELEN-1);
   rkfile_name_in_uumrc[PATHNAMELEN-1] = '\0';
@@ -599,14 +635,14 @@ do_r_opt ()
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
@@ -619,7 +655,7 @@ do_D_opt ()
 }
 
 static int
-do_n_opt ()
+do_n_opt (void)
 {
   strncpy(username, optarg, PATHNAMELEN-1);
   username[PATHNAMELEN-1] = '\0';
@@ -631,13 +667,13 @@ do_n_opt ()
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
@@ -682,39 +718,32 @@ parse_options (argc, argv)
 
 /** tty に対する ioctl のセット */
 
-#ifdef BSD42
-struct sgttyb savetmio;
-/*
-  struct sgttyb ttyb =
-  { B9600, B9600, 0x7f, 0x15, EVENP | ODDP | ECHO | CRMOD };
-  int local_mode = LCRTBS | LCRTERA | LCRTKIL | LCTLECH | LPENDIN | LDECCTQ;
-*/
+#ifdef USE_SGTTY
+#  if defined(BSD43) || defined(DGUX) /* should be "defined(LPASS8)"? */
+#    define SET_PASS8  1
+#  endif
 
+struct sgttyb savetmio;
+struct sgttyb ttyb_def = { B9600, B9600, 0x7f, 0x15,
+			   EVENP | ODDP | ECHO | CRMOD };
+int local_mode_def = LCRTBS | LCRTERA | LCRTKIL | LCTLECH | LPENDIN | LDECCTQ;
 /* added later */
 struct tchars tcharsv;
 struct ltchars ltcharsv;
 struct sgttyb ttyb;
 int local_mode;
+#  ifdef SET_PASS8
+static int local_mode_sv;
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
 
@@ -722,28 +751,125 @@ j_term_init ()
   buf.sg_flags |= RAW;
   buf.sg_flags &= ~ECHO;
   ioctl (ttyfd, TIOCSETP, &buf);
+#  ifdef SET_PASS8
+  ioctl (ttyfd, TIOCLSET, &local_mode);
+#  endif
 
   return 0;
 }
-#endif /* BSD42 */
 
-#ifdef SYSVR2
-#define UNDEF_STTY 0xff
+static_void
+j_term_save (void)
+{
+  ioctl (ttyfd, TIOCGETC, &tcharsv);
+  ioctl (ttyfd, TIOCGLTC, &ltcharsv);
+  if (ioctl (ttyfd, TIOCGETP, &ttyb))
+    ttyb = ttyb_def;
+  savetmio = ttyb;
+#  ifdef SET_PASS8
+  if (ioctl (ttyfd, TIOCLGET, &local_mode_sv))
+    local_mode_sv = local_mode_def;
+  local_mode = local_mode_sv | LPASS8;	/* set PASS8 */
+#  else  /* !SET_PASS8 */
+  if (ioctl (ttyfd, TIOCLGET, &local_mode))
+    local_mode = local_mode_def;
+#  endif /* !SET_PASS8 */
+}
+
+static void
+j_term_restore (void)
+{
+  ioctl (ttyfd, TIOCSETP, &savetmio);
+#  ifdef SET_PASS8
+  ioctl (ttyfd, TIOCLSET, &local_mode_sv);
+#  endif /* SET_PASS8 */
+}
 
-struct termio savetmio;
-struct termio terms = {
-  IGNBRK | ICRNL | IXON,        /* c_iflag */
-  ONLCR | OPOST,                /* c_oflag */
-  B9600 | CS8 | CSTOPB | CREAD | CLOCAL,        /* c_cflag */
-  ISIG | ICANON | ECHO | ECHOE | ECHOK, /* c_lflag */
-  0,                            /* c_line */
-  {0x3, 0x1c, 0x8, 0x15, 0x4, 0, 0, 0}  /* c_cc */
-};
+static void
+j_term_p_init (int ttypfd)
+{
+  int word;
+  ioctl (ttypfd, TIOCSETC, &tcharsv);
+  ioctl (ttypfd, TIOCSLTC, &ltcharsv);
+  ioctl (ttypfd, TIOCSETP, &ttyb);
+  ioctl (ttypfd, TIOCLSET, &local_mode);
+  if (pty_c_flag == J_JIS)
+    {
+      word = LCTLECH;
+      ioctl (ttypfd, TIOCLBIC, &word);
+    }
+}
+#endif /* USE_SGTTY */
+
+#if defined(USE_TERMIO) || defined(USE_TERMIOS)
+
+#ifdef USE_TERMIOS
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
+#ifdef CERASE
+#  define WNN_CERASE CERASE
+#else
+#  define WNN_CERASE 0x7f
+#endif
+
+struct TERMIO savetmio;
+
+static void
+set_default_termio (struct TERMIO *terms)
+{
+  bzero (terms, sizeof *terms);
+  terms->c_iflag = IGNBRK | ICRNL | IXON;
+  terms->c_oflag = OPOST;
+#ifdef ONLCR
+  terms->c_oflag |= ONLCR;
+#endif
+  terms->c_cflag = CS8 | CSTOPB | CREAD | CLOCAL;
+#ifndef USE_TERMIOS
+  terms->c_cflag |= B9600;
+#endif
+  terms->c_lflag = ISIG | ICANON | ECHO | ECHOE | ECHOK;
+#ifdef USE_TERMIOS
+  terms->c_cc[VINTR] = 0x3;
+  terms->c_cc[VQUIT] = 0x1c;
+  terms->c_cc[VERASE] = 0x8;
+  terms->c_cc[VKILL] = 0x15;
+  terms->c_cc[VEOF] = 0x4;
+  terms->c_cc[VEOL] = _POSIX_VDISABLE;
+#  ifdef VEOL2
+  terms->c_cc[VEOL2] = _POSIX_VDISABLE;
+#  endif
+  cfsetospeed (terms, B9600);
+  cfsetispeed (terms, B9600);
+#else /* !USE_TERMIOS */
+  terms->c_line = 0;
+  terms->c_cc[0] = 0x3;
+  terms->c_cc[1] = 0x1c;
+  terms->c_cc[2] = 0x8;
+  terms->c_cc[3] = 0x15;
+  terms->c_cc[4] = 0x4;
+  terms->c_cc[5] = 0;
+  terms->c_cc[6] = 0;
+  terms->c_cc[7] = 0;
+#endif /* !USE_TERMIOS */
+}
 
 #if defined(uniosu)
 struct jtermio savejtmio;
-struct jtermio savejtmiottyp;
-struct auxtermio saveauxterm;
 struct auxtermio auxterm = {
   0,                            /* -tostop */
   {0x1a, 0, 0, 0, 0, 0, 0, 0}   /* c_cc2 */
@@ -751,7 +877,7 @@ struct auxtermio auxterm = {
 #endif /* defined(uniosu) */
 
 static void
-get_rubout ()
+get_rubout (void)
 {
   if (savetmio.c_cc[VERASE] == UNDEF_STTY)
     {
@@ -764,9 +890,9 @@ get_rubout ()
 }
 
 int
-j_term_init ()
+j_term_init (void)
 {
-  struct termio buf1;
+  struct TERMIO buf1;
 #if defined(uniosu)
   struct jtermio buf2;
 #endif /* defined(uniosu) */
@@ -779,35 +905,47 @@ j_term_init ()
   buf1.c_cflag |= CS8;
   buf1.c_cc[VMIN] = 1;          /* cf. ICANON */
   buf1.c_cc[VTIME] = 0;
-#else /* linux */
   buf1.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IUCLC | IXON);
+#else /* !linux */
+  buf1.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IXON);
+#  ifdef IUCLC
+  buf1.c_iflag &= ~(IUCLC);
+#  endif
   if (flow_control)
     {
       buf1.c_iflag |= IXON;
     }
-  buf1.c_lflag &= ~(ECHONL | ECHOK | ECHOE | ECHO | XCASE | ICANON | ISIG);
+  buf1.c_lflag &= ~(ECHONL | ECHOK | ECHOE | ECHO | ICANON | ISIG);
+#  ifdef XCASE
+  buf1.c_lflag &= ~(XCASE);
+#  endif
+#  ifdef IEXTEN
+  buf1.c_lflag &= ~(IEXTEN);
+#  endif
   buf1.c_oflag = OPOST;
-  buf1.c_cc[VINTR] = CDEL;
-  buf1.c_cc[VQUIT] = CDEL;
-  buf1.c_cc[VERASE] = CDEL;
-  buf1.c_cc[VKILL] = CDEL;
+#  ifdef USE_TERMIOS
+  buf1.c_cc[VMIN] = 1;
+  buf1.c_cc[VTIME] = 0;
+  cfsetispeed(&buf1, cfgetispeed(&savetmio));
+  cfsetospeed(&buf1, cfgetospeed(&savetmio));
+#  else /* !USE_TERMIOS */
   buf1.c_cc[VEOF] = 1;          /* cf. ICANON */
   buf1.c_cc[VEOL] = 0;
-#endif /* linux */
-  if (ioctl (ttyfd, TCSETA, &buf1) == -1)
+  /* not needed? cf.ISIG*/
+  buf1.c_cc[VINTR] = WNN_CERASE;
+  buf1.c_cc[VQUIT] = WNN_CERASE;
+  buf1.c_cc[VERASE] = WNN_CERASE;
+  buf1.c_cc[VKILL] = WNN_CERASE;
+#  endif /* !USE_TERMIOS */
+#endif /* !linux */
+  if (SET_TERMATTR (ttyfd, &buf1) < 0)
     {
-      fprintf (stderr, "error in ioctl TCSETA.\n");
+      fprintf (stderr, SET_ATTR_ERROR);
       exit (1);
     }
 
 #if defined(uniosu)
-  if (ioctl (ttyfd, JTERMGET, &buf2) < 0)
-    {
-      fprintf (stderr, "error in ioctl JTERMGET in j_term_init.\n");
-      exit (1);
-    }
-  savejtmio = buf2;
-
+  buf2 = savejtmio;
   buf2.j_flg = CONVTOEXT | WNN_EXIST;
   buf2.j_level = jterm;
   switch (jcode_set)
@@ -854,42 +992,141 @@ j_term_init ()
 
   return 0;
 }
-#endif /* SYSVR2 */
+
+static void
+j_term_save (void)
+{
+  if (GET_TERMATTR (ttyfd, &savetmio) < 0)
+  {
+    set_default_termio (&savetmio);
+  }
+#if defined(uniosu)
+  if (ioctl (ttyfd, JTERMGET, &savejtmio) < 0)
+    {
+      fprintf (stderr, "uum: error in ioctl JTERMGET in open_ttyp.\n");
+      exit (1);
+    }
+#endif /* defined(uniosu) */
+}
+
+static void
+j_term_restore (void)
+{
+  if (SET_TERMATTR (ttyfd, &savetmio) < 0)
+    {
+      fprintf (stderr, SET_ATTR_ERROR);
+      exit (1);
+    }
+
+#if defined(uniosu)
+  if (ioctl (ttyfd, JTERMSET, &savejtmio) < 0)
+    {
+      fprintf (stderr, "error in ioctl JTERMSET.\n");
+      exit (1);
+    }
+#endif /* defined(uniosu) */
+}
+
+static void
+j_term_p_init (int ttypfd)
+{
+  struct TERMIO buf1;
+#if defined(uniosu)
+  struct TERMIO buf2;
+#endif
+  buf1 = savetmio;
+#ifdef DGUX                     /* copied from JLS5.4.2 */
+  /* should clear on all platforms? */
+  buf1.c_iflag &= ~ISTRIP;
+#endif /* DGUX */
+#ifdef nec_ews_svr2
+  buf1.c_line = JAPANLD;
+#endif
+#ifdef USE_TERMIOS
+  cfsetispeed(&buf1, cfgetispeed(&savetmio));
+  cfsetospeed(&buf1, cfgetospeed(&savetmio));
+#endif
+  if (SET_TERMATTR (ttypfd, &buf1) < 0)
+    {
+      fprintf (stderr, SET_ATTR_ERROR);
+      exit (1);
+    }
+#if defined(uniosu)
+  buf2 = savejtmio;
+  buf2.j_flg = CONVTOEXT | KANJIINPUT;  /* kanji input & output ok */
+  buf2.j_level = jterm;
+  switch (jcode_set)
+    {
+    case 0:
+      buf2.j_ecode = JIS;
+      break;
+    case 1:
+      buf2.j_ecode = SJIS;
+      break;
+    case 2:
+      buf2.j_ecode = UJIS;
+      break;
+    default:
+      fprintf (stderr, "uum: kanji code set not supported in terminfo.\n");
+      exit (1);
+    }
+
+  if (jis_kanji_in)
+    {
+      strcpy (buf2.j_jst, jis_kanji_in);
+      buf2.j_jstl = strlen (jis_kanji_in);
+    }
+  if (jis_kanji_out)
+    {
+      strcpy (buf2.j_jend, jis_kanji_out);
+      buf2.j_jendl = strlen (jis_kanji_out);
+    }
+  if (jgaiji_start_address)
+    {
+      *(short *) buf2.j_gcsa = jgaiji_start_address;
+    }
+  if (jgaiji_disp)
+    {
+      strcpy (buf2.j_gdsp, jgaiji_disp);
+      buf2.j_gdspl = strlen (jgaiji_disp);
+    }
+
+  if (ioctl (ttypfd, JTERMSET, &buf2) < 0)
+    {
+      fprintf (stderr, "error in ioctl JTERMSET.\n");
+      exit (1);
+    }
+
+  if (ioctl (ttypfd, TIOCSETAUX, &auxterm) < 0)
+    {
+      fprintf (stderr, "error in ioctl TIOCSETAUX.\n");
+      exit (1);
+    }
+
+#endif /* defined(uniosu) */
+}
+#endif /* USE_TERMIO || USE_TERMIOS */
 
 /** signal SIGCHLD を受けた後の処理をする。*/
-/* *INDENT-OFF* */
 RETSIGTYPE
-chld_handler ()
-/* *INDENT-ON* */
+chld_handler (void)
 {
 #ifdef HAVE_WAIT3
-#ifdef linux
-  int status;
-#else
+#ifdef HAVE_UNION_WAIT
   union wait status;
+#else /* POSIX */
+  int status;
 #endif
   int pid;
 
-/*
- * Remove warning.
- * Patched by Hidekazu Kuroki(hidekazu@cs.titech.ac.jp)         1996/8/20
- */
-/*  if ((pid = wait3(&status, WNOHANG | WUNTRACED, NULL)) == child_id) { */
-  if ((pid = wait3 ((int *) &status, WNOHANG | WUNTRACED, NULL)) == child_id)
+  if ((pid = wait3 (&status, WNOHANG | WUNTRACED, NULL)) == child_id)
     {
       if (WIFSTOPPED (status))
         {
 #ifdef SIGCONT
           kill (pid, SIGCONT);
-#ifndef SYSVR2
-          /* pid = getpgrp (pid); */
-          pid = getpgrp ();
-          killpg (pid, SIGCONT);
-#else
-#if defined(uniosu)
-          pid = ngetpgrp (pid);
-          kill (pid, SIGCONT);
-#endif
+#ifdef GETPGID
+	  KILLPG (GETPGID (pid), SIGCONT);
 #endif
 #endif
         }
@@ -900,6 +1137,10 @@ chld_handler ()
           /*
              printf("\r\nｕｕｍを終わります。\r\n");
            */
+#ifdef HAVE_LIBSPT
+	  if (spth)
+	    spt_utmp_set_exit (spth, *(int *)&status);
+#endif
           epilogue ();
           do_end ();
         }
@@ -927,7 +1168,7 @@ chld_handler ()
 
 /** signal SIGTERM を受けた時の処理をする。*/
 static RETSIGTYPE
-terminate_handler ()
+terminate_handler (void)
 {
   signal (SIGCHLD, SIG_IGN);
   epilogue_no_close ();
@@ -940,10 +1181,8 @@ terminate_handler ()
 }
 
 #ifdef  SIGWINCH
-/* *INDENT-OFF* */
 RETSIGTYPE
-resize_handler ()
-/* *INDENT-ON* */
+resize_handler (void)
 {
   re_signal (SIGWINCH, resize_handler);
   change_size ();
@@ -957,14 +1196,15 @@ resize_handler ()
 
 /** メインループ */
 
-int sel_ptn;
-int pty_bit;
-int tty_bit;
+/* Assume fd_set, FD_ZERO() family.
+   though we may use glue in jserver/de.c */
+fd_set sel_ptn;
 int ptyfd;
 
 static void
-do_main ()
+do_main (void)
 {
+#ifndef CANNA
   unsigned char *buf;
   int ml;
 
@@ -978,38 +1218,35 @@ do_main ()
       epilogue ();
       do_end ();
     }
-
-  pty_bit = 1 << ptyfd;
-  tty_bit = 1 << ttyfd;
-  sel_ptn = pty_bit | tty_bit;
+#else  /* CANNA */
+  extern void canna_mainloop();
+#endif /* CANNA */
+
+  FD_ZERO (&sel_ptn);
+  FD_SET (ptyfd, &sel_ptn);
+  FD_SET (ttyfd, &sel_ptn);
 
   if (henkan_off_flag == 0)
     {
       disp_mode ();
     }
 
+#ifndef CANNA
   for (;;)
     {
-
       ml = kk ();
-
-/*
-      if (!((ml < 2) && ((return_buf[0] <= ' ') || (return_buf[0] == 0x7f)))) {
-*/
       make_history (return_buf, ml);
-/*
-      }
-*/
       ml = (*code_trans[(internal_code << 2) | pty_c_flag]) (buf, return_buf, sizeof (w_char) * ml);
       if (ml > 0)
         write (ptyfd, buf, ml);
     }
+#else  /* CANNA */
+  canna_mainloop();
+#endif /* CANNA */
 }
 
-unsigned char keyin0 ();
-
 int
-keyin2 ()
+keyin2 (void)
 {
   int total, ret;
   unsigned char in;
@@ -1031,31 +1268,30 @@ keyin2 ()
 
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
 }
 
 /** キー入力関数 2 */
-unsigned char
-keyin0 ()
+static unsigned char
+keyin0 (void)
 {
   static unsigned char buf[BUFSIZ];
   static unsigned char outbuf[BUFSIZ];
   static unsigned char *bufend = outbuf;
   static unsigned char *bufstart = outbuf;
   int n;
-  int rfds;
-  int i, j, mask;
+  fd_set rfds, mask;
+  int i, j;
   unsigned char *p;
   extern int henkan_off_flag;
   struct timeval time_out;      /* If your OS's select was implemented as 
@@ -1097,9 +1333,10 @@ keyin0 ()
       time_out.tv_usec = 200 * 1000;    /* 200 msec 間待つのだゾ! */
       for (rfds = sel_ptn;
 #ifdef linux
-           (sel_ret = select (20, &rfds, 0, 0, NULL)) < 0 && errno == EINTR;
+           (sel_ret = select (FD_SETSIZE, &rfds, 0, 0, NULL)) < 0 && errno == EINTR;
 #else
-           (sel_ret = select (20, &rfds, 0, 0, &time_out)) < 0 && errno == EINTR;
+	   /* FD_SETSIZE should be 20 in classical env. */
+           (sel_ret = select (FD_SETSIZE, &rfds, 0, 0, &time_out)) < 0 && errno == EINTR;
 #endif
            rfds = sel_ptn)
         ;
@@ -1113,12 +1350,9 @@ keyin0 ()
               return (*bufstart++);
             }
           return (0xff);
-/*
-            continue;
-*/
         }
 
-      if (rfds & pty_bit)
+      if (FD_ISSET(ptyfd, &rfds))
         {
           if ((n = read (ptyfd, buf, BUFSIZ)) <= 0)
             {
@@ -1150,13 +1384,14 @@ keyin0 ()
                       p += j;
                       i -= j;
                     }
-                  mask = 1 << ttyfd;
+		  FD_ZERO (&mask);
+		  FD_SET (ttyfd, &mask);
                   select (32, 0, &mask, 0, 0);
                 }
               pop_cursor ();
             }
         }
-      if (rfds & tty_bit)
+      if (FD_ISSET(ttyfd, &rfds))
         {
           if ((n = read (ttyfd, buf, BUFSIZ)) > 0)
             {
@@ -1197,16 +1432,16 @@ keyin0 ()
 #if defined(uniosu)
 /** pty から ioctl がかかった時の処理 */
 int
-arrange_ioctl (jflg)
-     int jflg;                  /* jtermio の j_flg の変換フラグがオフの時 0 オンの時 1 */
+arrange_ioctl (int jflg)
+/* jflg: jtermio の j_flg の変換フラグがオフの時 0 オンの時 1 */
 {
   struct jtermio jbuf1;
-  struct termio frombuf;
-  struct termio tobuf;
+  struct TERMIO frombuf;
+  struct TERMIO tobuf;
   int i;
 
-  ioctl (ptyfd, TCGETA, &frombuf);
-  ioctl (ttyfd, TCGETA, &tobuf);
+  GET_TERMATTR (ptyfd, &frombuf);
+  GET_TERMATTR (ttyfd, &frombuf);
 
   if ((i = (frombuf.c_iflag & IXON)) != (tobuf.c_iflag & IXON))
     {
@@ -1243,7 +1478,7 @@ arrange_ioctl (jflg)
     }
   tobuf.c_cflag = (tobuf.c_cflag & ~CBAUD) | (frombuf.c_cflag & CBAUD);
 
-  ioctl (ttyfd, TCSETA, &tobuf);        /* set again */
+  SET_TERMATTR (ttyfd, &tobuf);		/* set again */
 
   ioctl (ptyfd, JTERMGET, &jbuf1);      /* about Japanease */
 
@@ -1269,28 +1504,66 @@ arrange_ioctl (jflg)
 
 /** 子プロセスを起こす。*/
 
-int ttypfd;
+int ttypfd = -1;	/* slave tty */
 
 static void
-exec_cmd (argv)
-     char **argv;
+exec_cmd (char **argv)
 {
   int i;
+#if defined(HAVE_LIBSPT) && !defined(USE_LINUX_TERM)
+  int r;
+  const char *ttynm;
+#elif !defined(HAVE_SETSID) || defined(USE_LINUX_TERM)
 #ifdef BSD42
   int pid;
 #endif
-#ifdef linux
+#endif /* (!HAVE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
+#if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
   struct winsize win;
-  extern Term_RowWidth, crow;
+  extern int Term_RowWidth;
 #endif
-#if defined(SYSVR2) && !defined(linux)
-  setpgrp ();
-  close (open (ttyname (ttypfd), O_WRONLY, 0));
-#endif /* SYSVR2 */
 
-  if (!(child_id = fork ()))
-    {
-#ifdef BSD42
+  child_id = fork ();
+  if (child_id < 0)
+    uum_err ("cannot fork.");
+  if (!child_id)
+    {
+      /* --- start changing controlling tty --- */
+#if defined(HAVE_LIBSPT) && !defined(USE_LINUX_TERM)
+#if defined(SIGWINCH) && defined(TIOCSWINSZ)
+      if (ioctl (ttyfd, TIOCGWINSZ, &win) == 0)
+	ioctl (ttypfd, TIOCSWINSZ, &win);
+#endif /* SIGWINCH && TIOCSWINSZ */
+      spt_detach_handle (spth);
+      spth = NULL;
+      if (spt_detach_ctty () || spt_set_ctty2 (ttypfd))
+	{
+	  uum_err ("cannot change controlling tty.");
+	}
+
+#elif defined(HAVE_SETSID) && !defined(USE_LINUX_TERM) /* !HAVE_LIBSPT */
+
+      int fd;
+# if defined(SIGWINCH) && defined(TIOCSWINSZ)
+      if (ioctl (ttyfd, TIOCGWINSZ, &win) == 0)
+	ioctl (ttypfd, TIOCSWINSZ, &win);
+# endif /* SIGWINCH && TIOCSWINSZ */
+      setsid ();
+# ifdef TIOCSCTTY
+      ioctl (ttypfd, TIOCSCTTY, 0);
+# else
+      close (open (ttyname (ttypfd), O_WRONLY, 0));
+# endif
+      if ((fd = open("/dev/tty", O_WRONLY)) < 0)
+	{
+	  uum_err ("cannot change controlling tty.");
+	}
+      close (fd);
+      /* disable utmp logging for now */
+
+#else /* (!HAVE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
+
+#ifdef BSD42
 #ifdef TIOCNOTTY
       /* set notty */
       {
@@ -1313,26 +1586,49 @@ exec_cmd (argv)
       close (open (ttyname (ttypfd), O_WRONLY, 0));
       setpgrp (0, pid);
 #endif /* BSD42 */
-
-#if !(defined(BSD) && (BSD >= 199306))
+#if defined(SYSVR2) && !defined(linux)
+      setpgrp (); /* should setpgrp() AFTER fork() */
+      close (open (ttyname (ttypfd), O_WRONLY, 0));
+#endif /* SYSVR2 */
+ 
+#if 0
+/* unneccessary? */
+      /* setutmp() does utmp handling if USE_UTMP is set to 1 */
       if (setutmp (ttypfd) == ERROR)
         {
           puts ("Can't set utmp.");
         }
+      else
+	{
+	  need_utmp_clear = 1;
+	}
 #endif
 
-#ifdef linux
+/* It is bizarre to open tty after fork().
+   So, try to do same as other os.
+   If it does work, we can remove this. */
+# ifdef linux
       setsid ();
       open_ttyp ();
       close (ptyfd);
-      ioctl (ttyfd, TIOCGWINSZ, &win);
       ioctl (ttypfd, TCSETA, &savetmio);
+# endif
+# if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
+      ioctl (ttyfd, TIOCGWINSZ, &win);
+# endif
+
+#endif	/* (!HAVE_LIBSPT && !HAVE_SETSID) || USE_LINUX_TERM */
+      /* --- finish changing controlling tty --- */
+
+#ifndef linux
+      setgid (getgid ());
+      setuid (getuid ());
+#endif
+#ifdef HAVE_DUP2
       dup2 (ttypfd, 0);
       dup2 (ttypfd, 1);
       dup2 (ttypfd, 2);
-#else /* linux */
-      setgid (getgid ());
-      setuid (getuid ());
+#else /* !HAVE_DUP2 */
       close (0);
       close (1);
       close (2);
@@ -1340,7 +1636,7 @@ exec_cmd (argv)
         {
           uum_err ("redirection fault.");
         }
-#endif /* linux */
+#endif /* !HAVE_DUP2 */
       for (i = WNN_NFD - 1; i > 2; i--)
         {
           close (i);
@@ -1358,19 +1654,50 @@ exec_cmd (argv)
       signal (SIGTTOU, SIG_IGN);
 #endif
 
-/*      if (setutmp(0) == ERROR) {
-            err("Can't set utmp.");
-        } 
-*/
-#ifdef linux
+#if defined(SIGWINCH) && defined(TIOCSWINSZ) /* || defined(linux) */
       crow = win.ws_row = Term_RowWidth = win.ws_row - conv_lines;
       ioctl (ttyfd, TIOCSWINSZ, &win);
+#endif
+#ifdef linux
       setgid (getgid ());
       setuid (getuid ());
 #endif
       execvp (cmdnm, argv);
       uum_err ("exec fault.");
     }
+
+  /* parent */
+#ifdef HAVE_LIBSPT
+  ttynm = ttyname (0);
+  if (ttynm)
+    {
+      ttynm = strchr (ttynm + 1, '/');
+      if (ttynm && ttynm[1])
+	{
+	  spt_utmp_set_host (spth, ttynm + 1);
+	}
+    }
+  spt_utmp_set_pid (spth, child_id);
+  r = spt_login_utmp (spth);
+  if (!r)
+    {
+      need_utmp_clear = 1;
+    }
+  else
+    {
+      spt_perror ("exec_cmd (login_utmp)", r);
+    }
+#else	/* !HAVE_LIBSPT */
+      /* setutmp() does utmp handling if USE_UTMP is set to 1 */
+      if (setutmp (ttypfd) == ERROR)
+        {
+          puts ("Can't set utmp.");
+        }
+      else
+	{
+	  need_utmp_clear = 1;
+	}
+#endif /* HAVE_LIBSPT */
 }
 
 #if !(HAVE_SETENV)
@@ -1381,10 +1708,7 @@ exec_cmd (argv)
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
@@ -1424,9 +1748,7 @@ setenv (var, value, overwrite)
 
 #ifdef SVR4
 static int
-euc_set (eucioc, ttyfd)
-     eucioc_t *eucioc;
-     int ttyfd;
+euc_set (eucioc_t *eucioc, int ttyfd)
 {
   struct strioctl sb;
 
@@ -1442,8 +1764,7 @@ euc_set (eucioc, ttyfd)
 }
 
 static int
-set_euc_term (ttyfd)
-     int ttyfd;
+set_euc_term (int ttyfd)
 {
   eucioc_t eucioc;
 
@@ -1468,8 +1789,7 @@ set_euc_term (ttyfd)
 
 #ifdef nec_ews_svr2
 static void
-set_jterm (ttyfd, ttypfd)
-     int ttyfd, ttypfd;
+set_jterm (int ttyfd, int ttypfd)
 {
   struct jtermio buf;
 
@@ -1488,228 +1808,285 @@ set_jterm (ttyfd, ttypfd)
 }
 #endif /* nec_ews_svr2 */
 
-/** ttyp のオープン */
-
-int ptyno;
-char *ptynm = "/dev/pty";
-#ifdef sgi
-extern char *_getpty (int *, int, mode_t, int);
-char *ttypnm = "/dev/ttyqxxx";
-#else
-char *ttypnm = "/dev/tty";
-#endif /* sgi */
-
-#if defined(BSD43) || defined(DGUX)     /* FOR PASS8 */
-static int local_mode_sv;
-#endif
-
-#ifndef sgi
-static void ptyname ();
-#endif
-
+#ifdef sony
 static void
-open_ttyp ()
+set_sony_jterm (int ttyfd, int ttypfd)
 {
-  char nmbuf[20];
-#ifdef BSD42
-  int word;
-#endif
-#if defined(SYSVR2) && !defined(linux)
-  struct termio buf1;
-#endif
-#if defined(uniosu)
-  struct jtermio buf2;
-#endif
-
-#ifdef sgi
-  if ((ttypfd = open (ttypnm, O_RDWR)) == ERROR)
-    {
-#else
-  ptyname (nmbuf, ttypnm, ptyno);
-  if ((ttypfd = open (nmbuf, O_RDWR, 0)) == ERROR)
-    {
-#endif
-      uum_err ("Can't open ttyp.");
-    }
-#ifndef linux
-  chown (nmbuf, getuid (), getgid ());
-  chmod (nmbuf, 0622);
-#endif /* !linux */
-#ifdef BSD42
-  ioctl (ttyfd, TIOCGETC, &tcharsv);
-  ioctl (ttyfd, TIOCGLTC, &ltcharsv);
-  ioctl (ttyfd, TIOCGETP, &ttyb);
-  savetmio = ttyb;
-#if defined(BSD43) || defined(DGUX)
-  ioctl (ttyfd, TIOCLGET, &local_mode_sv);
-  local_mode = local_mode_sv | LPASS8;  /* set PASS8 */
-  ioctl (ttyfd, TIOCLSET, &local_mode);
-#else /* defined(BSD43) || defined(DGUX) */
-  ioctl (ttyfd, TIOCLGET, &local_mode);
-#endif /* defined(BSD43) || defined(DGUX) */
+#ifdef TIOCKGET
+  int tmode, jmode = 0;
+  struct jtchars jtc;
 
-  ioctl (ttypfd, TIOCSETC, &tcharsv);
-  ioctl (ttypfd, TIOCSLTC, &ltcharsv);
-  ioctl (ttypfd, TIOCSETP, &ttyb);
-  ioctl (ttypfd, TIOCLSET, &local_mode);
-#ifdef notdef
-  pid = getpid ();
-  ioctl (ttypfd, TIOCSPGRP, &pid);
-#endif
-  if (pty_c_flag == J_JIS)
+  if (ioctl(ttyfd, TIOCKGET, &tmode) < 0)
     {
-      word = LCTLECH;
-      ioctl (ttypfd, TIOCLBIC, &word);
-    }
-#endif /* BSD42 */
-#if defined(SYSVR2) && !defined(linux)
-  if (ioctl (ttyfd, TCGETA, &buf1) == -1)
-    {
-      buf1 = terms;
-    }
-  savetmio = buf1;
-#ifdef DGUX                     /* copied from JLS5.4.2 */
-  buf1.c_iflag &= ~ISTRIP;
-#endif /* DGUX */
-#ifdef nec_ews_svr2
-  buf1.c_line = JAPANLD;
-#endif
-  if (ioctl (ttypfd, TCSETA, &buf1) < 0)
-    {
-      fprintf (stderr, "error in ioctl TCSETA.\n");
+      fprintf(stderr, "error in ioctl TIOCKGET.\n");
       exit (1);
     }
-#if defined(uniosu)
-  if (ioctl (ttyfd, JTERMGET, &buf2) < 0)
+  jmode = tmode;
+  tmode &= ~(KM_SYSCODE | KM_TTYPE);
+  switch (pty_c_flag)
     {
-      fprintf (stderr, "uum: error in ioctl JTERMGET in open_ttyp.\n");
-      exit (1);
-    }
-  savejtmiottyp = buf2;
-  buf2.j_flg = CONVTOEXT | KANJIINPUT;  /* kanji input & output ok */
-  buf2.j_level = jterm;
-  switch (jcode_set)
-    {
-    case 0:
-      buf2.j_ecode = JIS;
+    case J_EUJIS:
+      tmode |= KM_EUC | KM_SYSEUC;
       break;
-    case 1:
-      buf2.j_ecode = SJIS;
+    case J_JIS:
+      tmode |= KM_ASCII;
       break;
-    case 2:
-      buf2.j_ecode = UJIS;
+    case J_SJIS:
+      tmode |= KM_SJIS | KM_SYSSJIS;
       break;
-    default:
-      fprintf (stderr, "uum: kanji code set not supported in terminfo.\n");
-      exit (1);
-    }
-
-  if (jis_kanji_in)
-    {
-      strcpy (buf2.j_jst, jis_kanji_in);
-      buf2.j_jstl = strlen (jis_kanji_in);
-    }
-  if (jis_kanji_out)
-    {
-      strcpy (buf2.j_jend, jis_kanji_out);
-      buf2.j_jendl = strlen (jis_kanji_out);
-    }
-  if (jgaiji_start_address)
-    {
-      *(short *) buf2.j_gcsa = jgaiji_start_address;
-    }
-  if (jgaiji_disp)
-    {
-      strcpy (buf2.j_gdsp, jgaiji_disp);
-      buf2.j_gdspl = strlen (jgaiji_disp);
     }
-
-  if (ioctl (ttypfd, JTERMSET, &buf2) < 0)
+  if (ioctl(ttypfd, TIOCKSET, &tmode) < 0)
     {
-      fprintf (stderr, "error in ioctl JTERMSET.\n");
+      fprintf(stderr, "error in ioctl TIOCKSET.\n");
       exit (1);
     }
+#endif /* TIOCKGET */
 
-  if (ioctl (ttypfd, TIOCSETAUX, &auxterm) < 0)
+#ifdef TIOCKGETC    
+  if ((jmode & KM_TTYPE) == KM_JIS)
     {
-      fprintf (stderr, "error in ioctl TIOCSETAUX.\n");
-      exit (1);
+      ioctl(ttyfd, TIOCKGETC, &jtc);
+      jtc.t_ascii = 'B';
+      jtc.t_kanji = 'B';
+      if (ioctl(ttypfd, TIOCKSETC, &jtc) < 0)
+	{
+	  fprintf(stderr, "error in ioctl TIOCKSETC.\n");
+	  exit(1);
+	}
     }
+#endif
+}
+#endif /* sony */
 
-/*
-    pid = getpid();
+/** ttyp のオープン */
+
+#ifndef HAVE_LIBSPT
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
 */
-#endif /* defined(uniosu) */
 
-#if defined(nec_ews_svr2)
-  set_jterm (ttyfd, ttypfd);
+#if !defined(sgi) && !defined(HAVE_PTSNAME)
+char tty_master[32]; /*VVVV overflow?*/
+#endif
+char tty_slave [32]; /*VVVV overflow?*/
+
+#if defined(BSD43) || defined(DGUX)	/* FOR PASS8 */
+static int local_mode_sv;
+#endif
+#endif /* !HAVE_LIBSPT */
+
+/* open slave side of pty to ttypfd */
+static void
+open_ttyp (void)
+{
+#ifndef HAVE_LIBSPT	 /* && !defined(linux) ? */
+  struct stat tstat;
+  char chown_failed = 0;
+  const char *msg_insecure = "Your ttyp (%s) may be insecure from other users, but continue anyway ...\r\n";
+#endif	/* !HAVE_LIBSPT */
+
+#ifdef HAVE_LIBSPT
+  if ((ttypfd = spt_open_slave(spth)) == ERROR)
+#else /* HAVE_LIBSPT */
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
+#endif /* HAVE_LIBSPT */
+    {
+      perror(tty_slave);	/* debug */
+      uum_err ("Can't open ttyp.");
+    }
+#if defined(HAVE_LIBSPT)
+  spt_init_slavefd(spth, ttypfd);
+#else	/* HAVE_LIBSPT */
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
+#endif /* HAVE_LIBSPT */
+
+  /*
+   * We save terminal settings in main() instead of here.
+   * When defined(linux) open_ttyp() is invoked from child!
+   */
+#ifndef USE_LINUX_TERM
+  j_term_p_init (ttypfd);
 #endif
 
-/*
-    setpgrp();
-    close(open(ttyname(ttypfd), O_WRONLY, 0));
-*/
-#endif /* defined(SYSVR2) && !defined(linux) */
 #ifdef TIOCSSIZE
   pty_rowcol.ts_lines = crow;   /* instead of lines */
   pty_rowcol.ts_cols = maxlength;       /* instead of columns */
   ioctl (ttypfd, TIOCSSIZE, &pty_rowcol);
 #endif /* TIOCSSIZE */
+
+#ifdef SVR4
+  set_euc_term(ttypfd);
+#endif
+#if defined(nec_ews_svr2)
+  set_jterm (ttyfd, ttypfd);
+#endif
+#ifdef sony
+  set_sony_jterm(ttyfd, ttypfd);
+#endif
+}
+
+#if defined(HAVE_PTSNAME) && ! defined(HAVE_POSIX_OPENPT)
+/* Maybe harmless on defined(HAVE_LIBSPT) */
+#if !defined(HAVE__DEV_PTMX)
+#warning "If not cross compile, you must check pts master device (other than /dev/ptmx)."
+/* but continue anyway. */
+#endif
+
+/* fallback function to posix_openpt */
+static int
+posix_openpt (int flags)
+{
+  return open("/dev/ptmx", flags);
 }
+#endif		/* HAVE_PTSNAME && !HAVE_POSIX_OPENPT */
 
 /** pty のオープン */
-#ifdef sgi
+/* allocate a new pty master into int ptyfd */
 static void
-open_pty ()
+open_pty (void)
 {
-  char nmbuf[20];
+#if defined(HAVE_LIBSPT)
+  int r;
+  r = spt_open_pty(&spth, &ptyfd, NULL, NULL);
+  if (r != SPT_E_NONE && r != SPT_E_CHOWN_FAIL)
+    uum_err ("Can't get pty.");
+
+#elif defined(sgi)
   char *tty_name_buff;
+  extern char *_getpty (int *, int, mode_t, int);
   tty_name_buff = _getpty (&ptyfd, O_RDWR | O_NDELAY, 0600, 0);
   if (tty_name_buff == 0)
     uum_err ("Can't get pty.");
-  strcpy (ttypnm, tty_name_buff);
-  return;
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
+#endif /* HAVE_LIBSPT */
+
+  return;
+}
+
+#if !(HAVE_LIBSPT) && !(sgi) && !(HAVE_PTSNAME) && !(HAVE_OPENPTY)
 static void
-open_pty ()
+open_pty_traditional (void)
 {
-  char nmbuf[20];
-#ifdef linux
-  struct termio buf1;
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
 #endif
 
-  for (ptyno = 0; ptyno < 32; ptyno++)
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
+    sprintf ((b), PFX "%1c%1c", "pqrsPQRS"[((no) >> 5)], "0123456789abcdefghijklmnopqrstuv"[(no) & 0x1f])
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
-#ifdef linux
-          if (ioctl (0, TCGETA, &buf1) == -1)
-            {
-              buf1 = terms;
-            }
-          savetmio = buf1;
-#endif
+# endif /* uniosu */
           return;
         }
     }
   uum_err ("Can't get pty.");
 }
-#endif
+#endif /* !(HAVE_LIBSPT) && !(sgi) && !(HAVE_PTSNAME) && !(HAVE_OPENPTY) */
 
 /** エラーだよ。さようなら。 */
 void
-uum_err (s)
-     char *s;
+uum_err (char *s)
 {
   puts (s);
   fclose (stdout);
@@ -1720,9 +2097,11 @@ uum_err (s)
 
 /** 立つ鳥後を濁さず 終わりの処理 */
 static void
-do_end ()
+do_end (void)
 {
-  char nmbuf[20];
+#ifdef USE_LIBSPT
+  int r;
+#endif
 
   static int do_end_flg = 0;
   if (do_end_flg == 1)
@@ -1731,89 +2110,64 @@ do_end ()
 
   signal (SIGCHLD, SIG_DFL);
   fcntl (ttyfd, F_SETFL, 0);
+  j_term_restore ();
 
-#ifdef BSD42
-  ioctl (ttyfd, TIOCSETP, &savetmio);
-#endif /* BSD42 */
-#if defined(BSD43) || defined(DGUX)
-  ioctl (ttyfd, TIOCLSET, &local_mode_sv);
-#endif /* BSD43 */
-
-#ifdef SYSVR2
-  if (ioctl (ttyfd, TCSETA, &savetmio) < 0)
+#if !defined(HAVE_LIBSPT) && !defined(sgi)
+# ifndef HAVE_PTSNAME
+  if (chown (tty_master, 0, 0) == ERROR)
     {
-      fprintf (stderr, "error in ioctl TCSETA.\n");
-      exit (1);
+      perror ("Can't restore owner of tty_master.");
     }
-#endif /* SYSVR2 */
-
-#if defined(uniosu)
-  if (ioctl (ttyfd, JTERMSET, &savejtmio) < 0)
+  if (chmod (tty_master, 0666) == ERROR)
     {
-      fprintf (stderr, "error in ioctl JTERMSET.\n");
-      exit (1);
+      perror ("Can't restore permission of tty_master.");
     }
-#endif /* defined(uniosu) */
 
-#ifndef sgi
-  ptyname (nmbuf, ptynm, ptyno);
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
 
-  ptyname (nmbuf, ttypnm, ptyno);
-  if (chown (nmbuf, 0, 0) == ERROR)
-    {
-      perror (prog);
-    }
-  if (chmod (nmbuf, 0666) == ERROR)
-    {
-      perror (prog);
-    }
-
-#if !(defined(BSD) && (BSD >= 199306))
-  if (resetutmp (ttypfd) == ERROR)
+#endif /* !HAVE_LIBSPT && !sgi */
+  close (ttyfd);
+#ifdef HAVE_LIBSPT
+  if (spth && need_utmp_clear && (r = spt_logout_utmp(spth)))
+    spt_perror(NULL, r);
+  if (spth && (r = spt_close_pty(spth)))
+    spt_perror(NULL, r);
+#else
+/* needless? */
+  /* resetutmp() does utmp handling if USE_UTMP is set to 1 */
+  if (need_utmp_clear)
     {
-      printf ("Can't reset utmp.");
+      if (resetutmp (ttypfd) == ERROR)
+	{
+	  printf ("Can't reset utmp.");
+	}
+      need_utmp_clear = 0;	/* for safety */
     }
-#endif
-#ifdef TIOCSSIZE
-  pty_rowcol.ts_lines = 0;
-  pty_rowcol.ts_cols = 0;
-  ioctl (ttypfd, TIOCSSIZE, &pty_rowcol);
-#endif /* TIOCSSIZE */
-#endif /* !sgi */
-  close (ttyfd);
   close (ptyfd);
+#endif /* HAVE_LIBSPT */
 
   chdir ("/tmp");               /* to avoid making too many mon.out files */
 
-
-#ifdef BSD42
-  killpg (child_id, SIGHUP);
-/*    killpg(getpgrp(),SIGHUP);  */
-#endif
-#ifdef SYSVR2
-/*    kill(0, SIGHUP); */
-  kill (-child_id, SIGHUP);
-#endif /* SYSVR2 */
-
+  KILLPG (child_id, SIGHUP);
   exit (0);
 }
 
 #if defined(uniosu)
 /** 仮名漢字変換を ioctl でオフした時の keyin に代わる関数 */
 int
-ioctl_off ()
+ioctl_off (void)
 {
   static unsigned char buf[BUFSIZ];
   int n;
-  int rfds;
+  fd_set rfds;
 
   kk_restore_cursor ();
   clr_line_all ();
@@ -1826,8 +2180,8 @@ ioctl_off ()
           write (ptyfd, buf, n);
         }
       rfds = sel_ptn;
-      select (20, &rfds, 0, 0, NULL);
-      if (rfds & pty_bit)
+      select (FD_SETSIZE, &rfds, 0, 0, NULL);
+      if (FD_ISSET(ptyfd, &rfds))
         {
           if ((n = read (ptyfd, buf, BUFSIZ)) <= 0)
             {
@@ -1846,7 +2200,7 @@ ioctl_off ()
                 }
             }
         }
-      if (rfds & tty_bit)
+      if (FD_ISSET(ttyfd, &rfds))
         {
           if ((n = read (ttyfd, buf, BUFSIZ)) > 0)
             {
@@ -1857,47 +2211,15 @@ ioctl_off ()
 }
 #endif /* defined(uniosu) */
 
-
-#ifndef sgi
-static void
-ptyname (b, pty, no)
-     char *b, *pty;
-     int no;
-{
-/*
- * Change pseudo-devices.
- * Because FreeBSD's master pseudo-devices are pty[p-sP-S][0-9a-v].
- * Patched by Hidekazu Kuroki(hidekazu@cs.titech.ac.jp)         1996/8/20
- */
-#if (defined(BSD) && (BSD >= 199306))   /* 4.4BSD-Lite by Taoka */
-  sprintf (b, "%s%1c%1c", pty, "pqrsPQRS"[(no >> 5)], ((no & 0x1f > 9) ? 'a' : '0') + (no & 0x1f));
-#else /* ! 4.4BSD-Lite */
-  sprintf (b, "%s%1c%1x", pty, 'p' + (no >> 4), no & 0x0f);
-#endif /* ! 4.4BSD-Lite */
-}
-#endif /* !sgi */
-
-/* Move to etc/xutoj.c
-int
-through(x, y, z)
-char *x, *y;
-int z;
-{
-    bcopy(y, x, z);
-    return z;
-}
-*/
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
@@ -1913,10 +2235,9 @@ intfnptr sigwinch;
 #endif /* SIGWINCH */
 
 static void
-save_signals ()
+save_signals (void)
 {
   sigpipe = signal (SIGPIPE, SIG_IGN);
-/*     sighup  = signal(SIGHUP,  SIG_IGN); /88/12/27*/
 #ifdef linux                    /* XXX */
   sighup = signal (SIGHUP, SIG_IGN);
 #endif
@@ -1936,7 +2257,7 @@ save_signals ()
 }
 
 static void
-restore_signals ()
+restore_signals (void)
 {
   signal (SIGPIPE, sigpipe);
   signal (SIGHUP, sighup);
@@ -1956,11 +2277,11 @@ restore_signals ()
 
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
@@ -1983,11 +2304,11 @@ setsize ()
 
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
@@ -2002,7 +2323,7 @@ change_size ()
       if ((i = win.ws_row) != 0)
         {
           crow = Term_RowWidth = i - conv_lines;
-#ifdef linux
+#ifdef TIOCSWINSZ
           win.ws_row = crow;
 #endif
         }
@@ -2010,9 +2331,9 @@ change_size ()
         {
           maxlength = Term_LineWidth = i;
         }
-#ifdef linux
+#ifdef TIOCSWINSZ
       ioctl (ttypfd, TIOCSWINSZ, &win);
-#else /* linux */
+#else /* !TIOCSWINSZ */
 #ifdef  TIOCSSIZE
       pty_rowcol.ts_lines = crow;       /* instead of lines */
       pty_rowcol.ts_cols = maxlength;   /* instead of columns */
@@ -2022,15 +2343,12 @@ change_size ()
       {
         int grp;
         ioctl (ptyfd, TIOCGPGRP, &grp);
-#ifdef SVR4
-        kill (-grp, SIGWINCH);
-#else
-        killpg (grp, SIGWINCH);
-#endif
+	KILLPG (grp, SIGWINCH);
       }
 #endif /* sun */
-#endif /* linux */
+#endif /* !TIOCSWINSZ */
 
+#ifndef CANNA
       set_scroll_region (0, crow - 1);
       if (henkan_off_flag)
         {
@@ -2051,6 +2369,11 @@ change_size ()
           set_screen_vars_default ();
           t_print_l ();
         }
+#else /* CANNA */
+      set_scroll_region(0, crow - 1);
+      set_screen_vars_default();
+      t_print_l();
+#endif /* CANNA */
     }
 }
 #endif /* SIGWINCH */

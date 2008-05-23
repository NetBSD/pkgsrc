/*
 * This file, acconfig.h, which is a part of pdksh (the public domain ksh),
 * is placed in the public domain.  It comes with no licence, warranty
 * or guarantee of any kind (i.e., at your own risk).
 */

#ifndef CONFIG_H
#define CONFIG_H

@TOP@

/* Define if your kernal doesn't handle scripts starting with #! */
#undef SHARPBANG

/* Define if dup2() preserves the close-on-exec flag (ultrix does this) */
#undef DUP2_BROKEN

/* Define as the return value of signal handlers (0 or ).  */
#undef RETSIGVAL

/* Define if you have posix signal routines (sigaction(), et. al.) */
#undef POSIX_SIGNALS

/* Define if you have BSD4.2 signal routines (sigsetmask(), et. al.) */
#undef BSD42_SIGNALS

/* Define if you have BSD4.1 signal routines (sigset(), et. al.) */
#undef BSD41_SIGNALS

/* Define if you have v7 signal routines (signal(), signal reset on delivery) */
#undef V7_SIGNALS

/* Define to use the fake posix signal routines (sigact.[ch]) */
#undef USE_FAKE_SIGACT

/* Define if signals don't interrupt read() */
#undef SIGNALS_DONT_INTERRUPT

/* Define if you have bsd versions of the setpgrp() and getpgrp() routines */
#undef BSD_PGRP

/* Define if you have POSIX versions of the setpgid() and getpgrp() routines */
#undef POSIX_PGRP

/* Define if you have sysV versions of the setpgrp() and getpgrp() routines */
#undef SYSV_PGRP

/* Define if you don't have setpgrp(), setpgid() or getpgrp() routines */
#undef NO_PGRP

/* Define to char if your compiler doesn't like the void keyword */
#undef void

/* Define to nothing if compiler doesn't like the volatile keyword */
#undef volatile

/* Define if C compiler groks function prototypes */
#undef HAVE_PROTOTYPES

/* Define if C compiler groks __attribute__((...)) (const, noreturn, format) */
#undef HAVE_GCC_FUNC_ATTR

/* Define to 32-bit signed integer type */
#undef INT32

/* Define to 32-bit signed integer type if <sys/types.h> doesn't define */
#undef clock_t

/* Define to the type of struct rlimit fields if the rlim_t type is missing */
#undef rlim_t

/* Define if time() is declared in <time.h> */
#undef TIME_DECLARED

/* Define to `unsigned' if <signal.h> doesn't define */
#undef sigset_t

/* Define if sys_errlist[] and sys_nerr are in the C library */
#undef HAVE_SYS_ERRLIST

/* Define if sys_errlist[] and sys_nerr are defined in <errno.h> */
#undef SYS_ERRLIST_DECLARED

/* Define if sys_siglist[] is in the C library */
#undef HAVE_SYS_SIGLIST

/* Define if you have a sane <termios.h> header file */
#undef HAVE_TERMIOS_H

/* Define if you can include <sys/ioctl.h> with <termios.h> */
#undef SYS_IOCTL_WITH_TERMIOS

/* Define if you can include <sys/ioctl.h> with <termio.h> */
#undef SYS_IOCTL_WITH_TERMIO

/* Define if you have a memset() function in your C library */
#undef HAVE_MEMSET

/* Define if you have a memmove() function in your C library */
#undef HAVE_MEMMOVE

/* Define if you have a bcopy() function in your C library */
#undef HAVE_BCOPY

/* Define if you have a lstat() function in your C library */
#undef HAVE_LSTAT

/* Define if you have a sane <termio.h> header file */
#undef HAVE_TERMIO_H

/* Define if you don't have times() or if it always returns 0 */
#undef TIMES_BROKEN

/* Define if opendir() will open non-directory files */
#undef OPENDIR_DOES_NONDIR

/* Define if the pgrp of setpgrp() can't be the pid of a zombie process */
#undef NEED_PGRP_SYNC

/* Define if you arg running SCO unix */
#undef OS_SCO

/* Define if you arg running ISC unix */
#undef OS_ISC

/* Define if you arg running OS2 with the EMX library */
#undef OS2

/* Define if you have a POSIX.1 compatiable <sys/wait.h> */
#undef POSIX_SYS_WAIT

/* Define if your OS maps references to /dev/fd/n to file descriptor n */
#undef HAVE_DEV_FD

/* Define if your C library's getwd/getcwd function dumps core in unreadable
 * directories.  */
#undef HPUX_GETWD_BUG

/*   ------- ------ ----- ---- --- -- - - -- --- ---- ----- ------ -------   */
/*   Defines from here on down are enable/disable options to configure */

/* Default PATH (see comments in configure.in for more details) */
#undef DEFAULT_PATH

/* Include ksh features? (see comments in configure.in for more details) */
#undef KSH

/* Include emacs editing? (see comments in configure.in for more details) */
#undef EMACS

/* Include vi editing? (see comments in configure.in for more details) */
#undef VI

/* Include job control? (see comments in configure.in for more details) */
#undef JOBS

/* Include brace-expansion? (see comments in configure.in for more details) */
#undef BRACE_EXPAND

/* Include any history? (see comments in configure.in for more details) */
#undef HISTORY

/* Include complex history? (see comments in configure.in for more details) */
#undef COMPLEX_HISTORY

/* Strict POSIX behaviour? (see comments in configure.in for more details) */
#undef POSIXLY_CORRECT

/* Specify default $ENV? (see comments in configure.in for more details) */
#undef DEFAULT_ENV

/* Include shl(1) support? (see comments in configure.in for more details) */
#undef SWTCH

/* Include game-of-life? (see comments in configure.in for more details) */
#undef SILLY

@BOTTOM@

/* Need to use a separate file to keep the configure script from commenting
 * out the undefs....
 */
#include "conf-end.h"

#endif /* CONFIG_H */

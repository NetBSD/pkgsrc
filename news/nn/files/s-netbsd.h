/* $NetBSD: s-netbsd.h,v 1.2 1998/08/07 11:11:10 agc Exp $ */

/*
 *      This version is for FreeBSD 2.1
 *      Done by "Andrey A. Chernov" <ache@astral.msk.su>
 */


/*
 *	Include header files containing the following definitions:
 *
 * 		off_t, time_t, struct stat
 */

#include <sys/types.h>
#include <sys/stat.h>   /* for S_IFREG */
#include <fcntl.h>      /* for O_RDONLY */

#define HAVE_STDLIB_H
#define HAVE_STRING_H
#define HAVE_UNISTD_H
#define HAVE_FCNTL_H

#define HAVE_TERMIOS

/*
 *	Define if your system has system V like ioctls
 */

#undef	HAVE_TERMIO			/* */

/*
 *	Define to use terminfo database.
 *	Otherwise, termcap is used
 */

#undef	USE_TERMINFO			/* */

/*
 *	Specify the library (or libraries) containing the termcap/terminfo
 *	routines.
 *
 *	Notice:  nn only uses the low-level terminal access routines
 *	(i.e. it does not use curses).
 */

#define TERMLIB	-ltermcap

/*
 *	Define HAVE_STRCHR if strchr() and strrchr() are available
 */

#define HAVE_STRCHR			/* */

/*
 *	Define if a signal handler has type void (see signal.h)
 */

#define	SIGNAL_HANDLERS_ARE_VOID	/* */

/*
 *	Define HAVE_UALARM if your system has a 4.3 BSD like ualarm() call.
 *	Else define MICRO_ALARM(n) to timeout in n/10 seconds if possible.
 *	Don't define either if system only has the standard alarm() call.
 */

#define HAVE_UALARM			/* */


/*
 *	Define if your system has BSD like job control (SIGTSTP works)
 */

#define HAVE_JOBCONTROL			/* */


/*
 *	Define if your system has a 4.3BSD like syslog library.
 */

#define HAVE_SYSLOG

/*
 *	Define if your system provides the "directory(3X)" access routines
 *
 *	If true, include the header file(s) required by the package below
 *	(remember that <sys/types.h> or equivalent is included above)
 *	Also typedef Direntry to the proper struct type.
 */

#define	HAVE_DIRECTORY			/* */

#include <dirent.h>			/* POSIX */

typedef struct dirent Direntry;		/* POSIX */

/*
 *	Define if your system has a mkdir() library routine
 */

#define	HAVE_MKDIR			/* */

/*
 *	Pick one:
 *	Define HAVE_GETHOSTNAME if you have a BSD like gethostname routine.
 *	Define HAVE_UNAME if a system V compatible uname() is available.
 *	Define HOSTNAME_FILE "...." to a file containing the hostname.
 *	Define HOSTNAME_WHOAMI if sysname is defined in <whoami.h>.
 *
 *	As a final resort, define HOSTNAME to the name of your system
 *	(in config.h).
 */

#define HAVE_GETHOSTNAME			/* BSD systems */

/*
 *	Define HAVE_MULTIGROUP if system has simultaneous multiple group
 *	membership capability (BSD style).
 *	Also define NGROUPS or include the proper .h file if NGROUPS is
 *	not defined in <sys/param.h>.
 *	Also define GIDSET_TYPE to the type of the elements in the array
 *	initialized by getgroups() if different from "int" (many systems
 *	have a gid_t, but very few use it for getgroups()).
 */

#define HAVE_MULTIGROUP	/* BSD */
#define GIDSET_TYPE     gid_t

/*
 *	Define DETATCH_TERMINAL to be a command sequence which
 *	will detatch a process from the control terminal
 *	Also include system files needed to perform this HERE.
 *	If not possible, just define it (empty)
 */

#define DETATCH_TERMINAL setsid();

/*
 *	Specify where the Bourne Shell is.
 */

#define SHELL		"/bin/sh"

/*
 *	Specify the default mailer to be invoked by nnmail
 */

#define	MAILX	"/usr/bin/mail"		/* */

/*
 *	Define the maximum length of any pathname that may occur
 */

#define	FILENAME 	256

#define RESIZING

#define HAVE_8BIT_CTYPE

#define HAVE_WORKING_COLLATE

#define PREFIX		"@@PREFIX@@"
#define BINOWN		"@@BINOWN@@"
#define BINGRP		"@@BINGRP@@"

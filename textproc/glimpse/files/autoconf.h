/*	$NetBSD: autoconf.h,v 1.2 1999/06/30 13:13:03 agc Exp $	*/

/*
 * preprocessor variables used during build of glimpse-4.1
 */

#define HAVE_DIRENT_H 1
#ifdef __NetBSD__
#define HAVE_FLOCK 1
#else
#undef HAVE_FLOCK
#endif
#define HAVE_GETDTABLESIZE 1
#define HAVE_SETLINEBUF 1
#define HAVE_SETRLIMIT 1
#define HAVE_STRDUP 1
#define HAVE_STRERROR 1
#define HAVE_SYSCONF 1

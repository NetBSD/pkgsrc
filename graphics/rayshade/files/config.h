/* config.h
 * This file was produced by running the config.h.SH script, which
 * gets its values from config.sh, which is generally produced by
 * running Configure.
 *
 * Feel free to modify any of this as the need arises.  Note, however,
 * that running config.h.SH again will wipe out any changes you've made.
 * For a more permanent change edit config.sh and rerun config.h.SH.
 */


/* EUNICE:
 *	This symbol, if defined, indicates that the program is being compiled
 *	under the EUNICE package under VMS.  The program will need to handle
 *	things like files that don't go away the first time you unlink them,
 *	due to version numbering.  It will also need to compensate for lack
 *	of a respectable link() command.
 */
/* VMS:
 *	This symbol, if defined, indicates that the program is running under
 *	VMS.  It is currently only set in conjunction with the EUNICE symbol.
 */
/* XENIX:
 *	This symbol, if defined, indicates thet the program is running under
 *	Xenix (at least 3.0 ?).
 */
/* BSD:
 *	This symbol, if defined, indicates that the program is running under
 *	a BSD system.
 */
/*#undef EUNICE		/**/
/*#undef VMS		/**/
/*#undef XENIX		/**/
#define BSD		/**/

/* CPPSTDIN:
 *	This symbol contains the first part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.	 Typical value of "cc -E" or "/lib/cpp".
 */
/* CPPMINUS:
 *	This symbol contains the second part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.  This symbol will have the value "-" if CPPSTDIN needs a minus
 *	to specify standard input, otherwise the value is "".
 */
#define CPPSTDIN "/usr/bin/cpp"
#define CPPMINUS ""

/* bzero:
 *	This symbol is maped to memset if the  bzero() routine is not
 *	available to set memory to 0.
 */
/*#undef	bzero(s,l)	memset((s),0,(l))	;	/* mapped to memset */

/* CBRT:
 *	This symbol, if defined, indicates that the cbrt() (cube root)
 *	function is available.
 */
#define	CBRT		/**/

/* index:
 *	This preprocessor symbol is defined, along with rindex, if the system
 *	uses the strchr and strrchr routines instead.
 */
/* rindex:
 *	This preprocessor symbol is defined, along with index, if the system
 *	uses the strchr and strrchr routines instead.
 */
#define	index strchr	/* cultural */
#define	rindex strrchr	/*  differences? */

/* MEMSET:
 *	This symbol, if defined, indicates that the memset routine is available
 *	to set blocks of memory. You should always use bzero() instead of
 *	memset() because bzero is remaped to memset if necessary. This means
 *	that a memset() routine must be provided in case MEMSET is not defined
 *	and no bzero() is found.
 */
#define	MEMSET		/**/

/* POPEN:
 *	This symbol, if defined, indicates that the popen routine is
 *	available to open a pipe from a process.
 */
#define POPEN		/**/

/* RUSAGE:
 *	This symbol, if defined, indicates that the getrusage() routine exists.
 *	Inclusion of <sys/resource.h> and <sys/time.h> may be necessary.
 */
#define	RUSAGE		/**/

/* TIMES:
 *	This symbol, if defined, indicates that the times() routine exists.
 *	Note that this became obsolete on some systems (SUNOS), which now
 * use getrusage().
 */
/* CLOCKTYPE:
 *	This symbol holds the type returned by times(). It can be long,
 *	or clock_t on BSD sites (in which case <sys/types.h> should be
 *	included). Moreover, the Clock_t symbol is defined in common.h
 *	and should be used for easy clean reference.
 */
#define TIMES		/**/
#define CLOCKTYPE clock_t		/**/

/* I_STRING:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <string.h> (USG systems) instead of <strings.h> (BSD systems).
 */
#define I_STRING		/**/

/* I_SYSRESOURCE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/resource.h>.
 */
#define	I_SYSRESOURCE		/**/

/* I_SYSTYPES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/types.h>.
 */
#define	I_SYSTYPES		/**/

/* I_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <time.h>.
 */
/* I_SYSTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h>.
 */
/* I_SYSTIMEKERNEL:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h> with KERNEL defined.
 */
/*#undef I_TIME		/**/
#define I_SYSTIME		/**/
/*#undef I_SYSTIMEKERNEL		/**/

/* nrand:
 *	This macro is to be used to generate uniformly distributed
 *	random numbers over the range [0., 1.].
 */
/* seednrand:
 *	This symbol defines the macro to be used in seeding the
 *	random number generator (see nrand).
 */
#define nrand()		drand48()		/**/
#define seednrand(x)	srand48(x)	/**/

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *	    8 = suports declaration of generic void pointers
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including config.h, or by defining defvoidused in Myinit.U.  If the
 *	latter approach is taken, only those flags will be tested.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED 11
#endif
#define VOIDFLAGS 11
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID		/* Xenix strikes again */
#endif

/* URT:
 *     This symbol, if defined, indicates that the Utah Raster
 *	Toolkit is being used.
 */
#define       URT          /**/

/* I_VARARGS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <stdlib.h>.
 */
#define I_STDLIB		/**/


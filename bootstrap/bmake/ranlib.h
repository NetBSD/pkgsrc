/*	@(#)ranlib.h 1.6 88/08/19 SMI; from UCB 4.1 83/05/03	*/
/*	$Id: ranlib.h,v 1.1.1.1 2004/03/11 13:04:12 grant Exp $	*/

/*
 * Structure of the __.SYMDEF table of contents for an archive.
 * __.SYMDEF begins with a word giving the number of ranlib structures
 * which immediately follow, and then continues with a string
 * table consisting of a word giving the number of bytes of strings
 * which follow and then the strings themselves.
 * The ran_strx fields index the string table whose first byte is numbered 0.
 */

#ifndef IRIX
#ifndef _ranlib_h
#define _ranlib_h

/* #define RANLIBMAG	"!<arch>\n__.SYMDEF"	/* archive file name */
#define RANLIBMAG	"__.SYMDEF"	/* archive file name */
#define RANLIBSKEW	3		/* creation time offset */

struct	ranlib {
	union {
		off_t	ran_strx;	/* string table index of */
		char	*ran_name;	/* symbol defined by */
	} ran_un;
	off_t	ran_off;		/* library member at this offset */
};

#endif /*!_ranlib_h*/
#endif

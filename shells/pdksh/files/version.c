/*	$NetBSD: version.c,v 1.2 2008/05/31 16:47:37 tnn Exp $	*/

/*
 * value of $KSH_VERSION (or $SH_VERSION)
 */
#include <sys/cdefs.h>

#ifndef lint
__RCSID("$NetBSD: version.c,v 1.2 2008/05/31 16:47:37 tnn Exp $");
#endif


#include "sh.h"

char ksh_version [] =
	"@(#)PD KSH v5.2.14 99/07/13.2";

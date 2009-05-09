/*
 * $OpenBSD: pathnames.h,v 1.1 2003/07/29 20:10:17 millert Exp $
 * $DragonFly: src/usr.bin/patch/pathnames.h,v 1.2 2008/08/11 00:04:12 joerg Exp $
 * $NetBSD: pathnames.h,v 1.3 2009/05/09 20:15:35 joerg Exp $
 */

/*
 * Placed in the public domain by Todd C. Miller <Todd.Miller@courtesan.com>
 * on July 29, 2003.
 */

#include <nbcompat/paths.h>

#ifndef _PATH_DEVNULL
#define	_PATH_DEVNULL		"/dev/null"
#endif

#ifndef _PATH_ED
#define	_PATH_ED		"/bin/ed"
#endif

#ifndef _PATH_TTY
#define	_PATH_TTY		"/dev/tty"
#endif

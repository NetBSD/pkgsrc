/*	$NetBSD: if_tap_stub.c,v 1.3 2005/06/10 15:06:33 cube Exp $	*/

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: if_tap_stub.c,v 1.3 2005/06/10 15:06:33 cube Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/proc.h>
#include <sys/file.h>
#include <sys/filedesc.h>
#include <sys/stat.h>

#include "if_tap_stub.h"

/*
 * fdclone() and friends
 */

/* 2.99.10 is gray area.  Oh, well. */
#if __NetBSD_Version__ < 299001100
int
tap_fdclone(struct proc *p, struct file *fp, int flags, int fd,
    struct fileops *fops, void *data)
{
	fp->f_flag = flags;
	fp->f_type = DTYPE_MISC;
	fp->f_ops = fops;
	fp->f_data = data;

	curlwp->l_dupfd = fd;

	FILE_SET_MATURE(fp);
	FILE_UNUSE(fp, p);
	return ENXIO;
}

/* ARGSUSED */
int
tap_fnullop_fcntl(struct file *fp, u_int cmd, void *data, struct proc *p)
{
	if (cmd == F_SETFL)
		return 0;

	return EOPNOTSUPP;
}

/* ARGSUSED */
int
tap_fbadop_stat(struct file *fp, struct stat *sb, struct proc *p)
{
	return EOPNOTSUPP;
}
#endif

/*
 * hexdigits
 */

#if __NetBSD_Version__ < 399000400
const char tap_hexdigits[] = "0123456789abcdef";
#endif

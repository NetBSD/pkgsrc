/*	$NetBSD: if_tap_stub.c,v 1.1.1.1 2005/01/20 18:02:40 cube Exp $	*/

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: if_tap_stub.c,v 1.1.1.1 2005/01/20 18:02:40 cube Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/proc.h>
#include <sys/file.h>
#include <sys/filedesc.h>
#include <sys/stat.h>

#include "if_tap_stub.h"

/* 2.99.10 is gray area.  Oh, well. */
#if __NetBSD_Version__ < 299001100
int
tap_fdclone(struct proc *p, struct file *fp, int fd, struct fileops *fops,
    void *data)
{
	fp->f_flag = FREAD | FWRITE;
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

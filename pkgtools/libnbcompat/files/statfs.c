/*	$NetBSD: statfs.c,v 1.1 2003/09/01 15:31:21 jlam Exp $	*/
/*-
 * Copyright (c) 1998 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if HAVE_CONFIG_H
#include "nbconfig.h"
#endif

#if HAVE_STRING_H
#include <string.h>
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#if HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif

#if HAVE_SYS_STATVFS_H
#include <sys/statvfs.h>
#endif

#define	MFSNAMELEN	16	/* length of fs type name, including nul */
#define	MNAMELEN	90	/* length of buffer for returned name */

struct statfs {
	short	f_type;			/* type of file system */
	u_short	f_flags;		/* copy of mount flags */
	long	f_bsize;		/* fundamental file system block size */
	long	f_iosize;		/* optimal transfer block size */
	long	f_blocks;		/* total data blocks in file system */
	long	f_bfree;		/* free blocks in fs */
	long	f_bavail;		/* free blocks avail to non-superuser */
	long	f_files;		/* total file nodes in file system */
	long	f_ffree;		/* free file nodes in fs */
	fsid_t	f_fsid;			/* file system id */
	uid_t	f_owner;		/* user that mounted the file system */
	long	f_spare[4];		/* spare for later */
	char	f_fstypename[MFSNAMELEN]; /* fs type name */
	char	f_mntonname[MNAMELEN];	  /* directory on which mounted */
	char	f_mntfromname[MNAMELEN];  /* mounted file system */
};

#ifndef MNT_RDONLY
#define MNT_RDONLY      0x00000001      /* read only filesystem */
#endif

#ifndef MNT_NOSUID
#define MNT_NOSUID      0x00000008      /* don't honor setuid bits on fs */
#endif

static void vfs2fs(struct statfs *, const struct statvfs *);

static void
vfs2fs(struct statfs *sfs, const struct statvfs *vfs)
{
	sfs->f_type = 0;		/* ok */
	sfs->f_flags = 0;
	if (vfs->f_flag & ST_RDONLY)	
		sfs->f_flags |= MNT_RDONLY;
	if (vfs->f_flag & ST_NOSUID)	
		sfs->f_flags |= MNT_NOSUID;

	/*
	 * From a quick survey of f_bsize, f_iosize, and f_frsize on
	 * various NetBSD and Solaris systems, with varying fragment and
	 * block sizes:
	 *
	 *                   f_bsize         f_iosize        f_frsize
	 * netbsd   1k/8k      1024             8192
	 * netbsd   2k/16k     2048            16384
	 * solaris  1k/8k      8192                             1024
	 * solaris  2k/8k      8192                             2048
	 * solaris 512/4k      4096                              512
	 * 
	 * It is apparent that:
	 * 
	 *  - netbsd's f_bsize is equivalent to the fragment size of the
	 *    underlying filesystem
	 *  - netbsd's f_iosize is equivalent to the block size of the
	 *    underlying filesystem
	 *  - solaris's f_bsize is equivalent to the block size of the
	 *    underlying filesystem
	 *  - solaris's f_frsize is equivalent to the fragment size of the
	 *    underlying filesystem
	 *
	 * NetBSD's statfs(2) man page (and sys/mount.h header file) says:
	 *
	 *    long    f_bsize;    /* fundamental file system block size * /
	 *    long    f_iosize;   /* optimal transfer block size * /
	 *
	 * and Solaris's statvfs(2) man page says:
	 *
	 *    u_long  f_bsize;    /* preferred file system block size * /
	 *    u_long  f_frsize;   /* fundamental filesystem block
	 *                           (size if supported) * /
	 *
	 * so it makes sense that their f_frsize == our f_bsize.
	 *
	 * I see that Solaris's sys/statvfs.h says:
	 *
	 *   unsigned long  f_bsize;  /* fundamental file system block size * /
	 *   unsigned long  f_frsize; /* fragment size * /
	 *
	 * but empiric testing (above) seems to indicate that the comments
	 * in their code are wrong.  The following two assignments, even
	 * though they may look wrong, are actually correct.
	 */
	sfs->f_bsize = vfs->f_frsize;
	sfs->f_iosize = vfs->f_bsize;
	sfs->f_blocks = vfs->f_blocks;
	sfs->f_bfree = vfs->f_bfree;
	sfs->f_bavail = vfs->f_bavail;
	sfs->f_files = vfs->f_files;
	sfs->f_ffree = vfs->f_ffree;
	(void) memcpy(&sfs->f_fsid.val[0], &vfs->f_fsid, sizeof(fsid_t));
	sfs->f_owner = 0;		/* XXX: root always here */
	(void)strncpy(sfs->f_fstypename,
	    vfs->f_basetype, sizeof(sfs->f_fstypename));
	sfs->f_mntonname[0] = '\0';	/* XXX: */
	sfs->f_mntfromname[0] = '\0';	/* XXX: */
}

int
statfs(path, sfs)
	const char *path;
	struct statfs *sfs;
{
	struct statvfs vfs;

	if (statvfs(path, &vfs) == -1)
		return -1;
	vfs2fs(sfs, &vfs);
	return 0;

}

int
fstatfs(fd, sfs)
	int fd;
	struct statfs *sfs;
{
	struct statvfs vfs;

	if (fstatvfs(fd, &vfs) == -1)
		return -1;

	vfs2fs(sfs, &vfs);
	return 0;
}

/*	$NetBSD: statfs.h,v 1.1 2003/09/03 13:35:53 jlam Exp $	*/

#ifndef _NBCOMPAT_STATFS_H
#define _NBCOMPAT_STATFS_H

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#if HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif

#if HAVE_SYS_STATVFS_H
#include <sys/statvfs.h>
#endif

#if HAVE_SYS_VFS_H
#include <sys/vfs.h>
#endif

#ifndef MFSNAMELEN
#define	MFSNAMELEN	16	/* length of fs type name, including nul */
#endif
#ifndef MNAMELEN
#define	MNAMELEN	90	/* length of buffer for returned name */
#endif

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

int	statfs(const char *path, struct statfs *sfs);
int	fstatfs(int fd, struct statfs *sfs);

#endif /* !_NBCOMPAT_STATFS_H */

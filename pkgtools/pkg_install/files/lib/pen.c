/*	$NetBSD: pen.c,v 1.1.1.1 2002/12/20 18:14:03 schmonz Exp $	*/

#if 0
#include <sys/cdefs.h>
#ifndef lint
#if 0
static const char *rcsid = "from FreeBSD Id: pen.c,v 1.25 1997/10/08 07:48:12 charnier Exp";
#else
__RCSID("$NetBSD: pen.c,v 1.1.1.1 2002/12/20 18:14:03 schmonz Exp $");
#endif
#endif
#endif

/*
 * FreeBSD install - a package for the installation and maintainance
 * of non-core utilities.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * Jordan K. Hubbard
 * 18 July 1993
 *
 * Routines for managing the "play pen".
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ERR_H
#include <err.h>
#endif

#include "lib.h"

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif

#ifdef HAVE_SYS_VFS_H
#include <sys/vfs.h>
#endif

/* For keeping track of where we are */
static char Current[FILENAME_MAX];
static char Previous[FILENAME_MAX];
static int CurrentSet;		/* rm -rf Current only if it's really set! */
                                /* CurrentSet is set to 0 before strcpy()s
				 * to prevent rm'ing of a partial string
				 * when interrupted by ^C */

#if 0
/*
 * Backup Current and Previous into temp. strings that are later
 * restored & freed by restore_dirs
 * This is to make nested calls to make_playpen/leave_playpen work
 */
void
save_dirs(char **c, char **p)
{
	*c = strdup(Current);	/* XXX */
	*p = strdup(Previous);
}

/*
 * Restore Current and Previous from temp strings that were created
 * by safe_dirs.
 * This is to make nested calls to make_playpen/leave_playpen work
 */
void
restore_dirs(char *c, char *p)
{
	CurrentSet = 0;		/* prevent from deleting */
	strcpy(Current, c);
	CurrentSet = 1;		/* rm -fr Current is safe now */
	free(c);
	
	strcpy(Previous, p);
	free(p);
}
#endif

char   *
where_playpen(void)
{
	return Current;
}

/*
 * Find a good place to play.
 */
static char *
find_play_pen(char *pen, size_t pensize, size_t sz)
{
	char   *cp;
	struct stat sb;

	if (pen && pen[0] && stat(pen, &sb) != FAIL && (min_free(pen) >= sz))
		return pen;
	else if ((cp = getenv("PKG_TMPDIR")) != NULL && stat(cp, &sb) != FAIL && (min_free(cp) >= sz))
		(void) snprintf(pen, pensize, "%s/instmp.XXXXXX", cp);
	else if ((cp = getenv("TMPDIR")) != NULL && stat(cp, &sb) != FAIL && (min_free(cp) >= sz))
		(void) snprintf(pen, pensize, "%s/instmp.XXXXXX", cp);
	else if (stat("/var/tmp", &sb) != FAIL && min_free("/var/tmp") >= sz)
		strcpy(pen, "/var/tmp/instmp.XXXXXX");
	else if (stat("/tmp", &sb) != FAIL && min_free("/tmp") >= sz)
		strcpy(pen, "/tmp/instmp.XXXXXX");
	else if (stat("/usr/tmp", &sb) != FAIL && min_free("/usr/tmp") >= sz)
		strcpy(pen, "/usr/tmp/instmp.XXXXXX");
	else {
		cleanup(0);
		errx(2,
		    "can't find enough temporary space to extract the files, please set your\n"
		    "PKG_TMPDIR environment variable to a location with at least %lu bytes\n"
		    "free", (u_long) sz);
		return NULL;
	}
	return pen;
}

#if !defined(HAVE_MKDTEMP)
static char *
mkdtemp(char *template)
{
	/* mkdtemp(3) is not present on 1.3.3 and below */
	if (!mktemp(template)) {
		cleanup(0);
		errx(2, "can't mktemp '%s'", template);
	}
	if (mkdir(template, 0700) < 0) {
		cleanup(0);
		errx(2, "can't mkdir '%s'", template);
	}
	return template;
}
#endif

/*
 * Make a temporary directory to play in and chdir() to it, returning
 * pathname of previous working directory.
 */
char   *
make_playpen(char *pen, size_t pensize, size_t sz)
{
	if (!find_play_pen(pen, pensize, sz))
		return NULL;

	if (!mkdtemp(pen)) {
		cleanup(0);
		errx(2, "can't mkdtemp '%s'", pen);
	}
	if (Verbose) {
		if (sz)
			fprintf(stderr,
		"Requested space: %lu bytes, free space: %lld bytes in %s\n",
			    (u_long) sz, (long long) min_free(pen), pen);
	}
	if (min_free(pen) < sz) {
		rmdir(pen);
		cleanup(0);
		errx(2, "not enough free space to create '%s'.\n"
		    "Please set your PKG_TMPDIR environment variable to a location\n"
		    "with more space and\ntry the command again", pen);
	}
	if (Current[0])
		strcpy(Previous, Current);
	else if (!getcwd(Previous, FILENAME_MAX)) {
		cleanup(0);
		err(1, "fatal error during execution: getcwd");
	}
	if (chdir(pen) == FAIL) {
		cleanup(0);
		errx(2, "can't chdir to '%s'", pen);
	}
	strcpy(Current, pen); CurrentSet = 1;
	
	return Previous;
}

/*
 * Convenience routine for getting out of playpen
 */
void
leave_playpen(char *save)
{
	void    (*oldsig) (int);

	/* Make us interruptable while we're cleaning up - just in case... */
	oldsig = signal(SIGINT, SIG_DFL);
	if (Previous[0] && chdir(Previous) == FAIL) {
		cleanup(0);
		errx(2, "can't chdir back to '%s'", Previous);
	} else if (CurrentSet && Current[0] && strcmp(Current, Previous)) {
		if (strcmp(Current, "/") == 0) {
			fprintf(stderr, "PANIC: About to rm -rf / (not doing so, aborting)\n");
			abort();
		}
		if (vsystem("%s -rf %s", RM, Current))
			warnx("couldn't remove temporary dir '%s'", Current);
		strcpy(Current, Previous);
	}
	if (save)
		strcpy(Previous, save);
	else
		Previous[0] = '\0';
	signal(SIGINT, oldsig);
}

/*
 * Solaris 2.7 and 2.8 have statfs(2), but it is deprecated, and has a
 * different interface to NetBSD's statfs.
 * We do this autoconf dance here to get around the old interface (it's
 * in libc on 2.7 and 2.8, but not in 2.9)
 */
#if !defined(HAVE_STATFS) || (defined(HAVE_STATFS) && defined(HAVE_STATVFS))
/*	$NetBSD: pen.c,v 1.1.1.1 2002/12/20 18:14:03 schmonz Exp $	*/

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

#include <string.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <sys/statvfs.h>

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
#endif

/*
 * Return free disk space (in bytes) on given file system
 */
off_t
min_free(char *tmpdir)
{
	struct statfs buf;

	if (statfs(tmpdir, &buf) != 0) {
		warn("statfs");
		return -1;
	}
	return (off_t) buf.f_bavail * (off_t) buf.f_bsize;
}

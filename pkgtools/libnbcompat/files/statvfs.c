/*	$NetBSD: statvfs.c,v 1.1 2004/08/06 16:55:09 jlam Exp $	*/

/*-
 * Copyright (c) 2004 The NetBSD Foundation, Inc.
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
#include "nbcompat/nbconfig.h"
#endif

#if HAVE_STRING_H
#include <string.h>	/* memcpy() */
#endif

#include "nbcompat/statvfs.h"

static void fs2vfs(struct statvfs *vfs, const struct statfs *sfs);

static void
fs2vfs(struct statvfs *vfs, const struct statfs *sfs)
{
	vfs->f_flag = 0;
	if (sfs->f_flags & MNT_RDONLY)	
		vfs->f_flag |= ST_RDONLY;
	if (sfs->f_flags & MNT_NOSUID)	
		vfs->f_flag |= ST_NOSUID;

#if HAVE_STRUCT_STATFS_F_FSIZE
	vfs->f_bsize = sfs->f_fsize
#else
	vfs->f_bsize = sfs->f_bsize;
#endif
	vfs->f_frsize = sfs->f_bsize;
#if HAVE_STRUCT_STATFS_F_IOSIZE
	vfs->f_iosize = sfs->f_iosize;
#else
	vfs->f_iosize = sfs->f_bsize;
#endif
	vfs->f_blocks = sfs->f_blocks;
	vfs->f_bfree = sfs->f_bfree;
	vfs->f_bavail = sfs->f_bavail;
	vfs->f_bresvd = 0;		/* XXX */

	vfs->f_files = sfs->f_files;
	vfs->f_ffree = sfs->f_ffree;
	/*
	 * f_favail is supposed to only be free nodes available to non-root
	 * but that info isn't available via statfs().  Just fudge it by
	 * assigning it f_ffree as well, which is the total free nodes.
	 */
	vfs->f_favail = sfs->f_ffree;
	vfs->f_fresvd = 0;		/* XXX */

	vfs->f_syncreads = 0;		/* XXX */
	vfs->f_syncwrites= 0;		/* XXX */
	vfs->f_asyncreads = 0;		/* XXX */
	vfs->f_asyncwrites= 0;		/* XXX */

	(void) memcpy(&vfs->f_fsidx, &sfs->f_fsid, sizeof(fsid_t));
	vfs->f_fsid = sfs->f_fsid.val[0];

#if HAVE_STRUCT_STATFS_F_IOSIZE
	vfs->f_namemax = sfs->f_name_max;
#else
	vfs->f_namemax = VFS_MNAMELEN;	/* XXX */
#endif
	vfs->f_owner = 0;		/* XXX */
	vfs->f_fstypename[0] = '\0';	/* XXX */
	vfs->f_mntonname[0] = '\0';	/* XXX */
	vfs->f_mntfromname[0] = '\0';	/* XXX */
}

int
statvfs(const char *path, struct statvfs *vfs)
{
	struct statfs sfs;

	if (statfs(path, &sfs) == -1)
		return -1;
	fs2vfs(vfs, &sfs);
	return 0;
}

int
fstatvfs(int fd, struct statvfs *vfs)
{
	struct statfs sfs;

	if (fstatfs(fd, &sfs) == -1)
		return -1;

	fs2vfs(vfs, &sfs);
	return 0;
}

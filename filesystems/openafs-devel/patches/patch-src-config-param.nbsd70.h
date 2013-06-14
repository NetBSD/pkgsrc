$NetBSD: patch-src-config-param.nbsd70.h,v 1.2 2013/06/14 20:49:41 dholland Exp $

--- src/config/param.nbsd70.h.orig	2012-04-28 19:35:22.000000000 -0400
+++ src/config/param.nbsd70.h	2012-04-28 19:35:13.000000000 -0400
@@ -0,0 +1,171 @@
+/* NetBSD shared section */
+
+#ifndef	AFS_PARAM_COMMON_H
+#define	AFS_PARAM_COMMON_H 1
+
+#define AFS_NAMEI_ENV  1	/* User space interface to file system */
+#define AFS_64BIT_IOPS_ENV 1	/* Needed for NAMEI */
+#define AFS_64BIT_CLIENT 1
+
+#define AFS_MOUNT_AFS "afs"	/* The name of the filesystem type. */
+#define AFS_SYSCALL 210
+
+#define AFS_KALLOC(n)           kmem_alloc(n, KM_SLEEP)
+#define AFS_KALLOC_NOSLEEP(n)   kmem_alloc(n, KM_NOSLEEP)
+#define AFS_KFREE               kmem_free
+#define VATTR_NULL              vattr_null
+
+#if 0
+/* including this file before sysincludes.h is canonical, but
+ * NBSD40's mount.h defines MOUNT_AFS */
+
+#ifndef	MOUNT_AFS
+#define	MOUNT_AFS AFS_MOUNT_AFS
+#endif
+
+#endif /* 0 */
+
+#define AFS_XBSD_ENV 1		/* {Free,Open,Net}BSD */
+
+#define AFS_NBSD_ENV 1
+#define AFS_NBSD15_ENV 1
+#define AFS_NBSD16_ENV 1
+#define AFS_NBSD20_ENV 1
+#define AFS_NBSD30_ENV 1
+#define AFS_NBSD40_ENV 1
+#define AFS_NBSD50_ENV 1
+#define AFS_NBSD60_ENV 1
+#define AFS_NBSD70_ENV 1
+#undef  AFS_NONFSTRANS
+#define AFS_NONFSTRANS 1
+
+#define AFS_VFSINCL_ENV 1
+
+#define AFS_HAVE_FFS            1	/* Use system's ffs. */
+
+#if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
+#define AFS_HAVE_STATVFS    1	/* System supports statvfs */
+#endif
+
+#ifndef UKERNEL
+
+#if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
+#include <sys/param.h>
+#endif
+
+#define FTRUNC O_TRUNC
+
+#define IUPD 0x0010
+#define IACC 0x0020
+#define ICHG 0x0040
+#define IMOD 0x0080
+
+#define RXK_LISTENER_ENV  1
+
+#include <afs/afs_sysnames.h>
+
+#define AFS_VM_RDWR_ENV	1
+#define AFS_VFS_ENV	1
+#define AFS_GREEDY43_ENV	1
+
+#define AFS_GCPAGS	        0	/* if nonzero, garbage collect PAGs */
+#define AFS_USE_GETTIMEOFDAY    1	/* use gettimeofday to implement rx clock */
+#define AFS_GLOBAL_SUNLOCK      1
+
+/* Extra kernel definitions (from kdefs file) */
+#ifdef _KERNEL_DEPRECATED
+#define	AFS_VFS34	1	/* What is VFS34??? */
+#define	AFS_SHORTGID	1	/* are group id's short? */
+#define	afsio_iov	uio_iov
+#define	afsio_iovcnt	uio_iovcnt
+#define	afsio_offset	uio_offset
+#define	afsio_seg	uio_segflg
+#define	afsio_resid	uio_resid
+#define	AFS_UIOSYS	UIO_SYSSPACE
+#define	AFS_UIOUSER	UIO_USERSPACE
+#define	AFS_CLBYTES	CLBYTES
+#define	osi_GetTime(x)	microtime(x)
+#define	AFS_KALLOC(x)	kalloc(x)
+#define	AFS_KFREE(x,y)	kfree(x,y)
+#define	v_count		v_usecount
+#define v_vfsp		v_mount
+#define vfs_bsize	mnt_stat.f_bsize
+#define vfs_fsid	mnt_stat.f_fsid
+#define va_nodeid	va_fileid
+#define vfs_vnodecovered mnt_vnodecovered
+#define direct		dirent
+
+#ifndef MUTEX_DEFAULT
+#define MUTEX_DEFAULT   0
+#endif /* MUTEX_DEFAULT */
+
+#ifndef SSYS
+#define SSYS            0x00002
+#endif /* SSYS */
+
+#define p_rcred         p_ucred
+
+#define	VN_RELE(vp)	vrele(((struct vnode *)(vp)))
+#define	VN_HOLD(vp)	VREF(((struct vnode *)(vp)))
+
+#if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
+enum vcexcl { NONEXCL, EXCL };
+
+#ifdef KERNEL
+#ifndef MIN
+#define MIN(A,B) ((A) < (B) ? (A) : (B))
+#endif
+#ifndef MAX
+#define MAX(A,B) ((A) > (B) ? (A) : (B))
+#endif
+#endif /* KERNEL */
+
+#endif /* ! ASSEMBLER & ! __LANGUAGE_ASSEMBLY__ && !defined(IGNORE_STDS_H) */
+#endif /* _KERNEL_DEPRECATED */
+
+#else /* !defined(UKERNEL) */
+
+
+/* This section for user space compiles only */
+
+#define UKERNEL			1	/* user space kernel */
+
+#include <afs/afs_sysnames.h>
+
+#define AFS_USERSPACE_IP_ADDR 1
+#define RXK_LISTENER_ENV      1
+#define AFS_GCPAGS	      0	/* if nonzero, garbage collect PAGs */
+
+#define	afsio_iov	uio_iov
+#define	afsio_iovcnt	uio_iovcnt
+#define	afsio_offset	uio_offset
+#define	afsio_seg	uio_segflg
+#define	afsio_fmode	uio_fmode
+#define	afsio_resid	uio_resid
+#define	AFS_UIOSYS	UIO_SYSSPACE
+#define	AFS_UIOUSER	UIO_USERSPACE
+#define	AFS_CLBYTES	MCLBYTES
+#define	AFS_MINCHANGE	2
+#define	VATTR_NULL	usr_vattr_null
+
+#define AFS_DIRENT
+#ifndef CMSERVERPREF
+#define CMSERVERPREF
+#endif
+
+#if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H) && !defined()
+#include <limits.h>
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/mount.h>
+#include <sys/fcntl.h>
+#include <netinet/in.h>
+#include <sys/uio.h>
+#include <sys/socket.h>
+#endif
+
+#define ROOTINO	UFS_ROOTINO
+
+#endif /* !defined(UKERNEL) */
+
+#endif /* AFS_PARAM_COMMON_H */

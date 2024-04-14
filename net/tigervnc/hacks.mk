# $NetBSD: hacks.mk,v 1.2 2024/04/14 09:14:03 pho Exp $

.if !defined(TIGERVNC_HACKS_MK)
TIGERVNC_HACKS_MK=	defined

### [Tue Apr  9 13:40:46 JST 2024 : pho]
###
### With "smart scheduler" enabled, Xserver sets up an itimer to
### periodically receive SIGALRM from the kernel while the server is doing
### a socket I/O and processing commands from X clients. When the signal
### arrives while Xserver is in pixman_composite_src_8888_8888_asm_neon()
### or any similar functions from libpixman, the process fails to return
### from the signal handler and exits with status code 22 (EINVAL) due to
### kern/58149. These functions misalign SP while doing some SIMD stuff,
### thereby trigger the kernel bug.
###
### Disabling itimer can avoid the problem but there might be a performance
### regression.
###
.if ${MACHINE_PLATFORM:MNetBSD-9.*-aarch64} || \
	${MACHINE_PLATFORM:MNetBSD-10.0-aarch64}
PKG_HACKS+=	smart-scheduler-workaround
CONFIGURE_ENV+=	ac_cv_func_setitimer=no
.endif

.endif  # TIGERVNC_HACKS_MK

# $NetBSD: arch.mk,v 1.1 2024/05/07 21:48:54 nia Exp $

.if !defined(QUAKE_ARCH)

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH:M*arm*}
QUAKE_ARCH=	arm
.elif ${MACHINE_ARCH:M*mips*}
QUAKE_ARCH=	mips
.elif ${MACHINE_ARCH:M*sh3*}
QUAKE_ARCH=	sh
.elif ${MACHINE_ARCH} == "powerpc"
QUAKE_ARCH=	ppc
.elif ${MACHINE_ARCH} == "powerpc64"
QUAKE_ARCH=	ppc64
.elif ${MACHINE_ARCH} == "sparc64"
QUAKE_ARCH=	sparc
.else
QUAKE_ARCH=	${MACHINE_ARCH}
.endif

.endif

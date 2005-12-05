# $NetBSD: arch.mk,v 1.2 2005/12/05 20:50:12 rillig Exp $

.if !defined(SUSE_ARCH_MK)
SUSE_ARCH_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "powerpc"
SUSE_ARCH?=	ppc
.else
SUSE_ARCH?=	${MACHINE_ARCH}
.endif

.endif # SUSE_ARCH_MK

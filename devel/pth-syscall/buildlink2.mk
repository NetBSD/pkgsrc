# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 18:44:57 jlam Exp $

.if !defined(PTH_SYSCALL_BUILDLINK2_MK)
PTH_SYSCALL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pth-syscall
BUILDLINK_DEPENDS.pth-syscall?=		pth-syscall>=1.4.1
BUILDLINK_PKGSRCDIR.pth-syscall?=	../../devel/pth-syscall

EVAL_PREFIX+=	BUILDLINK_PREFIX.pth-syscall=pth-syscall
BUILDLINK_PREFIX.pth-syscall_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pth-syscall=	include/pth.h
BUILDLINK_FILES.pth-syscall+=	include/pthread.h
BUILDLINK_FILES.pth-syscall+=	lib/libpth.*
BUILDLINK_FILES.pth-syscall+=	lib/libpthread.*

BUILDLINK_TARGETS+=	pth-syscall-buildlink

pth-syscall-buildlink: _BUILDLINK_USE

.endif	# PTH_SYSCALL_BUILDLINK2_MK

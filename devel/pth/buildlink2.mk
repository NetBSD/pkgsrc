# $NetBSD: buildlink2.mk,v 1.1.2.4 2002/08/22 21:04:24 jlam Exp $

.if !defined(PTH_BUILDLINK2_MK)
PTH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pth
BUILDLINK_DEPENDS.pth?=		pth>=1.4.0
BUILDLINK_PKGSRCDIR.pth?=	../../devel/pth

EVAL_PREFIX+=	BUILDLINK_PREFIX.pth=pth
BUILDLINK_PREFIX.pth_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pth=	include/pth.h
BUILDLINK_FILES.pth+=	include/pthread.h
BUILDLINK_FILES.pth+=	lib/libpth.*
BUILDLINK_FILES.pth+=	lib/libpthread.*

BUILDLINK_TARGETS+=	pth-buildlink

pth-buildlink: _BUILDLINK_USE

.endif	# PTH_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:38 jlam Exp $

.if !defined(PTL2_BUILDLINK2_MK)
PTL2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ptl2
BUILDLINK_DEPENDS.ptl2?=	ptl>=2.1.7
BUILDLINK_PKGSRCDIR.ptl2?=	../../devel/ptl2

EVAL_PREFIX+=			BUILDLINK_PREFIX.ptl2=ptl
BUILDLINK_PREFIX.ptl2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ptl2=		PTL/include/*/*/*.h
BUILDLINK_FILES.ptl2+=		PTL/include/*/*.h
BUILDLINK_FILES.ptl2+=		PTL/include/*.h
BUILDLINK_FILES.ptl2+=		lib/libPTL.*

BUILDLINK_TARGETS+=	ptl2-buildlink

ptl2-buildlink: _BUILDLINK_USE

.endif	# PTL2_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.4 2003/12/04 11:26:42 adam Exp $

.if !defined(LAPACK_BUILDLINK2_MK)
LAPACK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lapack
BUILDLINK_DEPENDS.lapack?=	lapack>=20010201nb1
BUILDLINK_PKGSRCDIR.lapack?=	../../math/lapack

EVAL_PREFIX+=			BUILDLINK_PREFIX.lapack=lapack
BUILDLINK_PREFIX.lapack_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lapack=		lib/liblapack.*

BUILDLINK_TARGETS+=		lapack-buildlink

lapack-buildlink: _BUILDLINK_USE

.endif	# LAPACK_BUILDLINK2_MK

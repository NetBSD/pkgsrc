# $NetBSD: buildlink2.mk,v 1.1 2003/12/04 15:10:48 adam Exp $

.if !defined(SLATEC_BUILDLINK2_MK)
SLATEC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		slatec
BUILDLINK_DEPENDS.slatec?=	slatec>=4.1nb1
BUILDLINK_PKGSRCDIR.slatec?=	../../math/slatec

EVAL_PREFIX+=			BUILDLINK_PREFIX.slatec=slatec
BUILDLINK_PREFIX.slatec_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.slatec=		lib/libslatec*

BUILDLINK_TARGETS+=		slatec-buildlink

slatec-buildlink: _BUILDLINK_USE

.endif	# SLATEC_BUILDLINK2_MK

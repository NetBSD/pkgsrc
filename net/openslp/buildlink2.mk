# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:36 jlam Exp $

.if !defined(OPENSLP_BUILDLINK2_MK)
OPENSLP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		openslp
BUILDLINK_DEPENDS.openslp?=	openslp>=1.0.1
BUILDLINK_PKGSRCDIR.openslp?=	../../net/openslp

EVAL_PREFIX+=	BUILDLINK_PREFIX.openslp=openslp
BUILDLINK_PREFIX.openslp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openslp=	include/slp.h
BUILDLINK_FILES.openslp+=	lib/libslp.*

BUILDLINK_TARGETS+=	openslp-buildlink

openslp-buildlink: _BUILDLINK_USE

.endif	# OPENSLP_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:25 jlam Exp $

.if !defined(GLE_BUILDLINK2_MK)
GLE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gle
BUILDLINK_DEPENDS.gle?=		gle>=3.0.3
BUILDLINK_PKGSRCDIR.gle?=	../../graphics/gle

EVAL_PREFIX+=			BUILDLINK_PREFIX.gle=gle
BUILDLINK_PREFIX.gle_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gle=		include/GL/gle.h
BUILDLINK_FILES.gle+=		lib/libgle.*

.include "../../graphics/Mesa/buildlink2.mk"

BUILDLINK_TARGETS+=	gle-buildlink

gle-buildlink: _BUILDLINK_USE

.endif	# GLE_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.1 2002/09/21 12:03:28 jlam Exp $

.if !defined(COMPFACE_BUILDLINK2_MK)
COMPFACE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		compface
BUILDLINK_DEPENDS.compface?=	compface>=1.4
BUILDLINK_PKGSRCDIR.compface?=	../../graphics/compface

EVAL_PREFIX+=		BUILDLINK_PREFIX.compface=compface
BUILDLINK_PREFIX.compface_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.compface+=	include/compface.h
BUILDLINK_FILES.compface+=	lib/libcompface.*

BUILDLINK_TARGETS+=	compface-buildlink

compface-buildlink: _BUILDLINK_USE

.endif	# COMPFACE_BUILDLINK2_MK

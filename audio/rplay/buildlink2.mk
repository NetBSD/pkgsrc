# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:21:56 jlam Exp $

.if !defined(RPLAY_BUILDLINK2_MK)
RPLAY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		rplay
BUILDLINK_DEPENDS.rplay?=	rplay>=3.3.2
BUILDLINK_PKGSRCDIR.rplay?=	../../audio/rplay

EVAL_PREFIX+=		BUILDLINK_PREFIX.rplay=rplay
BUILDLINK_PREFIX.rplay_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rplay=	include/rplay.h
BUILDLINK_FILES.rplay+=	lib/librplay.*

BUILDLINK_TARGETS+=	rplay-buildlink

rplay-buildlink: _BUILDLINK_USE

.endif	# RPLAY_BUILDLINK2_MK

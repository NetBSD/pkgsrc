# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:53:43 wiz Exp $

.if !defined(LAME_BUILDLINK2_MK)
LAME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lame
BUILDLINK_DEPENDS.lame?=	lame>=3.93.1nb1
BUILDLINK_PKGSRCDIR.lame?=	../../audio/lame

EVAL_PREFIX+=			BUILDLINK_PREFIX.lame=lame
BUILDLINK_PREFIX.lame_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lame=		include/lame/lame.h
BUILDLINK_FILES.lame+=		lib/libmp3lame.*

BUILDLINK_TARGETS+=	lame-buildlink

lame-buildlink: _BUILDLINK_USE

.endif	# LAME_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:27 jlam Exp $

.if !defined(MPEG_BUILDLINK2_MK)
MPEG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		mpeg
BUILDLINK_DEPENDS.mpeg?=	mpeg>=1.3.1
BUILDLINK_PKGSRCDIR.mpeg?=	../../graphics/mpeg-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.mpeg=mpeg
BUILDLINK_PREFIX.mpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mpeg=		include/mpeg.h
BUILDLINK_FILES.mpeg+=		lib/libmpeg_lib.*

BUILDLINK_TARGETS+=		mpeg-buildlink

mpeg-buildlink: _BUILDLINK_USE

.endif	# MPEG_BUILDLINK2_MK

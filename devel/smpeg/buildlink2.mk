# $NetBSD: buildlink2.mk,v 1.6 2003/07/26 21:41:13 jmmv Exp $

.if !defined(SMPEG_BUILDLINK2_MK)
SMPEG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		smpeg
BUILDLINK_DEPENDS.smpeg?=	smpeg>=0.4.4nb3
BUILDLINK_PKGSRCDIR.smpeg?=	../../devel/smpeg

EVAL_PREFIX+=			BUILDLINK_PREFIX.smpeg=smpeg
BUILDLINK_PREFIX.smpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.smpeg=		include/smpeg/*
BUILDLINK_FILES.smpeg+=		lib/libsmpeg-*
BUILDLINK_FILES.smpeg+=		lib/libsmpeg.*

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	smpeg-buildlink

smpeg-buildlink: _BUILDLINK_USE

.endif	# SMPEG_BUILDLINK2_MK

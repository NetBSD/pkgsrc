# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:54:42 wiz Exp $

.if !defined(SMPEG_BUILDLINK2_MK)
SMPEG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		smpeg
BUILDLINK_DEPENDS.smpeg?=	smpeg>=0.4.4nb1
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

# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:03:58 jlam Exp $

.if !defined(WSOUND_BUILDLINK2_MK)
WSOUND_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wsound
BUILDLINK_DEPENDS.wsound?=	wsoundserver>=0.4.0
BUILDLINK_PKGSRCDIR.wsound?=	wsoundserver

EVAL_PREFIX+=			BUILDLINK_PREFIX.wsound=wsoundserver
BUILDLINK_FILES.wsound=		include/wsound.h
BUILDLINK_FILES.wsound+=	lib/libwsound.*

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/libproplist/buildlink2.mk"

BUILDLINK_TARGETS+=	wsound-buildlink

wsound-buildlink: _BUILDLINK_USE

.endif	# WSOUND_BUILDLINK2_MK

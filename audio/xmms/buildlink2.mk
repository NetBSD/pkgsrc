# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:03:58 jlam Exp $

.if !defined(XMMS_BUILDLINK2_MK)
XMMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xmms
BUILDLINK_DEPENDS.xmms?=	xmms>=1.2.5
BUILDLINK_PKGSRCDIR.xmms?=	../../audio/xmms

EVAL_PREFIX+=		BUILDLINK_PREFIX.xmms=xmms
BUILDLINK_PREFIX.xmms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xmms=	include/xmms/*
BUILDLINK_FILES.xmms+=	lib/libxmms.*

.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	xmms-buildlink

xmms-buildlink: _BUILDLINK_USE

.endif	# XMMS_BUILDLINK2_MK

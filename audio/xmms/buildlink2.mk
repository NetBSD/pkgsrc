# $NetBSD: buildlink2.mk,v 1.5 2003/05/02 11:53:48 wiz Exp $

.if !defined(XMMS_BUILDLINK2_MK)
XMMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xmms
BUILDLINK_DEPENDS.xmms?=	xmms>=1.2.7nb6
BUILDLINK_PKGSRCDIR.xmms?=	../../audio/xmms

EVAL_PREFIX+=		BUILDLINK_PREFIX.xmms=xmms
BUILDLINK_PREFIX.xmms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xmms=	include/xmms/*
BUILDLINK_FILES.xmms+=	lib/libxmms.*

PTHREAD_OPTS+=		require

.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	xmms-buildlink

xmms-buildlink: _BUILDLINK_USE

.endif	# XMMS_BUILDLINK2_MK

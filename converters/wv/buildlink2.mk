# $NetBSD: buildlink2.mk,v 1.4 2002/09/11 11:23:15 wiz Exp $

.if !defined(WV_BUILDLINK2_MK)
WV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wv
BUILDLINK_DEPENDS.wv?=		wv>=0.7.2
BUILDLINK_PKGSRCDIR.wv?=	../../converters/wv

EVAL_PREFIX+=			BUILDLINK_PREFIX.wv=wv
BUILDLINK_PREFIX.wv_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.wv=	include/wv.h
BUILDLINK_FILES.wv+=	lib/libwv.*

BUILDLINK_TARGETS+=	wv-buildlink

wv-buildlink: _BUILDLINK_USE

.endif	# WV_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:03 jlam Exp $

.if !defined(WV_BUILDLINK2_MK)
WV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wv
BUILDLINK_DEPENDS.wv?=		wv>=0.6.5
BUILDLINK_PKGSRCDIR.wv?=	../../converters/wv

EVAL_PREFIX+=			BUILDLINK_PREFIX.wv=wv
BUILDLINK_PREFIX.wv_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.wv=	include/wv.h
BUILDLINK_FILES.wv+=	lib/libwv.*

BUILDLINK_TARGETS+=	wv-buildlink

wv-buildlink: _BUILDLINK_USE

.endif	# WV_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:19 jlam Exp $

.if !defined(RX_BUILDLINK2_MK)
RX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		rx
BUILDLINK_DEPENDS.rx?=		rx>=1.5
BUILDLINK_PKGSRCDIR.rx?=	../../devel/rx

EVAL_PREFIX+=		BUILDLINK_PREFIX.rx=rx
BUILDLINK_PREFIX.rx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rx=	include/rxposix.h
BUILDLINK_FILES.rx+=	lib/librx.*

BUILDLINK_TARGETS+=	rx-buildlink

rx-buildlink: _BUILDLINK_USE

.endif	# RX_BUILDLINK2_MK

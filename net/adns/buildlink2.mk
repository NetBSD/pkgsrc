# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:11 jlam Exp $

.if !defined(ADNS_BUILDLINK2_MK)
ADNS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		adns
BUILDLINK_DEPENDS.adns?=	adns>=1.0
BUILDLINK_PKGSRCDIR.adns?=	../../net/adns

EVAL_PREFIX+=			BUILDLINK_PREFIX.adns=adns
BUILDLINK_PREFIX.adns_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.adns=		include/adns.h
BUILDLINK_FILES.adns+=		lib/libadns.*

BUILDLINK_TARGETS+=	adns-buildlink

adns-buildlink: _BUILDLINK_USE

.endif	# ADNS_BUILDLINK2_MK

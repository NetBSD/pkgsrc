# $NetBSD: buildlink2.mk,v 1.4 2003/08/09 13:07:41 recht Exp $
#

.if !defined(SPREAD_BUILDLINK2_MK)
SPREAD_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			spread
BUILDLINK_DEPENDS.spread?=		spread>=3.17.1
BUILDLINK_PKGSRCDIR.spread?=		../../net/spread

EVAL_PREFIX+=	BUILDLINK_PREFIX.spread=spread
BUILDLINK_PREFIX.spread_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.spread+=	include/spread/sp.h
BUILDLINK_FILES.spread+=	include/spread/sp_events.h
BUILDLINK_FILES.spread+=	include/spread/sp_func.h
BUILDLINK_FILES.spread+=	lib/libspread.*
BUILDLINK_FILES.spread+=	lib/libtspread.*

BUILDLINK_TARGETS+=	spread-buildlink

spread-buildlink: _BUILDLINK_USE

.endif	# SPREAD_BUILDLINK2_MK

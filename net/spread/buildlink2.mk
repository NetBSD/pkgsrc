# $NetBSD: buildlink2.mk,v 1.1 2003/02/22 23:37:14 mjl Exp $

.if !defined(SPREAD_BUILDLINK2_MK)
SPREAD_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		spread
BUILDLINK_DEPENDS.spread?=	spread>=3.17.0
BUILDLINK_PKGSRCDIR.spread?=	../../net/spread

EVAL_PREFIX+=			BUILDLINK_PREFIX.spread=spread
BUILDLINK_PREFIX.spread_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.spread+=	include/spread/sp.h
BUILDLINK_FILES.spread+=	include/spread/sp_events.h
BUILDLINK_FILES.spread+=	include/spread/sp_func.h
BUILDLINK_FILES.spread+=	lib/libspread.*
BUILDLINK_FILES.spread+=	lib/libtspread.*

BUILDLINK_TARGETS+=		spread-buildlink

spread-buildlink: _BUILDLINK_USE

.endif # SPREAD_BUILDLINK2_MK


# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:08 jlam Exp $

.if !defined(UDUNITS_BUILDLINK2_MK)
UDUNITS_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		udunits
BUILDLINK_DEPENDS.udunits?=	udunits>=1.11.7
BUILDLINK_PKGSRCDIR.udunits?=	../../math/udunits

EVAL_PREFIX+=			BUILDLINK_PREFIX.udunits=udunits
BUILDLINK_PREFIX.udunits_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.udunits=	lib/libudunits.*
BUILDLINK_FILES.udunits+=	lib/libudport.*
BUILDLINK_FILES.udunits+=	include/udunits.h
BUILDLINK_FILES.udunits+=	include/udunits.inc

BUILDLINK_TARGETS+=	udunits-buildlink

udunits-buildlink: _BUILDLINK_USE

.endif	# UDUNITS_BUILDLINK2_MK

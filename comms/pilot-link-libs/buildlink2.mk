# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:00 jlam Exp $

.if !defined(PILOT_LINK_LIBS_BUILDLINK2_MK)
PILOT_LINK_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pilot-link-libs
BUILDLINK_DEPENDS.pilot-link-libs?=	pilot-link-libs>=0.9.5
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.pilot-link-libs=pilot-link-libs
BUILDLINK_PREFIX.pilot-link-libs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pilot-link-libs=	include/pi-*.*
BUILDLINK_FILES.pilot-link-libs+=	lib/libpicc.*
BUILDLINK_FILES.pilot-link-libs+=	lib/libpisock.*

.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	pilot-link-libs-buildlink

pilot-link-libs-buildlink: _BUILDLINK_USE

.endif	# PILOT_LINK_LIBS_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.6 2003/12/08 21:48:09 reed Exp $

.if !defined(PILOT_LINK_LIBS_BUILDLINK2_MK)
PILOT_LINK_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pilot-link-libs
BUILDLINK_DEPENDS.pilot-link-libs?=	pilot-link-libs>=0.11.7nb1
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.pilot-link-libs=pilot-link-libs
BUILDLINK_PREFIX.pilot-link-libs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pilot-link-libs=	include/pi-*.*
BUILDLINK_FILES.pilot-link-libs+=       lib/libpisock++.*
BUILDLINK_FILES.pilot-link-libs+=       lib/libpisock.*
BUILDLINK_FILES.pilot-link-libs+=       lib/libpisync.*

.include "../../devel/ncurses/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	pilot-link-libs-buildlink

pilot-link-libs-buildlink: _BUILDLINK_USE

.endif	# PILOT_LINK_LIBS_BUILDLINK2_MK

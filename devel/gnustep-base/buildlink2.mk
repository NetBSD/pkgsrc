# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/27 10:58:44 rh Exp $
#
# This Makefile fragment is included by packages that use gnustep-base.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GNUSTEP_BASE_BUILDLINK2_MK)
GNUSTEP_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-base
BUILDLINK_DEPENDS.gnustep-base?=	gnustep-base>=1.5.0
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-base=gnustep-base
BUILDLINK_PREFIX.gnustep-base_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-base=	share/GNUstep/System/Headers/Foundation/*
BUILDLINK_FILES.gnustep-base+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libgnustep-base.*

.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/ffcall/buildlink2.mk"
.include "../../devel/gnustep-objc/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-base-buildlink

gnustep-base-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_BASE_BUILDLINK2_MK

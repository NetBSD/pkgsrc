# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/27 10:44:47 rh Exp $
#

.if !defined(GNUSTEP_OBJC_BUILDLINK2_MK)
GNUSTEP_OBJC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-objc
BUILDLINK_DEPENDS.gnustep-objc?=		gnustep-objc>=1.2.2
BUILDLINK_PKGSRCDIR.gnustep-objc?=		../../devel/gnustep-objc

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-objc=gnustep-objc
BUILDLINK_PREFIX.gnustep-objc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-objc=	share/GNUstep/System/Headers/objc/*
BUILDLINK_FILES.gnustep-objc+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/*

.include "../../devel/gnustep-make/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-objc-buildlink

gnustep-objc-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_OBJC_BUILDLINK2_MK

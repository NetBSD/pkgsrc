# $NetBSD: buildlink2.mk,v 1.5 2003/12/05 09:22:26 adam Exp $
#

.if !defined(GNUSTEP_OBJC_BUILDLINK2_MK)
GNUSTEP_OBJC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-objc
BUILDLINK_DEPENDS.gnustep-objc?=	gnustep-objc>=1.3.0
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-objc=gnustep-objc
BUILDLINK_PREFIX.gnustep-objc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-objc=	share/GNUstep/System/Library/Headers/objc/*
BUILDLINK_FILES.gnustep-objc+=	share/GNUstep/System/Library/Libraries/*

#.include "../../devel/gnustep-make/buildlink2.mk"
.include "../gnustep-make/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-objc-buildlink

gnustep-objc-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_OBJC_BUILDLINK2_MK

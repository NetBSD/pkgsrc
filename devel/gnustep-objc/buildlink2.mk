# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:54:29 wiz Exp $
#

.if !defined(GNUSTEP_OBJC_BUILDLINK2_MK)
GNUSTEP_OBJC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-objc
BUILDLINK_DEPENDS.gnustep-objc?=		gnustep-objc>=1.2.3nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=		../../devel/gnustep-objc

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-objc=gnustep-objc
BUILDLINK_PREFIX.gnustep-objc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnustep-objc=	share/GNUstep/System/Headers/objc/*
BUILDLINK_FILES.gnustep-objc+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/*

.include "../../devel/gnustep-make/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-objc-buildlink

gnustep-objc-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_OBJC_BUILDLINK2_MK

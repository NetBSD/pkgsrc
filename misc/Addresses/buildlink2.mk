# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/04/02 07:40:57 rh Exp $

.if !defined(ADDRESSES_BUILDLINK2_MK)
ADDRESSES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		Addresses
BUILDLINK_DEPENDS.Addresses?=	Addresses>=0.4.5
BUILDLINK_PKGSRCDIR.Addresses?=	../../misc/Addresses

EVAL_PREFIX+=	BUILDLINK_PREFIX.Addresses=Addresses
BUILDLINK_PREFIX.Addresses_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Addresses+=	share/GNUstep/Local/Library/Frameworks/AddressView.framework/Versions/A/Headers/*.h
BUILDLINK_FILES.Addresses+=	share/GNUstep/Local/Library/Frameworks/AddressView.framework/Versions/A/lib*.*
BUILDLINK_FILES.Addresses+=	share/GNUstep/Local/Library/Frameworks/Addresses.framework/Versions/A/Headers/*.h
BUILDLINK_FILES.Addresses+=	share/GNUstep/Local/Library/Frameworks/Addresses.framework/Versions/A/lib*.*

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	Addresses-buildlink

Addresses-buildlink: _BUILDLINK_USE

.endif	# ADDRESSES_BUILDLINK2_MK

# $NetBSD: buildlink3.mk,v 1.2 2004/04/10 23:57:23 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ADDRESSES_BUILDLINK3_MK:=	${ADDRESSES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Addresses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NAddresses}
BUILDLINK_PACKAGES+=	Addresses

.if !empty(ADDRESSES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Addresses+=	Addresses>=0.4.5
BUILDLINK_PKGSRCDIR.Addresses?=	../../misc/Addresses

.include "../../devel/gnustep-make/gnustep.mk"

_BL_Addresses_H1= Local/Library/Frameworks/AddressBook.framewok/Versions/A/Headers
_BL_Addresses_H2= Local/Library/Frameworks/AddressView.framewok/Versions/A/Headers
BUILDLINK_INCDIRS.Addresses+=	${GNUSTEP_ROOT}/${_BL_Addresses_H1}
BUILDLINK_INCDIRS.Addresses+=	${GNUSTEP_ROOT}/${_BL_Addresses_H2}
BUILDLINK_FILES.Addresses+=	${GNUSTEP_SUBDIR}/Local/Library/Headers/AddressBook/*.h
BUILDLINK_FILES.Addresses+=	${GNUSTEP_SUBDIR}/Local/Library/Headers/AddressView/*.h
BUILDLINK_FILES.Addresses+=	${GNUSTEP_SUBDIR}/Local/Library/Headers/Addresses/*.h

.endif	# ADDRESSES_BUILDLINK3_MK

.include "../../x11/gnustep-back/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

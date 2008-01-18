# $NetBSD: buildlink3.mk,v 1.11 2008/01/18 05:08:33 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ADDRESSES_BUILDLINK3_MK:=	${ADDRESSES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Addresses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NAddresses}
BUILDLINK_PACKAGES+=	Addresses
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Addresses

.if !empty(ADDRESSES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Addresses+=	Addresses>=0.4.5
BUILDLINK_ABI_DEPENDS.Addresses+=	Addresses>=0.4.6nb6
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

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

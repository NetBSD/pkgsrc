# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:00 joerg Exp $

BUILDLINK_TREE+=	Addresses

.if !defined(ADDRESSES_BUILDLINK3_MK)
ADDRESSES_BUILDLINK3_MK:=

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

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # ADDRESSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Addresses

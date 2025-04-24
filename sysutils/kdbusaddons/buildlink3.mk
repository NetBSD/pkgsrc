# $NetBSD: buildlink3.mk,v 1.36 2025/04/24 14:15:46 wiz Exp $

BUILDLINK_TREE+=	kdbusaddons

.if !defined(KDBUSADDONS_BUILDLINK3_MK)
KDBUSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdbusaddons+=	kdbusaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kdbusaddons?=	kdbusaddons>=5.116.0nb6
BUILDLINK_PKGSRCDIR.kdbusaddons?=	../../sysutils/kdbusaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KDBUSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdbusaddons

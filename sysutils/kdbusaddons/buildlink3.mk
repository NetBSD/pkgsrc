# $NetBSD: buildlink3.mk,v 1.7 2017/11/30 16:45:08 adam Exp $

BUILDLINK_TREE+=	kdbusaddons

.if !defined(KDBUSADDONS_BUILDLINK3_MK)
KDBUSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdbusaddons+=	kdbusaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kdbusaddons?=	kdbusaddons>=5.25.0nb10
BUILDLINK_PKGSRCDIR.kdbusaddons?=	../../sysutils/kdbusaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KDBUSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdbusaddons

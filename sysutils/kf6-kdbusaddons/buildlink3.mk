# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:54:23 markd Exp $

BUILDLINK_TREE+=	kf6-kdbusaddons

.if !defined(KF6_KDBUSADDONS_BUILDLINK3_MK)
KF6_KDBUSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kdbusaddons+=	kf6-kdbusaddons>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kdbusaddons?=	../../sysutils/kf6-kdbusaddons

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KDBUSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kdbusaddons

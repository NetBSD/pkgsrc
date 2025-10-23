# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:36:23 wiz Exp $

BUILDLINK_TREE+=	kf6-kcoreaddons

.if !defined(KF6_KCOREADDONS_BUILDLINK3_MK)
KF6_KCOREADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcoreaddons+=	kf6-kcoreaddons>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcoreaddons?=	kf6-kcoreaddons>=6.18.0nb1
BUILDLINK_PKGSRCDIR.kf6-kcoreaddons?=	../../devel/kf6-kcoreaddons

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCOREADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcoreaddons

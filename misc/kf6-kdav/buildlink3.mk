# $NetBSD: buildlink3.mk,v 1.8 2024/12/27 08:20:20 wiz Exp $

BUILDLINK_TREE+=	kf6-kdav

.if !defined(KF6_KDAV_BUILDLINK3_MK)
KF6_KDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kdav+=	kf6-kdav>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kdav?=		kf6-kdav>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-kdav?=		../../misc/kf6-kdav

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kdav

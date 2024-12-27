# $NetBSD: buildlink3.mk,v 1.8 2024/12/27 08:19:33 wiz Exp $

BUILDLINK_TREE+=	kf6-purpose

.if !defined(KF6_PURPOSE_BUILDLINK3_MK)
KF6_PURPOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-purpose+=	kf6-purpose>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-purpose?=	kf6-purpose>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-purpose?=	../../devel/kf6-purpose

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_PURPOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-purpose

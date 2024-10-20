# $NetBSD: buildlink3.mk,v 1.3 2024/10/20 14:03:35 wiz Exp $

BUILDLINK_TREE+=	kf6-purpose

.if !defined(KF6_PURPOSE_BUILDLINK3_MK)
KF6_PURPOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-purpose+=	kf6-purpose>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-purpose?=	kf6-purpose>=6.2.0nb3
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

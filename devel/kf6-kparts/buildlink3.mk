# $NetBSD: buildlink3.mk,v 1.8 2024/12/27 08:19:33 wiz Exp $

BUILDLINK_TREE+=	kf6-kparts

.if !defined(KF6_KPARTS_BUILDLINK3_MK)
KF6_KPARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kparts+=	kf6-kparts>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kparts?=	kf6-kparts>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-kparts?=	../../devel/kf6-kparts

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../x11/kf6-kjobwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KPARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kparts

# $NetBSD: buildlink3.mk,v 1.8 2024/12/27 08:19:32 wiz Exp $

BUILDLINK_TREE+=	kf6-kcmutils

.if !defined(KF6_KCMUTILS_BUILDLINK3_MK)
KF6_KCMUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcmutils+=	kf6-kcmutils>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcmutils?=	kf6-kcmutils>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-kcmutils?=	../../devel/kf6-kcmutils

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCMUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcmutils

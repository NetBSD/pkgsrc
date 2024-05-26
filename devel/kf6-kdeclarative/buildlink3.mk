# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:31:10 markd Exp $

BUILDLINK_TREE+=	kf6-kdeclarative

.if !defined(KF6_KDECLARATIVE_BUILDLINK3_MK)
KF6_KDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kdeclarative+=	kf6-kdeclarative>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kdeclarative?=		../../devel/kf6-kdeclarative

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kdeclarative

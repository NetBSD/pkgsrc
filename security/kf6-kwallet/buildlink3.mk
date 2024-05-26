# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:49:15 markd Exp $

BUILDLINK_TREE+=	kf6-kwallet

.if !defined(KF6_KWALLET_BUILDLINK3_MK)
KF6_KWALLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kwallet+=	kf6-kwallet>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kwallet?=	../../security/kf6-kwallet

.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KWALLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kwallet

# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:42:11 markd Exp $

BUILDLINK_TREE+=	kf6-kio

.if !defined(KF6_KIO_BUILDLINK3_MK)
KF6_KIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kio+=	kf6-kio>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kio?=	../../devel/kf6-kio

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kbookmarks/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kdoctools/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-kjobwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kio

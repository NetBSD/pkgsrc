# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:21:09 wiz Exp $

BUILDLINK_TREE+=	kf6-knewstuff

.if !defined(KF6_KNEWSTUFF_BUILDLINK3_MK)
KF6_KNEWSTUFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-knewstuff+=	kf6-knewstuff>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-knewstuff?=	kf6-knewstuff>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-knewstuff?=	../../net/kf6-knewstuff

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kpackage/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../misc/kf6-attica/buildlink3.mk"
.include "../../www/kf6-syndication/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KNEWSTUFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-knewstuff
